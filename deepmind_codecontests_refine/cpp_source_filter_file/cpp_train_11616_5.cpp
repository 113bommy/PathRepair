#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int a[MAXN];
int n, par[MAXN];
vector<int> adj[MAXN];
long long d[MAXN];
long long ans = -1e8;
long long dfs(int u) {
  long long mx1 = -1e18, mx2 = -1e18;
  d[u] = a[u];
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (v != par[u]) {
      par[v] = u;
      long long tmp = dfs(v);
      if (tmp > mx1)
        mx2 = mx1, mx1 = tmp;
      else if (tmp > mx2)
        mx2 = tmp;
      d[u] += d[v];
    }
  }
  ans = max(ans, mx1 + mx2);
  return max(d[u], mx1);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v), adj[v].push_back(u);
  }
  par[0] = -1;
  dfs(0);
  if (ans < -1e9)
    cout << "Impossible" << endl;
  else
    cout << ans << endl;
  return 0;
}
