#include <bits/stdc++.h>
using namespace std;
long long a[200000],c[200000],n;
long long lowbit(long long x)
{
	return x&(-x);
}
void update(long long index,long long max_value)
{
	while(index<=n)
	{
		c[index]=max(c[index],max_value);
		index+=lowbit(index);
	}
}
long long maxrange(long long index)
{
	long long ret=0;
	while(index)
	{
		ret=max(ret,c[index]);
		index-=lowbit(index);
	}
	return ret;
}
int main()
{
	long long i,t,s,ans=0;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&s);
		t=maxrange(a[i]-1);
		update(a[i],t+s);
		ans=max(ans,t+s);
	}
	printf("%lld",ans);
	return 0;
}