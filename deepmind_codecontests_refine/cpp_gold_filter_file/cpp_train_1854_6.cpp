#include<iostream>
#include<string>
using namespace std;
string s;
int main(){
	getline(cin,s);
  if(s[0]!=s[1] && s[1]!=s[2] && s[2]!=s[3])cout<<"Good"<<endl;
  else cout<<"Bad"<<endl;
}