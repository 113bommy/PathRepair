#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int n, m, qq;
vector<int> to[N], res[N];
int sum[N], up[N], dep[N];
void dfs(int u, int fa) {
  dep[u] = dep[fa] + 1;
  up[u] = fa;
  for (int v : to[u])
    if (v != fa && !dep[v]) dfs(v, u);
}
int ss = 0;
void calc(int u, int fa) {
  if (sum[u] & 1) ++ss;
  for (int v : to[u])
    if (v != fa && dep[v] == dep[u] + 1) calc(v, u);
}
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    int u, v;
    cin >> u >> v;
    to[u].push_back(v);
    to[v].push_back(u);
  }
  dfs(1, 1);
  cin >> qq;
  for (int i = 1; i <= qq; ++i) {
    int u, v;
    cin >> u >> v;
    vector<int> tmp;
    while (dep[v] > dep[u]) {
      tmp.push_back(v);
      v = up[v];
    }
    while (dep[u] > dep[v]) {
      res[i].push_back(u);
      u = up[u];
    }
    while (u != v) {
      res[i].push_back(u);
      tmp.push_back(v);
      u = up[u];
      v = up[v];
    }
    res[i].push_back(u);
    for (int j = tmp.size() - 1; j >= 0; --j) res[i].push_back(tmp[j]);
    for (int j = 0; j < res[i].size(); ++j) {
      if (j != 0 && j != res[i].size() - 1) ++sum[res[i][j]];
      ++sum[res[i][j]];
    }
  }
  calc(1, 1);
  if (ss)
    cout << "NO\n" << ss / 2 << '\n';
  else {
    cout << "YES\n";
    for (int i = 1; i <= qq; ++i) {
      cout << res[i].size() << '\n';
      for (int j : res[i]) cout << j << ' ';
      cout << '\n';
    }
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
