#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	int t=0;
	for(int i=0;i<3;i++)
	if(s1[i]==s2[i]) t++;
	cout<<t;
	return 0;
}