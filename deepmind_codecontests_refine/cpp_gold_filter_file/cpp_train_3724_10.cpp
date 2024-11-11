#include<iostream>
using namespace std;
int main(){
	string s;
  	cin>>s;
  	int n=s.length()-1;
  	if(s[n]=='s')s+="es";
  	else s+="s";
  	cout<<s;
  	return 0;
}
