#include<cstdio>
#include<cstring>
#define M 400004
#define N 100002
int S,T,a[N],b[M],c[M],e[N],f[N],g[N],h[N],l,n,o[N],p[N],q[N],r,t,x;bool d[M];
inline void add(int u,int v){b[++t]=a[u],c[a[u]=t]=v,d[t]=true,b[++t]=a[v],c[a[v]=t]=u;}
inline bool bfs()
{
    for(memset(h+1,-1,T<<2),q[l=0]=S,r=1;l<r;)
		for(int u=q[l++],i=a[u];i;i=b[i])
			if(d[i]&&h[c[i]]<0)h[q[r++]=c[i]]=h[u]+1;
    return h[T]>=0;
}
bool dfs(int u)
{
    if(u==T)return true;
    for(int&i=e[u];i;i=b[i])if(d[i]&&h[c[i]]==h[u]+1&&dfs(c[i]))return d[i]=false,d[i^1]=true;
    return false;
}
int i,j;
int main()
{
    scanf("%d",&n),t=1,x=n;
    for(i=0;i<n;i++)scanf("%d",o+i);
    for(i=0;i<n;i++)scanf("%d",p+i);
    for(i=0;i<n;i++) if(o[i]!=i&&!f[i]) for(j=i,T++;!f[j];j=o[j])f[j]=T;
    for(i=0;i<n;i++) if(p[i]!=i&&!g[i]) for(j=i,T++;!g[j];j=p[j])g[j]=T;
    for(i=0,T++;i<n;i++)
	    if(o[i]==i&&p[i]==i)x--;
	    else if(o[i]==i)add(g[i],T);
	    else if(p[i]==i)add(S,f[i]);
	    else if(o[i]!=p[i])add(g[i],f[i]);
	    else add(f[i],g[i]),add(g[i],f[i]);
    while(bfs())for(memcpy(e,a,T+1<<2);dfs(S);)x--;
    printf("%d\n",x)
}
