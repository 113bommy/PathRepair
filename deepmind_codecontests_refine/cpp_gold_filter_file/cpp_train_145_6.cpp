#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
vector<vector<int>> G(MAX);
vector<int> odd(MAX, 0), lef(MAX, 0), vis(MAX, 0), par(MAX);
vector<tuple<int, int, int>> ans;
void dfs(int node, int p) {
  vis[node] = 1;
  par[node] = p;
  for (int nxt : G[node]) {
    if (!vis[nxt]) {
      dfs(nxt, node);
    }
  }
  vector<int> Ve;
  for (int nxt : G[node]) {
    if (nxt != p) {
      if (par[nxt] == node && odd[nxt]) {
        ans.push_back({node + 1, nxt + 1, lef[nxt] + 1});
      } else if (vis[nxt] == 1 || par[nxt] == node)
        Ve.push_back(nxt);
    }
  }
  int sz = Ve.size();
  if (sz & 1) {
    odd[node] = 1;
    lef[node] = Ve[sz - 1];
  }
  for (int i = 0; i + 1 < sz; i += 2) {
    ans.push_back({Ve[i] + 1, node + 1, Ve[i + 1] + 1});
  }
  vis[node] = 2;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  if (m & 1) {
    cout << "No solution\n";
    return 0;
  }
  dfs(0, -1);
  for (auto x : ans) {
    int a, b, c;
    tie(a, b, c) = x;
    cout << a << ' ' << b << ' ' << c << '\n';
  }
  return 0;
}
