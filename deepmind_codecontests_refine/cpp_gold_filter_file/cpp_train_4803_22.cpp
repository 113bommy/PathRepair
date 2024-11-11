#include <bits/stdc++.h>
using namespace std;
const int oo = 1e9, MN = 100010;
int n, order;
int from[MN], to[MN], cost[MN], col[MN];
vector<int> g[MN];
int dfs(int u, int k) {
  col[u] = 0;
  for (int e : g[u]) {
    if (cost[e] <= k) continue;
    int v = to[e];
    if (col[v] == -1) {
      if (!dfs(v, k)) return 0;
    } else if (col[v] == 0) {
      return 0;
    }
  }
  col[u] = ++order;
  return 1;
}
int can(int k) {
  int ok = 1;
  order = 0;
  memset(col, -1, sizeof col);
  for (int i = 0; i < n; i++)
    if (col[i] == -1) ok &= dfs(i, k);
  return ok;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    u--;
    v--;
    from[i] = u;
    to[i] = v;
    cost[i] = c;
    g[u].push_back(i);
  }
  int lo = -1, hi = oo;
  while (hi - lo > 1) {
    int mi = (lo + hi) / 2;
    if (can(mi))
      hi = mi;
    else
      lo = mi;
  }
  can(hi);
  int cnt = 0;
  for (int i = 0; i < m; i++)
    cnt += (cost[i] <= hi && col[from[i]] < col[to[i]]);
  cout << hi << " " << cnt << '\n';
  for (int i = 0; i < m; i++)
    if (cost[i] <= hi && col[from[i]] < col[to[i]]) cout << i + 1 << " ";
  cout << '\n';
  return 0;
}
