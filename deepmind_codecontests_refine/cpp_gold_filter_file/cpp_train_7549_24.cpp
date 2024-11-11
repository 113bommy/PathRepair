#include <bits/stdc++.h>
const double EPS = 0.00000001;
const long long mod = 1000000000 + 7;
using namespace std;
vector<int> g[100100];
int vis[100100], rnk[100100], rnk2[100100];
pair<int, int> e[100100];
int t;
int n, m;
void dfs(int s) {
  vis[s] = 1;
  int mx = 0;
  for (auto u : g[s]) {
    if (!vis[u]) dfs(u);
    mx = max(mx, rnk[u]);
  }
  rnk[s] = mx + 1;
}
int valid() {
  for (int i = 0; i < n; i++) {
    if (rnk[i] != rnk2[i]) return 0;
  }
  return 1;
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m;
  int u, v;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    u--, v--;
    e[i] = {u, v};
    g[u].push_back(v);
  }
  for (int i = 0; i < n; i++) {
    if (!vis[i]) dfs(i);
  }
  for (int i = 0; i < n; i++) rnk2[i] = rnk[i];
  sort(rnk2, rnk2 + n);
  for (int i = 0; i < n - 1; i++) {
    if (rnk2[i] == rnk2[i + 1]) {
      cout << -1 << endl;
      return 0;
    }
  }
  for (int i = 0; i < n; i++) rnk2[i] = rnk[i];
  int l = 0, r = m;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    memset(vis, 0, sizeof(vis));
    memset(rnk, 0, sizeof(rnk));
    for (int i = 0; i < n; i++) g[i].clear();
    for (int i = 0; i < mid; i++) {
      g[e[i].first].push_back(e[i].second);
    }
    for (int i = 0; i < n; i++)
      if (!vis[i]) dfs(i);
    if (valid())
      r = mid;
    else
      l = mid;
  }
  cout << r << endl;
  int ____________;
  cin >> ____________;
  return 0;
}
