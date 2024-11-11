#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)
int n, a[100005], v, u, t;
bool out;
vector<int> G[100005];
ll dfs(int u, int p){
	if(G[u].size() == 1) return a[u];
	ll mxv = 0, ac = 0, ret;
	for(int nx: G[u]) if(nx != p){
		ll tmp = dfs(nx,u);
		ac += tmp;
		mxv = max(mxv, tmp);
	}
	ret = a[u] * 2 - ac;
	mxv = max(mxv, ret);
	if(ret < 0 || a[u] < mxv) out = true;
	return ret;
}
int main(){
	scanf("%d", &n);
	rep(i,n) scanf("%d", a+i);
	rep(i,n-1){
		scanf("%d%d", &v, &u);
		v--; u--;
		G[v].push_back(u);
		G[u].push_back(v);
	}
	if(n == 2){
		puts(a[0] == a[1] ? "YES" : "NO");
		return 0;
	}
	for(; G[t].size() == 1; t++);
	if(dfs(t,t) > 0 || out) puts("NO");
	else puts("YES");
}