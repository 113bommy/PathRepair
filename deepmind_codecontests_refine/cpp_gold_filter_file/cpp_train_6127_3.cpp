#include<iostream>
using namespace std;
int main(){

	long long int s,c;

	cin>>s>>c;
	if(s>=c/2){
		cout<<c/2<<endl;
	}

	if(c/2>s){
		cout<<s+(c-s*2)/4<<endl;
	}

	return 0;
}

