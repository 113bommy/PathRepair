#include<bits/stdc++.h> 
using namespace std;
int main(){
	string s,t;
	int s=0,i;
	cin>>s>>t;
	for(i=0;i<s.size();i++){
		if(s[i]!=t[i]) s++;
	} 
	cout<<s;
	return 0;
}