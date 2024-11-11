#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> G[N];
int mark[N];
int dep[N];
int par[N];
int dp[N][20];
void poreshkon(int u) {
  if (u == 1) {
    return;
  }
  dp[u][0] = par[u];
  for (int i = 1; i < 20; i++) {
    dp[u][i] = dp[dp[u][i - 1]][i - 1];
  }
}
void dfs(int u, int d) {
  mark[u] = 1;
  dep[u] = d;
  poreshkon(u);
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (mark[v] == 0) {
      par[v] = u;
      dfs(v, d + 1);
    }
  }
}
int lca(int u, int v) {
  if (dep[u] > dep[v]) {
    swap(u, v);
  }
  if (dep[v] > dep[u]) {
    for (int i = 19; i >= 0; i--) {
      int vv = dp[v][i];
      if (dep[vv] >= dep[u]) {
        return lca(u, vv);
      }
    }
  }
  if (u == v) {
    return v;
  }
  if (par[u] == par[v]) {
    return par[u];
  }
  for (int i = 19; i >= 0; i--) {
    if (dp[u][i] != dp[v][i]) {
      u = dp[u][i];
      v = dp[v][i];
      return lca(u, v);
    }
  }
}
int solve(int f, int s, int t) {
  int sf = lca(f, s);
  int tf = lca(t, f);
  int st = lca(s, t);
  if (tf == sf) {
    return (dep[f] - dep[sf]) + (st - dep[tf]);
  } else {
    return dep[f] - max(dep[tf], dep[sf]);
  }
}
signed main() {
  int n, q;
  cin >> n >> q;
  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p;
    G[p].push_back(i);
    G[i].push_back(p);
  }
  dfs(1, 0);
  while (q--) {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = solve(a, b, c);
    ans = max(solve(b, a, c), ans);
    ans = max(solve(c, a, b), ans);
    cout << ans + 1 << endl;
  }
}
