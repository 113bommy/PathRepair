#include <bits/stdc++.h>
using namespace std;
const int maxx = 1e5 + 1;
const int maxm = 1e6 + 1;
int n, m;
struct ha {
  int f, t, d, id;
} es[maxm];
ha cc[maxm];
int tot = 0, first[maxm], Next[maxm];
void build(int f, int t, int d) {
  es[++tot] = (ha){f, t, d};
  Next[tot] = first[f];
  first[f] = tot;
}
int cp(ha x, ha y) { return x.d < y.d; }
bool cp2(ha x, ha y) { return x.id < y.id; }
int fax[maxx];
int find(int x) {
  if (fax[x] == x)
    return x;
  else
    return fax[x] = find(fax[x]);
}
bool Use[maxm];
void Krus() {
  for (int i = 1; i <= n; i++) fax[i] = i;
  sort(cc + 1, cc + 1 + m, cp);
  for (int i = 1; i <= m; i++) {
    int x = cc[i].f, y = cc[i].t;
    if (find(x) != find(y)) {
      fax[find(x)] = find(y);
      build(cc[i].f, cc[i].t, cc[i].d);
      build(cc[i].t, cc[i].f, cc[i].d);
      Use[cc[i].id] = true;
    }
  }
}
int fa[maxx][30], sd[maxx], dis[maxx][30];
void dfs(int x) {
  for (int i = first[x]; i != 0; i = Next[i]) {
    int v = es[i].t;
    if (sd[v] == 0) {
      sd[v] = sd[x] + 1;
      fa[v][0] = x;
      dis[v][0] = es[i].d;
      for (int i = 1; i <= 25; i++) {
        fa[v][i] = fa[fa[v][i - 1]][i - 1];
        dis[v][i] = max(dis[v][i - 1], dis[fa[v][i - 1]][i - 1]);
      }
      dfs(v);
    }
  }
}
int lca(int u, int v) {
  int Max = 0;
  if (sd[u] > sd[v]) swap(u, v);
  int tt = sd[v] - sd[u];
  for (int i = 0; i <= 25; i++) {
    if ((tt >> i) & 1 == 1) {
      Max = max(Max, dis[v][i]);
      v = fa[v][i];
    }
  }
  for (int i = 25; i >= 0; i--) {
    if (fa[u][i] != fa[v][i]) {
      Max = max(Max, dis[v][i]);
      Max = max(Max, dis[u][i]);
      u = fa[u][i];
      v = fa[v][i];
    }
  }
  if (u != v) {
    Max = max(Max, dis[u][0]);
    Max = max(Max, dis[v][0]);
  }
  return Max;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++)
    scanf("%d%d%d", &cc[i].f, &cc[i].t, &cc[i].d), cc[i].id = i;
  Krus();
  for (int i = 1; i <= n; i++) {
    if (sd[i] == 0) {
      sd[i] = 1;
      dfs(i);
    }
  }
  sort(cc + 1, cc + n + 1, cp2);
  for (int i = 1; i <= m; ++i) {
    if (!Use[i]) printf("%d\n", lca(cc[i].f, cc[i].t));
  }
  return 0;
}
