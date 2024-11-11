#include<bits/stdc++.h>
using namespace std;

int n,s1=0,s2=0;
string s;
int main(){
	cin>>n;
	cin>>s;
	for(int i=1;i<n;i++)
	    if(s[i]!='R')
	       s1++;
	for(int n-s1;i<n;i++)
	    if(s[i]!='W')
	       s2++;
	    
	cout<<s2;
	return 0;
} 