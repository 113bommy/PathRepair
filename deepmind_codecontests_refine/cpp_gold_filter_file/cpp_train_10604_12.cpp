#include<bits/stdc++.h>
using namespace std;
string a,b="CODEFESTIVAL2016";
int main()
{
	double ans;
	ans=16;
	getline(cin,a);
	for(int i=0;i<=15;i++)
	{
		if(a[i]==b[i]) ans--;
	}
	cout<<ans<<endl;
	return 0;
}