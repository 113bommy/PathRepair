#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y)
{
	if(y==0)return x;
	return gcd(y,x%y);
}
int n;
int x;
int xx[10010];
int ans;
int main()
{
	cin>>n>>x;
	cin>>xx[1];
	ans=fabs(xx[1]-x);
	for(int i=2;i<=n;i++)
	{
		cin>>xx[i];
		ans=gcd(ans,fabs(x-x[i]));
	}
	cout<<ans<<endl;
}
