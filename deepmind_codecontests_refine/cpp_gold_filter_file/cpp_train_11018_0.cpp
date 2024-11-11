#include<cstdio>
#include<cctype>
const int maxn=1000010;
int n;
int a[maxn],b[maxn];
int dg[maxn];
struct Edge {
	int to,id,fl;
	Edge *ne;
}el[maxn],*la[maxn],*st[maxn],*cl=el;
int cc;
bool vv[maxn];
int ww[maxn],xx[maxn];
int In() {
	register char c;
	for(;c=getchar(),c!='-'&&!isdigit(c););
	register bool f=c=='-';
	register int s=f?0:c-'0';
	for(;c=getchar(),isdigit(c);)s=s*10+c-'0';
	return f?-s:s;
}
void ins(register int u,register int v,register int id) {
	++cc;
	*++cl=(Edge){v,id,cc,la[u]},la[u]=cl,++dg[v];
	*++cl=(Edge){u,-id,cc,la[v]},la[v]=cl,++dg[u];
}
void dfs(int x) {
	for(Edge *i=la[x];i;i=la[x]) {
		if(!vv[i->fl]) {
			if(i->id) i->id>0?ww[i->id]=1:ww[-i->id]=-1;
			vv[i->fl]=1,la[x]=la[x]->ne,dfs(i->to);
		}
		else la[x]=la[x]->ne;
	}
}
int main() {
	n=In();
	for(register int i=1;i<=n;++i)a[i]=In(),~a[i]?ins(i,a[i],i):ins(i,0,i);
	for(register int i=1;i<=n;++i)b[i]=In(),~b[i]?ins(i+n,b[i]+n,0):ins(i+n,0,0);
	for(register int i=1;i<=n;++i) {
		if((dg[i]&1)^(dg[i+n]&1)) return puts("IMPOSSIBLE"),0;
		register int z=dg[i]<dg[i+n]?dg[i]:dg[i+n];
		for(register int j=1;j<=z;++j)ins(i,i+n,0);
	}
	for(register int i=1;i<=n;++i)st[i]=la[i];
	dfs(0);
	for(register int i=1;i<=n;++i) {
		xx[i]=-ww[i];
		for(register Edge *j=st[i];j;j=j->ne)if(j->to&&j->to<=n&&j->to!=a[i]) xx[i]+=ww[j->to];
	}
	puts("POSSIBLE");
	for(register int i=1;i<=n;++i)printf("%d%c",xx[i]," \n"[i==n]);
	return 0;
}