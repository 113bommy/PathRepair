#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> pii;
const int N=1e5+10,M=4e5+10,p=1e9+7;
int n,m,s,t,fs[N],gs[N],ft[N],gt[N],vis[N],ans,al;
int tot,fi[N],ne[M],a[M],c[M];
inline void A(int &x,int y){x+=y;if (x>=p) x-=p;}
inline void add(int x,int y,int z){
	a[++tot]=y;c[tot]=z;ne[tot]=fi[x];fi[x]=tot;
}
inline int dp(int x,int *f,int *g){
	if (vis[x]) return g[x];vis[x]=1;
	for (int i=fi[x];i;i=ne[i]) if (f[x]-c[i]==f[a[i]]) A(g[x],dp(a[i],f,g));
	return g[x];
}	
inline void dij(int *f,int *g,int s,int t){
	priority_queue<pii,vector<pii>,greater<pii> > q;
	for (int i=1;i<=n;++i) f[i]=1e15;
	f[s]=0;q.push(make_pair(0,s));
	while (!q.empty()){
		pii tmp=q.top();q.pop();
		int u=tmp.second;
		if (tmp.first>f[u]) continue;
		for (int i=fi[u];i;i=ne[i]) if (f[u]+c[i]<f[a[i]]) f[a[i]]=f[u]+c[i],q.push(make_pair(f[a[i]],a[i]));
	}
	memset(vis,0,sizeof vis);
	g[s]=1;vis[s]=1;
	dp(t,f,g);
}
inline void solve(int x){
	if (vis[x]) return;vis[x]=1;
	if (fs[x]*2==al) {A(ans,p-1ll*gs[x]*gt[x]%p);return;}
	for (int i=fi[x];i;i=ne[i]) if (fs[x]+c[i]==fs[a[i]]){
		if (fs[a[i]]*2>al) A(ans,p-1ll*gs[x]*gt[a[i]]%p);
			else solve(a[i]);
	}
}
signed main(){
	scanf("%lld%lld%lld%lld",&n,&m,&s,&t);
	for (int i=1,x,y,z;i<=m;++i) scanf("%lld%lld%lld",&x,&y,&z),add(x,y,z),add(y,x,z);
	dij(fs,gs,s,t);dij(ft,gt,t,s);
	for (int i=1;i<=n;++i) (gs[i]*=gs[i])%=p,(gt[i]*=gt[i])%=p;
	al=fs[t];ans=gs[t]%p;
	memset(vis,0,sizeof vis);
	solve(s);
	printf("%lld\n",ans;
	return 0;
}
