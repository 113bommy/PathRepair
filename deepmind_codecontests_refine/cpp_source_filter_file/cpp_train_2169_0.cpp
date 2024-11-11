#include<stdio.h>
#include<algorithm>
using namespace std;
int fa[131072],rank[131072],fw[131072];
int findroot(int x)
{
	if(fa[x]==x)
	{
		return x;
	}
	return findroot(fa[x]);
}
int chk(int u,int v)
{
	int ans=0;
	while(u!=v)
	{
		if(fw[u]<fw[v])
		{
			if(fw[u]>ans)
			{
				ans=fw[u];
			}
			u=fa[u];
		}
		else
		{
			if(fw[v]>ans)
			{
				ans=fw[v];
			}
			v=fa[v];
		}
	}
	return ans;
}
struct node{
	int u;
	int v;
	int w;
	bool operator<(node b) const
	{
		return w<b.w;
	}
};
node nn[262144];
int main()
{
	int n,m;
	long long x;
	scanf("%d%d%lld",&n,&m,&x);
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		rank[i]=1;
		fw[i]=1000000007;
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&nn[i].u,&nn[i].v,&nn[i].w);
	}
	if(n<=2)
	{
		printf("0\n");
		return 0;
	}
	sort(nn,nn+m);
	long long s=0;
	int num=0;
	for(int i=0;i<m;i++)
	{
		int u=findroot(nn[i].u);
		int v=findroot(nn[i].v);
		if(u==v)
		{
			continue;
		}
		s+=nn[i].w;
		num++;
		if(rank[u]>rank[v])
		{
			fa[v]=u;
			fw[v]=nn[i].w;
		}
		else
		{
			if(rank[u]==rank[v])
			{
				rank[v]++;
			}
			fa[u]=v;
			fw[u]=nn[i].w;
		}
	}
	if(num<n-1)
	{
		printf("0\n");
		return 0;
	}
	if(s>x)
	{
		printf("0\n");
		return 0;
	}
	int ss=2,ss2=2;
	if(s==x)
	{
		ss=1;
	}
	for(int i=0;i<m;i++)
	{
		int d=nn[i].w-chk(nn[i].u,nn[i].v);
		if(s+d>=x)
		{
			ss<<=1;
			if(ss>=1000000007)
			{
				ss-=1000000007;
			}
		}
		if(s+d>x)
		{
			ss2<<=1;
			if(ss2>=1000000007)
			{
				ss2-=1000000007;
			}
		}
	}
	ss-=ss2;
	if(ss<0)
	{
		ss+=1000000007;
	}
	printf("%d\n",ss);
	return 0;
}