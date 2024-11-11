#include<iostream>
#include<string>
using namespace std;

int main(){
	string s;
	while(cin>>s,s!="0"){
		int a,b;
		a=b=0;
		for(int i=1;i<s.size();i++){
			if(s[i]=='A') a++; else b++;
		}
		if(a>b) a++; else b++;
		cout<<a<<" "<<b<<endl;
		
	}
}