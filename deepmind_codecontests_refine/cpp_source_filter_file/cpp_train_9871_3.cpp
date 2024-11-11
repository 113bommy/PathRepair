#include<bits/stdc++.h>
using namespace std;
long long c[200001];
int h[200001];
long long maxn;
int lowbit(int x)
{
	return x&-x;
}
void increase(int index,long long value)
{
	while(index<=200001)
	{
		c[index]=max(c[index],value);
		index+=lowbit(index);
	}
}
long long maxrange(int index)
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
	int n,i,t;
	long long a;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&h[i]);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a);
		t=maxrange(h[i])+a;
		increase(h[i],t);
		maxn=max(maxn,t);
	}
	printf("%lld",maxn);
	return 0;
}