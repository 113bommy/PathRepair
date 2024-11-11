#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin>>n;
	int s=0,mx=0;
	int t;
	while(n--)
	{
		cin>>t;
		s+=t;
		mx=max(mx,t);
	}
	cout<<(s-mx/2)<<"\n";
	return 0;
}