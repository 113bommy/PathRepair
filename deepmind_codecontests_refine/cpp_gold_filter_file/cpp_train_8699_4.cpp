#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 22;
int n, k;
int par[N], dpd[N];
vector<int> ans;
vector<int> G[N];
bool c[N];
void dfs_down(int v, int p = -1) {
  for (int i = 0; i < (G[v].size()); i++) {
    int u = G[v][i];
    if (u == p) continue;
    par[u] = v;
    dfs_down(u, v);
    dpd[v] += dpd[u] + c[u];
  }
}
void dfs(int v, int p = -1) {
  if (c[v]) ans.push_back(v);
  for (int i = 0; i < (G[v].size()); i++) {
    int u = G[v][i];
    if (u == p) continue;
    dfs(u, v);
  }
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < (n - 1); i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    G[x].push_back(y), G[y].push_back(x);
  }
  for (int i = 0; i < (2 * k); i++) {
    int x;
    cin >> x;
    x--;
    c[x] = true;
  }
  dfs_down(0);
  for (int i = 0; i < (n); i++) {
    int r = 0;
    for (int j = 0; j < (G[i].size()); j++) {
      int u = G[i][j];
      if (par[i] == u)
        r = max(r, 2 * k - dpd[i] - c[i]);
      else
        r = max(r, dpd[u] + c[u]);
    }
    if (r <= k) {
      dfs(i);
      cout << 1 << endl << i + 1 << endl;
      for (int j = 0; j < (ans.size() / 2); j++)
        cout << ans[j] + 1 << " " << ans[j + k] + 1 << " " << i + 1 << endl;
      return 0;
    }
  }
  return 0;
}
