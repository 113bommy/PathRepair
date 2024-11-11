#include <bits/stdc++.h>
using namespace std;
int ini[100005], fin[100005];
vector<int> E[100005];
int cont[100005], ares[100005], n;
int p[18][100005], h[100005];
void dfs(int u = 0, int pa = 0, int alt = 0) {
  p[0][u] = pa;
  h[u] = alt;
  for (typeof E[u].begin() v = E[u].begin(); v != E[u].end(); v++)
    if (*v != pa) dfs(*v, u, alt + 1);
}
void make_lca() {
  for (int i = 1; i < 18; i++)
    for (int j = 0; j < n; j++) p[i][j] = p[i - 1][p[i - 1][j]];
}
int lca(int x, int y) {
  if (h[x] < h[y]) swap(x, y);
  for (int i = 16; i >= 0; i--)
    if (h[x] - h[y] >= (1 << i)) x = p[i][x];
  if (x == y) return x;
  for (int i = 16; i >= 0; i--)
    if (p[i][x] != p[i][y]) x = p[i][x], y = p[i][y];
  return p[0][x];
}
int res[100005];
void solve(int u = 0, int pa = 0) {
  res[u] = cont[u];
  for (typeof E[u].begin() v = E[u].begin(); v != E[u].end(); v++)
    if (*v != pa) {
      solve(*v, u);
      res[u] += res[*v];
    }
}
int main() {
  cin >> n;
  int m = n - 1;
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--;
    v--;
    E[u].push_back(v);
    E[v].push_back(u);
    ini[i] = u;
    fin[i] = v;
  }
  dfs();
  make_lca();
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--;
    v--;
    int w = lca(u, v);
    cont[u]++;
    cont[v]++;
    cont[w] -= 2;
  }
  solve();
  for (int i = 0; i < m; i++) {
    int u = ini[i], v = fin[i];
    if (h[u] < h[v]) swap(u, v);
    ares[i] = res[u];
  }
  printf("%d", ares[0]);
  for (int i = 1; i < m; i++) printf(" %d", ares[i]);
}
