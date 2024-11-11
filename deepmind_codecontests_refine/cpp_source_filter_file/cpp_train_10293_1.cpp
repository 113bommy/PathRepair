#include <bits/stdc++.h>
using namespace std;
inline int sqr(int x) return x*x;
int main()
{
	int n,a[101];
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans+=sqr(a[i]-0);
	}
	for(x=-100;x<=100;x++)
	{
		int tmp=0;
		for(int i=1;i<=n;i++)
		{
			tmp+=sqr(a[i]-x);
		}
		ans=min(ans,tmp);
	}
	cout<<ans;
}
