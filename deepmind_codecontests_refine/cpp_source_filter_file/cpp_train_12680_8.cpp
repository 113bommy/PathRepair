#include<bits/stdc++.h>
using namespace std;

int main (){
	string s;
	cin>>s;
	int n=s.strlen();int c=0;
	for (int i=0;i<n;i++)if(s[i]=='x')c++;
	if(c<=7)cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}