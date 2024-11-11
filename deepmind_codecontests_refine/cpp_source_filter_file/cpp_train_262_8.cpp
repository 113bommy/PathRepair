#include <bits/stdc++.h>
using namespace std;
vector<int> g[400001];
void UP(int &x, int y) {
  if (y > x) x = y;
}
int size[400001], dn[400001], n, ans[400001], up[400001], x, y;
void dfs1(int x, int fa) {
  size[x] = 1;
  for (int i = 0; i < g[x].size(); i++) {
    int to = g[x][i];
    if (to == fa) continue;
    dfs1(to, x);
    if (size[to] - dn[to] > n / 2) ans[to] = 0;
    size[x] += size[to];
    UP(dn[x], dn[to]);
  }
  if (size[x] <= n / 2) dn[x] = size[x];
}
void dfs2(int u, int fa) {
  if (n - size[u] - up[u] > n / 2) ans[u] = 0;
  if (n - size[u] <= n / 2) up[u] = n - size[u];
  int mx = 0;
  for (int i = 0; i < g[u].size(); ++i) {
    int v = g[u][i];
    if (v == fa) continue;
    up[v] = max(up[u], mx);
    UP(mx, dn[v]);
  }
  mx = 0;
  for (int i = g[u].size() - 1; i >= 0; --i) {
    int v = g[u][i];
    if (v == fa) continue;
    UP(up[v], mx);
    UP(mx, dn[v]);
    dfs2(v, u);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) ans[i] = 1;
  dfs1(1, 0), dfs2(1, 0);
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
}
