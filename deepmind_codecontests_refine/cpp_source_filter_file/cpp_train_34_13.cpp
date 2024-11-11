#include <bits/stdc++.h>
using namespace std;
struct apple {
  int v, nxt;
} edge[3011 * 4];
double ans;
int n, len, indexx[3011], a[3011], cir[3011], belong[3011], fa[3011][20 + 1],
    tot, vist[3011], rt, deep[3011];
void addedge(int x, int y) {
  edge[++tot].v = y;
  edge[tot].nxt = indexx[x];
  indexx[x] = tot;
}
int find_cir(int u, int pre) {
  if (vist[u]) {
    rt = u;
    return 2;
  }
  vist[u] = 1;
  int t = indexx[u], vv;
  while (t) {
    vv = edge[t].v;
    if (t != ((pre - 1) ^ 1) + 1) {
      int k = find_cir(vv, t);
      if (k == 2) {
        a[++len] = u;
        cir[u] = 1;
        if (u == rt) return 1;
        return 2;
      } else if (k == 1)
        return 1;
    }
    t = edge[t].nxt;
  }
  return 0;
}
void dfs(int u, int Fa, int anc, int dep) {
  belong[u] = anc;
  deep[u] = dep;
  fa[u][0] = Fa;
  int t = indexx[u], vv;
  while (t) {
    vv = edge[t].v;
    if (vv != Fa && !cir[vv]) {
      dfs(vv, u, anc, dep + 1);
    }
    t = edge[t].nxt;
  }
}
int lca(int x, int y) {
  if (deep[x] < deep[y]) swap(x, y);
  for (int i = 20; i >= 0; i--) {
    if (deep[fa[x][i]] >= deep[y]) x = fa[x][i];
  }
  if (x == y) return x;
  int ret = 0;
  for (int i = 20; i >= 0; i--) {
    if (fa[x][i] == fa[y][i])
      ret = fa[x][i];
    else
      x = fa[x][i], y = fa[y][i];
  }
  return ret;
}
void solve() {
  int x, y, z;
  for (int i = 1; i <= len; i++) {
    dfs(a[i], 0, i, 0);
  }
  for (int i = 1; i <= 20; i++) {
    for (int j = 1; j <= n; j++) fa[j][i] = fa[fa[j][i - 1]][i - 1];
  }
  ans = n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      if (belong[i] == belong[j]) {
        x = deep[i] + deep[j] - deep[lca(i, j)] + 1;
        ans += (1 / (double)x);
      } else {
        x = deep[i] + deep[j] + 2;
        y = abs(belong[i] - belong[j]) - 1;
        z = len - y - 2;
        ans += (1.0 / (x + y) + 1.0 / (x + z) - 1.0 / (x + y + z));
      }
    }
  }
}
int main() {
  int x, y;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &x, &y);
    x++, y++;
    addedge(x, y);
    addedge(y, x);
  }
  find_cir(1, 0);
  solve();
  printf("%lf", ans);
  return 0;
}
