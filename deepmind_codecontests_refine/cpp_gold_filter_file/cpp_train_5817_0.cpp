#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	string t;
	 t="";
	for(int i=0;i<s.size();i++){
		if(s[i]=='1') t+='1';
		else if(s[i]=='0') t+='0';
		else if(t.size()>0) t.erase(t.end()-1);
	} 
	cout<<t;
	return 0; 
} 