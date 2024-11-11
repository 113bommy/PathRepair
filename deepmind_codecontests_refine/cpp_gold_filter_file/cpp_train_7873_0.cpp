#include <bits/stdc++.h>
using namespace std;
struct edge {
  int v, nxt;
} e[500005];
int n, h[100005], t, deg[100005], vis[100005], vis2[100005];
int a[100005], b[100005], at, bt, m, tans[100005], d[100005];
int g[15][15], g2[15][15], p[15], pvis[15], tfl;
void add(int u, int v) {
  e[++t].v = v;
  e[t].nxt = h[u];
  h[u] = t;
}
void link(int u, int v) {
  tans[u] = v;
  vis[u] = vis[v] = 1;
}
void dfs(int u, int fa, int dep) {
  d[u] = dep;
  for (int i = h[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if (v == fa || vis[v]) continue;
    dfs(v, u, dep + 1);
  }
}
void tdfs(int dep) {
  if (dep == m + 1) {
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= m; j++)
        if (g[i][j] && g2[p[i]][p[j]]) return;
    tfl = 1;
    return;
  }
  for (int i = 1; i <= m; i++)
    if (!pvis[i]) {
      pvis[i] = 1;
      p[dep] = i;
      tdfs(dep + 1);
      if (tfl) return;
      pvis[i] = 0;
    }
}
void findlf(int fl, int &u, int &v, int &fu, int &fv) {
  int mx = 0, id = 0;
  for (int i = fl + 1; i <= fl + n; i++) {
    if (deg[i] > mx) {
      mx = deg[i];
      id = i;
    }
  }
  if (mx < m - 3) {
    for (int i = fl + 1; i <= fl + n; i++)
      if (!vis[i] && deg[i] == 1) {
        u = i;
        break;
      }
  } else {
    dfs(id, 0, 1);
    for (int i = fl + 1; i <= fl + n; i++)
      if (!vis[i] && deg[i] == 1 && d[i] == 2) {
        u = i;
        break;
      }
  }
  dfs(u, 0, 1);
  for (int i = fl + 1; i <= fl + n; i++) {
    if (!vis[i] && deg[i] == 1 && d[i] > 3) v = i;
    if (!vis[i] && d[i] == 2) fu = i;
  }
  for (int i = h[v]; i; i = e[i].nxt) {
    int nw = e[i].v;
    if (vis[nw]) continue;
    fv = nw;
  }
}
void solve() {
  if (m <= 7) {
    at = bt = 0;
    for (int i = 1; i <= n; i++)
      if (!vis[i]) a[++at] = i;
    for (int i = 1; i <= at; i++) {
      int u = a[i];
      for (int j = h[u]; j; j = e[j].nxt) {
        int v = e[j].v;
        if (vis[v]) continue;
        for (int k = 1; k <= at; k++)
          if (v == a[k]) g[i][k] = 1;
      }
    }
    for (int i = n + 1; i <= 2 * n; i++)
      if (!vis[i]) b[++bt] = i;
    for (int i = 1; i <= bt; i++) {
      int u = b[i];
      for (int j = h[u]; j; j = e[j].nxt) {
        int v = e[j].v;
        if (vis[v]) continue;
        for (int k = 1; k <= bt; k++)
          if (v == b[k]) g2[i][k] = 1;
      }
    }
    tdfs(1);
    for (int i = 1; i <= at; i++) link(a[i], b[p[i]]);
    return;
  }
  int id = 0;
  for (int i = 1; i <= 2 * n; i++) {
    if (vis[i]) continue;
    if (deg[i] == m - 2) id = i;
  }
  if (id) {
    int fl = 0;
    dfs(id, 0, 1);
    if (id > n) fl += n;
    int u = 0, v = 0;
    for (int i = fl + 1; i <= fl + n; i++) {
      if (vis[i]) continue;
      if (d[i] == 3) u = i;
    }
    for (int i = h[u]; i; i = e[i].nxt) {
      int nw = e[i].v;
      if (vis[nw]) continue;
      v = nw;
    }
    int id2 = 0, u2 = 0, v2 = 0;
    if (fl == 0)
      fl = n;
    else
      fl = 0;
    for (int i = fl + 1; i <= fl + n; i++)
      if (!vis[i] && deg[i] == 1) {
        id2 = i;
        break;
      }
    for (int i = h[id2]; i; i = e[i].nxt) {
      int nw = e[i].v;
      if (vis[nw]) continue;
      u2 = nw;
    }
    vis2[u2] = 1;
    for (int i = h[u2]; i; i = e[i].nxt) {
      int nw = e[i].v;
      if (vis[nw]) continue;
      vis2[nw] = 1;
    }
    for (int i = fl + 1; i <= fl + n; i++)
      if (!vis[i] && !vis2[i]) v2 = i;
    if (u < u2)
      link(u, u2), link(v, v2), link(id, id2);
    else
      link(u2, u), link(v2, v), link(id2, id);
    at = bt = 0;
    for (int i = 1; i <= n; i++)
      if (!vis[i]) a[++at] = i;
    for (int i = n + 1; i <= 2 * n; i++)
      if (!vis[i]) b[++bt] = i;
    for (int i = 1; i <= at; i++) link(a[i], b[i]);
    return;
  }
  if (!id) {
    int u = 0, v = 0, fu, fv, u2 = 0, v2 = 0, fu2, fv2;
    findlf(0, u, v, fu, fv);
    findlf(n, u2, v2, fu2, fv2);
    vis[u] = vis[v] = vis[u2] = vis[v2] = 1;
    m -= 2;
    deg[fu]--, deg[fv]--, deg[fu2]--, deg[fv2]--;
    solve();
    if (tans[fu] == fu2 || tans[fv] == fv2)
      link(u, v2), link(v, u2);
    else
      link(u, u2), link(v, v2);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= 2 * n - 2; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    add(u, v);
    add(v, u);
    deg[u]++, deg[v]++;
  }
  for (int i = 1; i <= 2 * n; i++)
    if (deg[i] == n - 1) {
      printf("No\n");
      return 0;
    }
  m = n;
  solve();
  printf("Yes\n");
  for (int i = 1; i <= n; i++) printf("%d ", tans[i]);
  return 0;
}
