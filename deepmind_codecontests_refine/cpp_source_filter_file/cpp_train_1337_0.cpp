#include<bits/stdc++.h>

using namespace std;

int n,a[100010],a1[100010],b[100010],b1[100010];
int ans=-1,fa[100010],h[19260827],p[19260827],cnt;

inline int hash(int x)
{
	int y=x%19260817;
	while(h[y]>=0&&h[y]!=x)y=(y+1)%19260817;
	return y;
}

inline int f(int x)
{
	if(fa[x]!=x)fa[x]=f(fa[x]);
	return fa[x];
}

int main()
{
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&a[i]);
		a1[i]=a[i];
		a[n+1]^=a[i];
	}
	a1[n+1]=a[n+1];
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&b[i]);
		b1[i]=b[i];
		b[n+1]^=b[i];
	}
	b1[n+1]=b[n+1];
	sort(a1+1,a1+n+2);
	sort(b1+1,b1+n+2);
	for(int i=1; i<=n+1; i++)
	{
		if(a1[i]^b1[i])
		{
			printf("-1");
			return 0;
		}
	}
	memset(h,-1,sizeof(h));
	for(int i=1; i<=n+1; i++)
	{
		if(i==n+1||a[i]^b[i])
		{
			if(i<=n)ans++;
			int k=hash(a[i]);
			if(h[k]==-1)h[k]=a[i],p[k]=++cnt;
			k=hash(b[i]);
			if(h[k]==-1)h[k]=b[i],p[k]=++cnt;
		}
	}
	for(int i=1; i<=cnt; i++)fa[i]=i;
	for(int i=1; i<=n+1; i++)
	{
		if(a[i]^b[i])
		{
			fa[f(p[hash(a[i])])]=f(p[hash(b[i])]);
		}
	}
	for(int i=1; i<=cnt; i++)if(fa[i]==i)ans++;
	printf("%d",ans);
	return 0;
}