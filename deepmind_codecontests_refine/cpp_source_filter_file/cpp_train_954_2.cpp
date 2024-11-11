#include <bits/stdc++.h>
using namespace std;
int n, k;
struct Edge {
  int v, nxt;
} e[400010];
int tot;
int first[200010];
void build(int u, int v) {
  e[++tot] = (Edge){v, first[u]};
  first[u] = tot;
  return;
}
int f[200010], g[200010], h[200010];
void solve1(int u, int lst) {
  f[u] = 0;
  g[u] = -1e9;
  for (int i = first[u]; i; i = e[i].nxt)
    if (e[i].v != lst) {
      solve1(e[i].v, u);
      if (f[e[i].v] + 1 > f[u]) {
        g[u] = f[u];
        f[u] = f[e[i].v] + 1;
      } else
        g[u] = max(g[u], f[e[i].v] + 1);
    }
  return;
}
void solve2(int u, int lst) {
  if (!lst)
    h[u] = -1e9;
  else {
    int val = f[lst];
    if (f[lst] == f[u] + 1) val = g[lst];
    h[u] = max(val, h[lst]) + 1;
  }
  int mx = h[u], mmx = -1e9, mmmx = -1e9;
  for (int i = first[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if (v == lst) continue;
    solve2(v, u);
    if (f[v] + 1 > mx) {
      mmmx = mmx;
      mmx = mx;
      mx = f[v] + 1;
    } else if (f[v] + 1 > mmx) {
      mmmx = mmx;
      mmx = f[v] + 1;
    } else
      mmmx = max(mmmx, f[v] + 1);
  }
  if (mmmx + mmx >= k - 1) {
    printf("No\n");
    exit(0);
  }
  return;
}
int dis[200010];
int fa[200010];
void dfs(int u, int lst, int& S) {
  fa[u] = lst;
  dis[u] = dis[lst] + 1;
  if (dis[u] > dis[S]) S = u;
  for (int i = first[u]; i; i = e[i].nxt)
    if (e[i].v != lst) dfs(e[i].v, u, S);
  return;
}
int col[200010];
void dfs1(int u, int now) {
  col[u] = now;
  for (int i = first[u]; i; i = e[i].nxt)
    if (!col[e[i].v]) {
      int tnow = now - 1;
      if (!tnow) tnow = k;
      dfs1(e[i].v, tnow);
    }
  return;
}
void dfs2(int u, int now) {
  col[u] = now;
  for (int i = first[u]; i; i = e[i].nxt)
    if (!col[e[i].v]) {
      int tnow = now + 1;
      if (tnow > k) tnow -= k;
      dfs2(e[i].v, tnow);
    }
  return;
}
int p[200010];
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    build(u, v);
    build(v, u);
  }
  if (k > 2) {
    solve1(1, 0);
    solve2(1, 0);
  }
  int S = 0, T = 0;
  dfs(1, 0, S);
  dfs(S, 0, T);
  int N = 0;
  int u = T;
  while (u != S) {
    p[++N] = u;
    u = fa[u];
  }
  p[++N] = T;
  col[p[N / 2]] = 1;
  col[p[N / 2 + 1]] = 2;
  dfs1(p[N / 2], 1);
  dfs2(p[N / 2 + 1], 2);
  printf("Yes\n");
  for (int i = 1; i <= n; i++) printf("%d ", col[i]);
  printf("\n");
  return 0;
}
