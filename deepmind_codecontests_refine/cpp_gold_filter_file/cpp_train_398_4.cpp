#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	string b=s;
	reverse(s.begin(),s.end());
	for(int i=0; i<s.size();i++)
	{
		if(s[i]=='b') s[i]='d';
		else if(s[i]=='d') s[i]='b';
		else if(s[i]=='p') s[i]='q';
		else if(s[i]=='q') s[i]='p';
	}
	if(s==b) 
	cout<<"Yes"<<"\n";
	else
	cout<<"No"<<"\n";
	return 0;
}