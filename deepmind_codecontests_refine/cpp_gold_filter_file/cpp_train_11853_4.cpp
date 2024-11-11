#include<bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
	int a,b,c,f=0,t=0;
	string s[102];
	cin>>a>>b;
	r(i,a){
		cin>>s[i+1];
		s[i+1]="#"+s[i+1]+"#";
	}
	r(i,b+2)s[0]+="#",s[a+1]+="#";
	r(i,a+2)cout<<s[i]<<endl;
}