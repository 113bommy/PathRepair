#include <>bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=1e3+7;
const int Md=1e9+7;
int n,m,K;
LL fac[MX],inv[MX];
LL ans=1;

void init()
{
  int n=1e3;
  fac[0]=fac[1]=inv[0]=inv[1]=1;
  for(int i=2; i<=n; i++)
	{
    fac[i]=fac[i-1]*i%Md;
    inv[i]=(Md-Md/i)*inv[Md%i]%Md;
  }
  for(int i=2; i<=n; i++) inv[i]=inv[i]*inv[i-1]%Md;
}

LL qpow(LL a, LL n)
{
  LL ret=1;
  while(n)
	{
    if(n&1) ret=ret*a%Md;
    a=a*a%Md; n>>=1;
  }
  return ret;
}

int gcd(int x,int y)
{
	return y?gcd(y,x%y):x;
}

LL polya(int m)
{
  LL ret=0;
  for(int i = 1; i <= m; i++)
	{
    ret+=qpow(K,gcd(i,m)); ret%=Md;
  }
  return (ret*qpow(m,Md-2))%Md;
}

LL C(int n, int m)
{
  if(n<m) return 0;
  return fac[n]*inv[m]%Md*inv[n-m]%Md;
}

struct edge
{
  int v; bool vis;
  edge *nxt,*rev;
}*con[MX],*stc[MX];
int dfn[MX],low[MX],tim,top;
bool vis[MX];

void add(int u, int v)
{
  edge *p=new edge;
  p->v=v; p->vis=0; p->nxt=con[u]; con[u]=p;
}
void get_rev(int u, int v)
{
  con[u]->rev=con[v]; con[v]->rev=con[u];
}

void tarjan(int u)
{
  dfn[u]=low[u]=++tim;
  for(edge *p = con[u]; p; p = p->nxt)
	{
    if(p->vis || p->rev->vis) continue;
    stc[++top]=p;
    p->vis=p->rev->vis=1;
    if(!dfn[p->v])
		{
      tarjan(p->v);
      low[u]=min(low[u],low[p->v]);
      if(low[p->v]>=dfn[u]) 
			{
        bool cir=1;//判断一个环的点双联通分量与多重环的点双联通分量
        int cnt=0;
        for(int i=top; stc[i+1]!=p; --i,++cnt)
          if (vis[stc[i]->v]) cir=0;
          else vis[stc[i]->v]=1;
        for(; stc[top+1]!=p; --top) vis[stc[top]->v]=0;
        if(cir) ans=(ans*polya(cnt))%Md;
        else ans=(ans*C(cnt+K-1,K-1))%Md;
        ans%=Md;
      }
    }
    else low[u]=min(low[u],dfn[p->v]);
  }
}

int main()
{
  init();
  scanf("%d%d%d",&n,&m,&K);
  for(int i = 1,u,v; i <= m; i++)
	{
    scanf("%d%d",&u,&v);
    add(u,v); add(v,u); get_rev(u,v);
  }
  for(int i=1; i<=n; i++)
    if(!dfn[i]) tarjan(i);
  printf("%lld\n",ans);
  return 0;
}
