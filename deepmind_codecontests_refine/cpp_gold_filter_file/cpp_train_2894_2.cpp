#include <bits/stdc++.h>
using namespace std;

#define f(i,a,b) for (int i = a; i < b; i++)
#define pb push_back
using vi = vector<int>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
int n; cin>>n;
int q; cin>>q;
vi adj[n];
f(i,0,n-1) {
int a, b; cin>>a>>b;
adj[--a].pb(--b);
adj[b].pb(a);
}
vi ans(n,0);
function<void(int,int)> dfs = [&](int v, int p) {
if (p != -1) ans[v] += ans[p];
for (int w : adj[v]) if (w != p)
dfs(w,v);
};
f(_,0,q) {
int p, x; cin>>p>>x;
ans[--p]+=x;
}
dfs(0,-1);
f(i,0,n) cout << ans[i] << " ";
cout << endl;
return 0;
}