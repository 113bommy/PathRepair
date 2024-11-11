#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	if (s.lenght()%2==0)
	cout<<s;
	else
	{
		reverse(s.begin(),s.end());
	cout<<s;
	}
	
}