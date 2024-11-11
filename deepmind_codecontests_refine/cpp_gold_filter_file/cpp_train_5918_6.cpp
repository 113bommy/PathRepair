#include<bits/stdc++.h>
using namespace std;
string s;
int k; 
int main()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]=='1') k++;
	cout<<k;
	return 0; 
}