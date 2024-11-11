#include<bits/stdc++.h>
using namespace std;
int main()
{
	int e,r,a=0;
	string s;
	cin>>s;
	e=s.find("A");
	r=s.rfind("Z");
	a=(r-e)+1;
	cout<<a;
	return 0;
}