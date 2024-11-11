#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	set<string>s1;
	for(int i=0; i<n; i++)
	{
		string s;
		cin>>s;
		s1.insert(s);
	}
	cout<<s1.size()<<endl;
}