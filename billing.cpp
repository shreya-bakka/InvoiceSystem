#include<bits/stdc++.h> 
using namespace std;
 class shopping{

 private:
 	int pcode;
 	float price;
 	float dis;
 	string pname; //p stands for product

 public:
 	void menu();
 	void administrator();
 	void buyer();
 	void add();
 	void edit();
 	void rem();
 	void list();
 	void receipt();
 };

 void shopping :: menu(){
 	m:
 	int choice;
 	string email;
 	string password;

 	cout << "________________________________________________\n";
 	cout << "                                            \n";
 	cout << "           SUPER MARKET MAIN MENU           \n";
 	cout << "                                            \n";
 	cout << "________________________________________________\n";
 	cout << "                                            \n";
 	cout << "|                  |\n";
 	cout << "| 1) Administrator |\n";
 	cout << "|                  |\n";
 	cout << "| 2) Buyer         |\n";
 	cout << "|                  |\n";
 	cout << "| 3) Exit          |\n";
 	cout << "|                  |\n";
 	cout << " Please select!\n";
 	cin >> choice;

 	switch(choice){

 	case 1:
 		cout << " Please Login \n";
 		cout << " Enter Email \n";
 		cin >> email;
 		cout << " Password     \n";
 		cin >> password;

 		if(email == "shreya@email.com" && password =="shreya@20")  administrator();
 		else cout << "Invalid Email/Password\n";
 		break;

 	case 2:{

 		buyer();
 	}
 	case 3:{
 		exit(0);
 	}

 	default:{
 		cout << "Please select from the given options\n";
 	}

 	}
 goto m;

}


void shopping :: administrator(){
	m:
	int choice;
	cout << "\n\n\n Administrator menu";
	cout << "\n|__1) Add the product__|";
	cout << "\n|                            |";
	cout << "\n|__2) Modify the product_|";
	cout << "\n|                            |";
	cout << "\n|__3) Delete the product_|";
	cout << "\n|                            |";
	cout << "\n|__4) Back to main menu _|";
	
	cout << "\n\n Please enter your choice\n";
	cin >> choice;
	switch(choice){
	
	case 1:
		add();
		break;

	case 2:
		edit();
		break;

	case 3:
		rem();
		break;

	case 4:
		menu();
		break;

	default:
		cout << "Invalid choice!\n";

	}
goto m;
}

void shopping :: buyer(){
	m:
	int choice;
	cout << " 1) Buy Product \n";
	cout << "                \n";
	cout << " 2) Go Back \n";
	cout << "                \n"; 
	cout << " Enter your choice : \n";
	cin >> choice;

	switch(choice){
	case 1:
		receipt();
		break;

	case 2:
		menu();
		break;

	default:
		cout << "Invalid choice\n";

	}

goto m;

}

void shopping :: add(){
	m:
	fstream data;
	int c;
	int token = 0;
	float p; // price 
	float d; // discount
	string n;

	cout << "\n\n Add new product";
	cout << "\n\n Product code of the product ";
	cin >> pcode;
	cout << " Name of the product ";
	cin >> pname;
	cout << "\n\n Price of the product";
	cin >> price;
	cout << "\n\n Discount on product ";
	cin >> dis;

	data.open("database.txt",ios::in);

	if(!data){
		data.open("database.txt",ios::app|ios::out);
		data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
		data.close();
	}

	else{
		data >> c >> n >> p >> d;

		while(!data.eof()){
			if(c == pcode) token++;

			data >> c >> n >> p >> d;
		}

		data.close();

	}

	if(token == 1) goto m;
	else{
		data.open("database.txt",ios::app|ios::out);
		data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
		data.close();
	}
	cout << "\n\n Record inserted! ";

}

