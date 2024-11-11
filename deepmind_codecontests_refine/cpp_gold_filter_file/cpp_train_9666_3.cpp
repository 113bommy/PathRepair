#include<cstdio>
#include<algorithm>
#include<cstring>

#define maxn 200050
#define add(u,v)(to[++top]=head[u],head[u]=top,w[top]=v)
#define For(x) for (int h=head[x],o=w[h];h;o=w[h=to[h]])

using namespace std;

int n,m,to[maxn],head[maxn],w[maxn],u,v,top;
int a[maxn],b[maxn],c[maxn],co[maxn],r[maxn],q,i;

void dfs(int x,int rg,int col){
	if (rg<=r[x]||rg<=0) return;
	r[x]=rg;
	if (co[x]==0) co[x]=col;
	For(x) dfs(o,rg-1,col);
}

int main(){
	scanf("%d%d",&n,&m);
	while (m--){
		scanf("%d%d",&u,&v);
		add(u,v);add(v,u);
	}
	scanf("%d",&q);
	for (i=1;i<=q;i++) scanf("%d%d%d",&a[i],&b[i],&c[i]);
	memset(co,0,sizeof(co));memset(r,0,sizeof(r));
	for (i=q;i>=1;i--) dfs(a[i],b[i]+1,c[i]);
	for (i=1;i<=n;i++) printf("%d\n",co[i]);
	return 0;
}