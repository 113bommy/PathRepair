#include <bits/stdc++.h>
using namespace std;
const int nmax = 100010;
int n, m, u, v, level[nmax], anc[20][nmax], sub[nmax];
long long spdown[nmax], sproot[nmax], sumdown[nmax];
bool used[nmax];
vector<int> g[nmax];
void dfsdown(int node, int father) {
  used[node] = 1;
  level[node] = level[father] + 1;
  anc[0][node] = father;
  sub[node] = 1;
  spdown[node] = 0;
  for (int vec : g[node])
    if (!used[vec]) {
      dfsdown(vec, node);
      sub[node] += sub[vec];
      spdown[node] += spdown[vec];
    }
  spdown[node] += sub[node];
}
void dfsroot(int node) {
  used[node] = 1;
  for (int vec : g[node])
    if (!used[vec]) {
      sproot[vec] = sumdown[vec] + sub[vec] + sproot[node] - spdown[vec] -
                    sub[vec] + n - sub[vec];
      dfsroot(vec);
    }
}
void buildAnc() {
  for (int i = 1; (1 << i) <= n; ++i)
    for (int j = 1; j <= n; ++j) anc[i][j] = anc[i - 1][anc[i - 1][j]];
}
int getLCA(int x, int y) {
  if (level[x] < level[y]) swap(x, y);
  for (int i = 19; i >= 0; --i)
    if (level[x] - (1 << i) >= level[y]) x = anc[i][x];
  if (x == y) return x;
  for (int i = 19; i >= 0; --i)
    if (anc[i][x] && anc[i][x] != anc[i][y]) x = anc[i][x], y = anc[i][y];
  return anc[0][x];
}
int getKth(int node, int k) {
  for (int i = 0; i <= 19; ++i)
    if (k & (1 << i)) node = anc[i][node];
  return node;
}
int main() {
  scanf("%i %i", &n, &m);
  for (int i = 1; i < n; ++i) {
    scanf("%i %i", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfsdown(1, 0);
  for (int i = 1; i <= n; ++i) used[i] = 0;
  for (int i = 1; i <= n; ++i)
    for (int vec : g[i])
      if (level[vec] == level[i] + 1) sumdown[i] += spdown[vec];
  sproot[1] = sumdown[1] + sub[1];
  dfsroot(1);
  buildAnc();
  for (int i = 1; i <= m; ++i) {
    scanf("%i %i", &u, &v);
    int lca = getLCA(u, v);
    if (level[u] > level[v]) swap(u, v);
    if (lca == u) {
      int l = level[v] - level[u];
      int f = getKth(v, l - 1);
      printf("%.10f\n",
             l - 1 + 1.0 * spdown[v] / sub[v] +
                 1.0 * (sproot[u] - spdown[f] - sub[f]) / (n - sub[f]));
    } else {
      int l = level[v] + level[u] - 2 * level[lca];
      printf("%.10f\n",
             l - 1 + 1.0 * spdown[v] / sub[v] + 1.0 * spdown[u] / sub[u]);
    }
  }
}
