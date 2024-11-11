#include<iostream>
#include<string>
using namespace std;
int main(){
	int n, a = 0, b = 0, o = 0, ab = 0;
	char delim;
	string type;
	while( cin >> n >> delim >> type ){
		if ( type == "A" ) a++;
		else if ( type == "B" ) b++;
		else if ( type == "AB" ) ab++;
		else if ( type == "O" ) o++;
	}
	cout << a << endl << b << endl << ab << endl << o << endl;
}