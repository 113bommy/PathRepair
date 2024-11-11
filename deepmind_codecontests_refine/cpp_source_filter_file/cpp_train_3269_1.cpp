#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double EPS = 1e-7;
vector<int> g[100100];
int a[100100];
int depth[100100];
int tin[100100];
int tout[100100];
int timer = 0;
int up[100100][30];
bool c[100100];
bool A[100100];
void dfs(int x, int p, int d) {
  up[x][0] = p;
  for (int i = 1; i < 30; i++) {
    up[x][i] = up[up[x][i - 1]][i - 1];
  }
  depth[x] = d;
  tin[x] = timer++;
  for (int i = 0; i < g[x].size(); i++) {
    if (g[x][i] == p) continue;
    dfs(g[x][i], x, d + 1);
  }
  tout[x] = timer++;
}
bool upp(int x, int y) {
  if (tin[x] <= tin[y] && tout[x] >= tout[y]) return true;
  return false;
}
int lca(int x, int y) {
  if (upp(x, y)) return x;
  if (upp(y, x)) return y;
  for (int it = 30; it >= 0; it--) {
    if (!upp(up[x][it], y)) x = up[x][it];
  }
  return up[x][0];
}
int dist(int x, int y) {
  int z = lca(x, y);
  return depth[x] + depth[y] - 2 * depth[z];
}
bool dfs_mark(int x, int p) {
  c[x] = false;
  for (int i = 0; i < g[x].size(); i++) {
    if (g[x][i] == p) continue;
    if (dfs_mark(g[x][i], x)) c[x] = true;
  }
  if (A[x]) c[x] = true;
  return c[x];
}
int vertice = -1;
int mm;
void dfs_max_distance(int x, int p, int d) {
  if (!c[x]) return;
  if (d > mm) {
    mm = d;
    vertice = x;
  }
  for (int i = 0; i < g[x].size(); i++) {
    if (g[x][i] == p) continue;
    dfs_max_distance(g[x][i], x, d + 1);
  }
}
int main() {
  int n, m, d;
  scanf("%d%d%d", &n, &m, &d);
  for (int i = 0; i < m; i++) {
    scanf("%d", &a[i]);
    a[i]--;
    A[a[i]] = true;
  }
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  if (m == 0) {
    cout << n << endl;
    return 0;
  }
  dfs(0, 0, 0);
  dfs_mark(a[0], -1);
  mm = -1000000000;
  dfs_max_distance(a[0], -1, 0);
  int v1 = vertice;
  mm = -1000000000;
  dfs_max_distance(vertice, -1, 0);
  int v2 = vertice;
  int res = 0;
  for (int i = 0; i < n; i++) {
    if (max(dist(i, v1), dist(i, v2)) <= d) res++;
  }
  cout << res << endl;
}
