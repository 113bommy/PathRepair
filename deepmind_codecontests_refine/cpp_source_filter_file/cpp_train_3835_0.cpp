#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const ll P=1000000007;
const int maxn=5010;
int n,m,cnt,rt,mn,sum;
ll ans;
int head[maxn],to[maxn<<1],next[maxn<<1],siz[maxn],fa[maxn],v[maxn];
ll jc[maxn],jcc[maxn],ine[maxn],f[maxn],g[maxn],h[maxn];
inline void add(int a,int b)
{
	to[cnt]=b,next[cnt]=head[a],head[a]=cnt++;
}
void dfs(int x)
{
	siz[x]=1;
	int i,tmp=0;
	for(i=head[x];i!=-1;i=next[i])	if(to[i]!=fa[x])
		fa[to[i]]=x,dfs(to[i]),siz[x]+=siz[to[i]],tmp=max(tmp,siz[to[i]]);
	tmp=max(tmp,n-siz[x]);
	if(tmp<mn)	mn=tmp,rt=x;
}
inline ll c(int a,int b)
{
	if(a<b)	return 0;
	return jc[a]*jcc[b]%P*jcc[a-b]%P;
}
inline int rd()
{
	int ret=0,f=1;	char gc=getchar();
	while(gc<'0'||gc>'9')	{if(gc=='-')	f=-f;	gc=getchar();}
	while(gc>='0'&&gc<='9')	ret=ret*10+(gc^'0'),gc=getchar();
	return ret*f;
}
int main()
{
	n=rd();
	int i,j,k,a,b;
	memset(head,-1,sizeof(head));
	jc[0]=jcc[0]=ine[0]=jc[1]=jcc[1]=ine[1]=1;
	for(i=2;i<=n;i++)	jc[i]=jc[i-1]*i%P,ine[i]=P-(P/i)*ine[P%i]%P,jcc[i]=jcc[i-1]*ine[i]%P;
	for(i=1;i<n;i++)	a=rd(),b=rd(),add(a,b),add(b,a);
	mn=1<<30,dfs(1);
	if(mn+mn==n)
	{
		printf("%lld",jc[n/2]*jc[n/2]%P);
		return 0;
	}
	for(i=head[rt];i!=-1;i=next[i])
	{
		if(to[i]==fa[rt])	v[++m]=n-siz[rt];
		else	v[++m]=siz[to[i]];
	}
	f[0]=1;
	for(i=1;i<=m;i++)
	{
		for(j=0;j<=v[i];j++)	g[j]=c(v[i],j)*c(v[i],j)%P*jc[j]%P;
		memset(h,0,sizeof(h[0])*(sum+v[i]+2));
		for(j=0;j<=sum;j++)	for(k=0;k<=v[i];k++)	h[j+k]=(h[j+k]+f[j]*g[k])%P;
		memcpy(f,h,sizeof(h[0])*(sum+v[i]+2));
		sum+=v[i];
	}
	for(i=n;i>=0;i--)
	{
		f[i]=f[i]*jc[n-i]%P;
		for(j=i+1;j<=n;j++)	f[i]=(f[i]-f[j]*c(j,i))%P;
	}
	printf("%lld",(f[0]+P)%P);
	return 0;
}
