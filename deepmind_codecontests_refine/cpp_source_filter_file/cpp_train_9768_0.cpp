#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int n,t,z,d,tot,head[55000];
long long ans,f[1000010];
struct point{
	int v,w,num;
	friend bool operator <(point a,point b){
		return a.w*b.v>b.w*a.v;
	}
}a[55000];
struct node{
	int fr,to,nxt;	
}e[55000];
void add(int x,int y)
{
	e[++tot].fr=x;
	e[tot].to=y; e[tot].nxt=head[x];
	head[x]=tot;
}
void dfs(int x)
{
	a[x].w=1; 
	for(int i=head[x];i;i=e[i].nxt)
		dfs(e[i].to),a[x].v+=a[e[i].to].v,a[x].w+=a[e[i].to].w;
}
int main()
{
	scanf("%lld%lld%lld",&n,&t,&d);
	scanf("%lld",&a[1].v); a[1].num=1;
	for(int i=2,x;i<=n;i++)
		scanf("%lld%lld",&a[i].v,&x),a[i].num=i,add(x,i);
	dfs(1);
	memset(f,0x3f,sizeof(f)); f[0]=0;
	for(int i=1;i<=n;i++)
	{
		int tmp=min(d,n);
		for(int j=0;(1<<j)<=tmp;j++) {
			for(int k=n*n*n;k>=0;k--)
				f[k+(1<<j)*a[i].w]=min(f[k+(1<<j)*a[i].w],f[k]+1ll*(1<<j)*a[i].v);
			tmp-=(1<<j);
		}
		if(tmp) for(int k=n*n*n;k>=0;k--)
			f[k+tmp*a[i].w]=min(f[k+tmp*a[i].w],f[k]+1ll*tmp*a[i].v);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) 
		if(a[i].num==1) {z=i;break;}
	for(int i=0;i<=n*n*n;i++)
	{
		if(f[i]>t) continue;
		long long rst=t-f[i],ret=i;
		for(int j=1;j<z;j++)
		{
			int now=min(0ll+d-min(d,n),rst/a[j].v);
			ret+=1ll*now*a[j].w; rst-=1ll*now*a[j].v;
		}
		long long now=rst/a[z].v;
		ret+=1ll*now*a[z].w; ans=max(ans,ret);
	} 
	printf("%lld\n",ans);
}