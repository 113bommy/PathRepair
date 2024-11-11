#include <bits/stdc++.h>
using namespace std;
int n, lg;
vector<int> G[200004];
long long vis[200004], sz[200004], par[17][200004], h[200004];
void dfs(int u, int p) {
  vis[u] = 1;
  sz[u] = 1;
  h[u] = h[p] + 1;
  par[0][u] = p;
  for (int i = 1; i <= lg; i++) par[i][u] = par[i - 1][par[i - 1][u]];
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (!vis[v]) {
      dfs(v, u);
      sz[u] += sz[v];
    }
  }
}
int lca(int u, int v) {
  if (h[v] > h[u]) swap(u, v);
  for (int i = lg; i >= 0; i--)
    if (h[u] - (1 << i) >= h[v]) u = par[i][u];
  for (int i = lg; i >= 0; i--)
    if (par[i][u] != par[i][v]) u = par[i][u], v = par[i][v];
  if (u != v) u = par[0][u];
  return u;
}
int findpar(int u, int d) {
  for (int i = lg; i >= 0; i--)
    if ((1 << i) <= d) {
      d -= (1 << i);
      u = par[i][u];
    }
  return u;
}
int main() {
  ios_base::sync_with_stdio(0);
  int m, c, x, y;
  cin >> n;
  lg = log2(n);
  for (int i = 1; i < n; i++) {
    cin >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  dfs(1, 0);
  cin >> m;
  while (m--) {
    int x, y;
    cin >> x >> y;
    if (x == y) {
      cout << n << "\n";
      continue;
    }
    int l = lca(x, y);
    int d = h[x] + h[y] - 2 * h[l];
    if (d % 2) {
      cout << "0\n";
      continue;
    }
    if (h[x] < h[y]) swap(x, y);
    d /= 2;
    int p = findpar(x, d - 1);
    if (h[x] == h[y]) {
      cout << n - sz[p] - sz[findpar(y, d - 1)] << "\n";
    } else {
      cout << sz[par[0][p]] - sz[p] << "\n";
    }
  }
}
