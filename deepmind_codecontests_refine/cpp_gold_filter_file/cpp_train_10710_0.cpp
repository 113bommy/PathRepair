#include<iostream>
using namespace std;

int main(){
   int X[5];

   while(1){
	int con1=0,con2=0,con3=0;
	
	cin >> X[0];
	if(X[0] == 0) break;

	for(int i=1;i<5;i++){
		cin >> X[i];
	}

	for(int i=0;i<5;i++){
		if(X[i] == 1) con1++;
		if(X[i] == 2) con2++;
		if(X[i] == 3) con3++;
	}

	if(((con1 != 0)&&(con2 != 0)&&(con3 != 0))||((con1 == 0)&&(con2 == 0))||((con2 == 0)&&(con3 == 0))||((con1 == 0)&&(con3 == 0))){
		for(int i=0; i<5; i++){
			cout << "3" << "\n";
		}

	}else if(con1 == 0){
		for(int i=0; i<5; i++){
			if(X[i] == 2) {
				cout << "1";
			}else{
				cout << "2";
			}

			cout << endl;
		}
	}else if(con2 == 0){
		for(int i=0; i<5; i++){
			if(X[i] == 3) {
				cout << "1";
			}else{
				cout << "2";
			}

			cout << endl;
		}
	}else if(con3 == 0){
		for(int i=0; i<5; i++){
			if(X[i] == 1) {
				cout << "1";
			}else{
				cout << "2";
			}

			cout << endl;
		}
	}
   }

   return 0;
}