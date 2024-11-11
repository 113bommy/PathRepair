#include<iostream>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int e=0,w=0,S=0,n=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='E')
			e=1;
		else if(s[i]=='W')
		{
			w=1;
		}
		else if(s[i]=='S')
			S=1;
		else if(s[i]=='N')
			n=1;
	}
	if(e!=w||S!=n))
	{
		cout<<"No";
	}
	else
	{
		cout<<"Yes";
	}
	return 0;
}