#include <iostream>
#include <string>
using namespace std;

int main(void){
	string s;
	bool f=false,b=false;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(!f&&s[i]=='A') f=!f;
		else if(f&&s[i]=='Z'){cout<<"AZ";b=true;f=!f}
	}
	if(!b)cout<<-1;
	cout<<endl;
}