void shopping :: edit(){
	fstream data, data1;
	int pkey;
	int token = 0;
	int c;
	float p;
	float d;
	string n;

	cout << "\n Modify the record";
	cout << "\n Product code :";
	cin >> pkey;

	data.open("database.txt", ios::in);
	if(!data) cout << "\n\n File does'nt exist! ";
	else{
		data1.open("database1.txt", ios::app|ios::out);

		data >> pcode >> pname >> price >> dis;

		while(!data.eof()){
			if(pkey == pcode){

				cout << "\n Product new code :";
				cin >> c;
				cout << "\n Name of the product :";
				cin >> n;
				cout << "\n Price :";
				cin >> p;
				cout << "\n Discount :";
				cin >> d;
				data1 << " " << c << " " << n << " " << p << " " << d <<"\n";
				cout << "\n\n Record edited ";
			}	

			else{

				data1 << " " << pcode << " " << pname << " " << price << " " << dis << " \n";
			}
			data >> pcode >> pname >> price >> dis;
		}
		data.close();
		data1.close();

		remove("database.txt");
		rename("database1.txt", "database.txt");

		if(token == 0){
			cout << "\n\n Record not found sorry!";
		}
	}

}
void shopping :: rem(){

	fstream data, data1;
	int pkey;
	int token = 0;
	cout << " \n\n Delete product";
	cout << "\n\n Product code :";
	cin >> pkey;
	data.open("database.txt", ios::in);

	if(!data){
		cout << "File does'nt exist";
	}
	else{
		data.open("database1.txt", ios::app|ios::out);
		data >> pcode >> pname >> price >> dis;

		while(!data.eof()){
			if(pcode == pkey){
				cout << "\n\n Product deleted successfully";
				token++;
			}
			else{
				data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
			}
			data >> pcode >> pname >> price >> dis;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt", "database.txt");

		if(token == 0){
			cout << "\n\n Record not found";

		}

	}

}

void shopping :: list(){
	fstream data;
	data.open("database.txt", ios::in);
	cout << "\n\n________________\n";
	cout << "ProNoNamePrice\n";
	cout << "\n\n________________\n";
	data >> pcode >> pname >> price >> dis;
	while(!data.eof()){
		cout << pcode << "" << pname << "" << price << "\n";
		data >>  pcode >> pname >> price >> dis;
	}

	data.close();
}

void shopping :: receipt(){
	m:
	fstream data;
	int arrc[100]; //array of codes
	int arrq[100]; //array of quantity
	char choice;
	int c = 0;
	float amount;
	float dis = 0;
	float total = 0;


	cout << "\n\n RECEIPT ";
	data.open("database.txt",ios::in);

	if(!data){
		cout << "\n\n Empty database";
	}
	else{
		data.close();

		list();
		cout << "\n___________\n";
		cout << "\n                             \n";
		cout << "\n      Please place order     \n";
		cout << "\n                             \n";
		cout << "\n___________\n";

		do{

			cout << "\n\n Enter Product code :";
			cin >> arrc[c];
			cout << "\n\n Enter the product quantity :";
			cin >> arrq[c];

			for(int i = 0; i < c; i++)
			{
				if(arrc[c] == arrc[i])
				{
					cout << "\n\n Duplicate product code. Pleasetry again!";
					goto m;
				}
			}
			c++;
			cout << "\n\n Do you want to buy another product? if yes then press y else press anything else\n";
			cin >> choice;
		}while(choice == 'y');
		

			cout << "\n\n________RECEIPT________";
			cout << "\nProduct No product Name product quantitypriceAmountAmount with discount\n";

			for(int i = 0; i < c; i++){
				data.open("database.txt", ios::in);
				data >> pcode >> pname >> price >> dis;
				while(!data.eof())
				{

					if(arrc[i] == pcode){
						amount = price*arrq[i];
						dis = amount - (amount*dis/100);
						total += dis;
						cout << "\n" << pcode << "  " << pname << "  " << arrq[i] << "  " << price << "  " << amount << "  " << dis; 
					}
					data >> pcode >> pname >> price >> dis;
				}
			
			data.close();

		}

		cout << "\n\n__________________";
		cout << "\n Total Amount : " << total; 

	}

}

int main(){
	shopping s;
	s.menu();
	
}