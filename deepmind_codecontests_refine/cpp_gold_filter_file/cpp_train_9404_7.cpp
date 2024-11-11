#include <bits/stdc++.h>
using namespace std;
const int N = 400010;
const int L = 20;
bool used[N];
int tin[N], fup[N], timer;
vector<int> g[N];
void dfs(int v, int p = -1) {
  used[v] = true;
  tin[v] = fup[v] = ++timer;
  for (int i = 0; i < (int)g[v].size(); i++) {
    int to = g[v][i];
    if (to == p) continue;
    if (used[to])
      fup[v] = min(fup[v], tin[to]);
    else {
      dfs(to, v);
      fup[v] = min(fup[v], fup[to]);
      if (fup[to] > tin[v]) {
      }
    }
  }
}
bool bridge(int a, int b) {
  if (tin[a] < fup[b]) return true;
  if (tin[b] < fup[a]) return true;
  return false;
}
int parent[N];
int find_parent(int v) {
  if (parent[v] == v) return v;
  return parent[v] = find_parent(parent[v]);
}
void unite(int a, int b) {
  a = find_parent(a);
  b = find_parent(b);
  if (a == b) return;
  if (rand() & 1) swap(a, b);
  parent[a] = b;
}
int depth[N];
vector<int> g2[N];
int ti[N], tout[N], up[N][L];
bool upper(int a, int b) { return ti[a] <= ti[b] && tout[a] >= tout[b]; }
int lca(int a, int b) {
  if (upper(a, b)) return a;
  if (upper(b, a)) return b;
  for (int i = L - 1; i >= 0; i--) {
    if (up[a][i] > 0 && !upper(up[a][i], b)) a = up[a][i];
  }
  return up[a][0];
}
void dfs2(int v, int p = -1, int lvl = 1) {
  ti[v] = ++timer;
  depth[v] = lvl;
  up[v][0] = p;
  for (int i = 1; i < L; i++) up[v][i] = up[up[v][i - 1]][i - 1];
  for (int i = 0; i < (int)g2[v].size(); i++) {
    if (g2[v][i] != p) dfs2(g2[v][i], v, lvl + 1);
  }
  tout[v] = ++timer;
}
int n, m, deg[N];
int u[N], v[N], q, l, a, b, x, y;
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &u[i], &v[i]);
    g[u[i]].push_back(v[i]);
    g[v[i]].push_back(u[i]);
  }
  dfs(1);
  for (int i = 1; i <= n; i++) parent[i] = i;
  for (int i = 1; i <= m; i++) {
    if (bridge(u[i], v[i])) {
      continue;
    }
    unite(u[i], v[i]);
  }
  for (int i = 1; i <= m; i++) {
    if (!bridge(u[i], v[i])) continue;
    x = find_parent(u[i]);
    y = find_parent(v[i]);
    g2[x].push_back(y);
    g2[y].push_back(x);
    deg[x]++;
    deg[y]++;
  }
  timer = 0;
  for (int i = 1; i <= n; i++)
    if (deg[i] == 1) {
      dfs2(i);
      break;
    }
  scanf("%d", &q);
  while (q--) {
    scanf("%d %d", &a, &b);
    a = find_parent(a);
    b = find_parent(b);
    if (a == b) {
      printf("0\n");
    } else {
      l = lca(a, b);
      printf("%d\n", depth[a] + depth[b] - 2 * depth[l]);
    }
  }
  return 0;
}
