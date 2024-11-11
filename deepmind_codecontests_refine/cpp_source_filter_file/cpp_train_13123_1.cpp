#include <iostream>
using namespace std;

int main(){

	string str;

	while(1){

		int sum=0;
		getline(cin,str);

		if(str[i]==0) break;

		for(int i=0; i<str.size(); i++){
			sum += str[i];
		}
		cout << sum << endl;
	}
}