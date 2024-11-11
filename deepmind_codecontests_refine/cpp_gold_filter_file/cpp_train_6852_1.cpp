#include<iostream>
#define int long long
using namespace std;
int a[1000001],n,ans;
int s[1000001],c[5000001];
int lowbit(int x)
{
	return x&(-x);
}
void add(int x,int d)
{
	for (;x<=n*4;x+=lowbit(x))
		c[x]+=d;
	return;
}
int sum(int x)
{
	ans=0;
	for (;x>=1;x-=lowbit(x))
		ans+=c[x];
	return ans;
}
bool check(int x)
{
	for (int i=1;i<=n*4;++i)
		c[i]=0;
	s[0]=0;
	int res=0;
	for (int i=1;i<=n;++i)
	{
		if (a[i]>=x)
			s[i]=s[i-1]+1;
		else
			s[i]=s[i-1]-1;
	}
	for (int i=0;i<=n;++i)
	{
		res+=sum(s[i]+n+1);
		add(s[i]+n+1,1);
	}
	return res>=(n+1)*n/4;
}
signed main()
{
	int first,last,mid,ans=-(1e+9),minn=1e+9,maxn=-(1e+9);
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
	}
	first=minn;
	last=maxn;
	ans=minn;
	while (first<=last)
	{
		mid=(first+last)/2;
		if (check(mid))
		{
			ans=max(ans,mid);
			first=mid+1;
		}
		else
			last=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}