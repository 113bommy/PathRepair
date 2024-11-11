#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e16;
const int MAX=2500;
const int N=105;
ll n,m,s;
ll a[N][N],b[N][N],c[N],d[N],f[N][MAX+10],v[N][MAX+10];
struct node {
	ll num1,num2,len;
	node() {}
	node(ll a,ll b,ll c) {
		num1=a; num2=b; len=c;
	}
	bool operator<(const node &node1) const {
		return len<node1.len;
	}
	bool operator>(const node &node1) const {
		return len>node1.len;
	}
};
priority_queue<node,vector<node>,greater<node>> q;
inline ll calc(ll x) {
	if (x>MAX) return MAX;
	else return x;
}
int main() {
	ll u,w,x,y,i,j,ans;
	node p;
	scanf("%lld%lld%lld",&n,&m,&s);
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			b[i][j]=INF;
	for (i=1;i<=m;i++) {
		scanf("%lld%lld%lld%lld",&u,&w,&x,&y);
		a[u][w]=a[w][u]=x;
		b[u][w]=b[w][u]=y;
	}
	for (i=1;i<=n;i++)
		scanf("%lld%lld",&c[i],&d[i]);
	s=calc(s);
	q.push(node(1,s,0));
	for (i=1;i<=n;i++)
		for (j=0;j<=MAX;j++)
			f[i][j]=INF;
	f[1][s]=0;
	while (!q.empty()) {
		p=q.top(); q.pop();
		x=p.num1; y=p.num2;
		if (v[x][y]>0) continue;
		v[x][y]=1;
		if (!v[x][calc(y+c[x])]&&f[x][y]+d[x]<f[x][calc(y+c[x])]) {
			f[x][calc(y+c[x])]=f[x][y]+d[x];
			q.push(node(x,calc(y+c[x]),f[x][y]+d[x]));
		}
		for (i=1;i<=n;i++)
			if (b[x][i]<INF) {
				if (y-a[x][i]>=0&&!v[i][y-a[x][i]]&&f[x][y]+b[x][i]<f[i][y-a[x][i]]) {
					f[i][y-a[x][i]]=f[x][y]+b[x][i];
					q.push(node(i,y-a[x][i],f[x][y]+b[x][i]));
				}
			}
	}
	for (i=2;i<=n;i++) {
		ans=INF;
		for (j=0;j<=MAX;j++)
			ans=min(ans,f[i][j]);
		printf("%lld\n",ans);
	}
	return 0;
} 