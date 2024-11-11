#include <bits/stdc++.h>
using std ::max;
inline int geti() {
  int x = 0, c = getchar();
  while (!isdigit(c)) c = getchar();
  for (; isdigit(c); c = getchar()) x = x * 10 + (c & 15);
  return x;
}
const int N = 400005;
int n, hd[N], cnt, fa[N], siz[N], f[N], g[N], h[N];
struct edge {
  int to, nxt;
} e[N << 1];
void adde(int u, int v) {
  e[++cnt].to = v;
  e[cnt].nxt = hd[u];
  hd[u] = cnt;
  e[++cnt].to = u;
  e[cnt].nxt = hd[v];
  hd[v] = cnt;
}
void update(int x, int u) {
  if (x > f[u]) {
    g[u] = f[u];
    f[u] = x;
  } else
    g[u] = max(g[u], x);
}
void dfs1(int u) {
  siz[u] = 1;
  for (int i = hd[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (v == fa[u]) continue;
    fa[v] = u;
    dfs1(v);
    siz[u] += siz[v];
    if (siz[v] > siz[h[u]]) h[u] = v;
    if (siz[v] <= (n >> 1)) {
      update(siz[v], u);
    } else
      update(f[v], u);
  }
  if (n - siz[u] > siz[h[u]]) h[u] = fa[u];
}
void dfs2(int u) {
  if (n - siz[u] <= (n >> 1)) {
    update(n - siz[u], u);
  } else if (f[fa[u]] == siz[u]) {
    update(g[fa[u]], u);
  } else
    update(f[fa[u]], u);
  for (int i = hd[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (v == fa[u]) continue;
    dfs2(v);
  }
}
int main() {
  n = geti();
  for (int i = 1; i <= n - 1; ++i) {
    int u = geti(), v = geti();
    adde(u, v);
  }
  dfs1(1);
  dfs2(1);
  for (int u = 1; u <= n; ++u) {
    if (h[u] == fa[u]) {
      if (n - siz[u] <= (n >> 1))
        printf("1 ");
      else if (f[fa[u]] == siz[u]) {
        if (n - siz[u] - g[fa[u]] <= (n >> 1))
          printf("1 ");
        else
          printf("0 ");
      } else if (n - siz[u] - f[fa[u]] <= (n >> 1))
        printf("1 ");
      else
        printf("0 ");
    } else if (siz[h[u]] <= (n >> 1))
      printf("1 ");
    else if (f[h[u]] == n - siz[h[u]]) {
      if (siz[h[u]] - g[h[u]] <= (n >> 1))
        printf("1 ");
      else
        printf("0 ");
    } else if (siz[h[u]] - f[h[u]] <= (n >> 1))
      printf("1 ");
    else
      printf("0 ");
  }
  puts("");
  return 0;
}
