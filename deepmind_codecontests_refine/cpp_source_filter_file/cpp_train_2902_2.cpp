#include <iostream>
using namespace std;

bool isLeapYear(int y){
    return ( year%4 == 0 && year%100 != 0 || year%400 == 0 )? true : false ;
}

int main(){
	int a,b;
	bool flag, iniFlag = true;
	
	while( cin >> a >> b , a || b ){
		flag = true;
		if( iniFlag == false ){
			cout << endl;
		}else{
			iniFlag = false;
		}	

		for(int i=a ; i<=b ; i++){
			if( isLeapYear(i) ){
				flag = false;
				cout << i << endl;
			}
		}
		if( flag ) cout << "NA" << endl;		
	}
}