#include <bits/stdc++.h>
using namespace std;
const int N = 100010, mod = 1000000007;
int n, q, k, m, r, a[N], fa[N][17], dep[N], hd[N],
    o = 1, bin[20], h[N], f[N][310], st[N], ed[N], c[N], vis[N], idx;
struct Edge {
  int v, nt;
} E[N << 1];
char gc() {
  static char *p1, *p2, s[1000000];
  if (p1 == p2) p2 = (p1 = s) + fread(s, 1, 1000000, stdin);
  return (p1 == p2) ? EOF : *p1++;
}
int rd() {
  int x = 0;
  char c = gc();
  while (c < '0' || c > '9') c = gc();
  while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + c - '0', c = gc();
  return x;
}
void adde(int u, int v) {
  E[o] = (Edge){v, hd[u]};
  hd[u] = o++;
  E[o] = (Edge){u, hd[v]};
  hd[v] = o++;
}
void dfs(int u, int F) {
  st[u] = ++idx;
  fa[u][0] = F;
  dep[u] = dep[F] + 1;
  for (int i = 1; bin[i] < dep[u]; ++i) fa[u][i] = fa[fa[u][i - 1]][i - 1];
  for (int i = hd[u]; i; i = E[i].nt) {
    int v = E[i].v;
    if (v == F) continue;
    dfs(v, u);
  }
  ed[u] = idx;
}
int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (int i = 0; i < 17; ++i)
    if (bin[i] & (dep[u] - dep[v])) u = fa[u][i];
  if (u == v) return u;
  for (int i = 16; ~i; --i)
    if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
  return fa[u][0];
}
void add(int x, int y) {
  for (; x <= n; x += x & -x) c[x] += y;
}
int ask(int x) {
  int re = 0;
  for (; x; x -= x & -x) re += c[x];
  return re;
}
void update(int u, int x) {
  vis[u] += x;
  add(st[u], x);
  add(ed[u] + 1, -x);
}
int query(int u) {
  int t = lca(u, r);
  return ask(st[u]) + ask(st[r]) - ask(st[t]) * 2 + vis[t];
}
int main() {
  n = rd();
  q = rd();
  for (int i = bin[0] = 1; i <= 16; ++i) bin[i] = bin[i - 1] << 1;
  for (int i = 1; i < n; ++i) adde(rd(), rd());
  dfs(1, 0);
  f[0][0] = 1;
  for (int i = 1; i <= q; ++i) {
    k = rd();
    m = rd();
    r = rd();
    for (int j = 1; j <= k; ++j) a[j] = rd(), update(a[j], 1);
    for (int j = 1; j <= k; ++j) h[j] = query(a[j]) - 1;
    sort(h + 1, h + k + 1);
    for (int j = 1; j <= k; ++j)
      for (int l = 1; l <= m; ++l) {
        f[j][l] = ((long long)f[j - 1][l] * max(0, l - h[j]) % mod +
                   f[j - 1][l - 1]) %
                  mod;
      }
    int ans = 0;
    for (int l = 0; l <= m; ++l) ans = (ans + f[k][l]) % mod;
    printf("%d\n", ans);
    for (int j = 1; j <= k; ++j) update(a[j], -1);
  }
  return 0;
}
