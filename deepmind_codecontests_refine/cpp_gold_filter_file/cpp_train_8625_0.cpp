#include<iostream>
#include<string>
using namespace std;
int a1,a;
int main(){
	string s1,s2;
	cin>>s1;
	for(int i=0;i<s1.size();i++)
	   {
	   	  if(s1[i]=='p') a1++;  
	   }
	a=s1.size()/2;
	cout<<a-a1;
}