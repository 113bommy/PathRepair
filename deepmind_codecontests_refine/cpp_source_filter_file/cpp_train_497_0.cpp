#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	int red=0,blue=0;
	for(char x: s)
	{
		if(x=='R')
		{
			red++;
		}
		else
		{
			blue++;
		}
	}
	if(red>blue){cout<<"Yes";
	}
	else
	{
		cout<<"No";
	}
