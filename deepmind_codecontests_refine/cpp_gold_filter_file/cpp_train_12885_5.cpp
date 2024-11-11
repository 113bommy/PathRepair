#include<bits/stdc++.h> 
using namespace std;
int main(){
	string s,t;
	int s1=0,i;
	cin>>s>>t;
	for(i=0;i<s.size();i++){
		if(s[i]!=t[i]) s1++;
	} 
	cout<<s1;
	return 0;
}