#include<bits/stdc++.h>
using namespace std;
long long x,k,d;
int main()
{
	cin>>k>>x>>d;
	k=abs(k);
	if(x*d>0 && x*d<=k)
	{
		cout<<k-x*d<<endl;
		return 0;
	}
	if((x-k/d)%2==0)
	{
		cout<<k%d<<endl;
	}
	else
	{
		cout<<d-k%d<<endl;
	}
	return 0;
}