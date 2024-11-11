#include<bits/stdc++.h>
using namespace std;
int main(){
	int ans=0,i;
	string s,t;
	cin>>s>>t;
	for(i=0;i<s.size();i++)if(s[i]!=t[i])ans++;
	couut<<ans; 
	return 0;
}
