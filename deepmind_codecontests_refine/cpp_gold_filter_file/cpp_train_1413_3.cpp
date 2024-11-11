#include <bits/stdc++.h>
using namespace std;
int n, x, ans[500005], tw[25];
char opt[5];
void ckmax(int &x, int y) { x = (x > y) ? x : y; }
struct edge {
  int nxt, v, vo;
  edge() {}
  edge(int A, int B, int C) : nxt(A), v(B), vo(C) {}
} e[500005];
int tot, fr[500005], sz[500005], son[500005], t[500005], vc[500005], xo[500005];
int cnt, dep[500005], cdp[500005], dfn[500005], rin[500005], in[500005],
    out[500005], lst[500005];
int c[(1 << 22) + 5], c2[(1 << 22) + 5];
void add(int x, int y, int z) {
  ++tot;
  e[tot] = edge(fr[x], y, z), fr[x] = tot;
}
void dfs(int u) {
  sz[u] = 1;
  int mx = -1;
  for (int i = fr[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    cdp[v] = cdp[u] ^ (1 << e[i].vo);
    dep[v] = dep[u] + 1;
    dfs(v);
    sz[u] += sz[v];
    if (sz[v] > mx) son[u] = v, mx = sz[v], vc[u] = 1 << e[i].vo;
  }
}
void dfs2(int u, int tp) {
  dfn[++cnt] = u;
  in[u] = cnt;
  t[u] = tp;
  if (!son[u]) {
    rin[u] = cnt + 1;
    out[u] = cnt;
    return;
  }
  dfs2(son[u], tp);
  rin[u] = cnt + 1;
  xo[u] = xo[son[u]] ^ vc[u];
  for (int i = fr[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if (v == son[u]) continue;
    dfs2(v, v);
  }
  out[u] = cnt;
}
void calc(int u, int x, int d1, int d2) {
  for (int i = 0; i <= 22; ++i)
    if (c[x ^ tw[i]]) ckmax(ans[u], c[x ^ tw[i]] + d1 - (d2 << 1));
}
void calc2(int u, int x, int d1, int d2) {
  for (int i = 0; i <= 22; ++i)
    if (c2[x ^ tw[i]]) ckmax(ans[u], c2[x ^ tw[i]] + d1 - (d2 << 1));
}
void solve(int u) {
  if (!son[u]) {
    if (t[u] == u) return;
    ++c[0];
  }
  for (int i = fr[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if (v == son[u]) continue;
    solve(v);
    ckmax(ans[u], ans[v]);
  }
  solve(son[u]), ckmax(ans[u], ans[son[u]]);
  c2[0] = dep[u];
  for (int i = fr[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if (v == son[u]) continue;
    for (int j = in[v]; j <= out[v]; ++j)
      calc2(u, cdp[dfn[j]] ^ cdp[u], dep[dfn[j]], dep[u]);
    for (int j = in[v]; j <= out[v]; ++j)
      ckmax(c2[cdp[dfn[j]] ^ cdp[u]], dep[dfn[j]]);
  }
  c2[0] = 0;
  for (int i = fr[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if (v == son[u]) continue;
    for (int j = in[v]; j <= out[v]; ++j) c2[cdp[dfn[j]] ^ cdp[u]] = 0;
  }
  for (int i = rin[u]; i <= out[u]; ++i)
    calc(u, cdp[dfn[i]] ^ cdp[u] ^ xo[u], dep[dfn[i]], dep[u]);
  calc(u, xo[u], dep[u], dep[u]);
  for (int i = rin[u]; i <= out[u]; ++i)
    lst[dfn[i]] = xo[u] ^ cdp[dfn[i]] ^ cdp[u],
    ckmax(c[lst[dfn[i]]], dep[dfn[i]]);
  lst[u] = xo[u], ckmax(c[lst[u]], dep[u]);
  if (t[u] == u) {
    for (int i = in[u]; i <= out[u]; ++i) c[lst[dfn[i]]] = 0;
  }
}
int main() {
  tw[0] = 0;
  for (int i = 1; i <= 22; ++i) tw[i] = 1 << i - 1;
  scanf("%d", &n);
  for (int i = 2; i <= n; ++i) {
    scanf("%d", &x);
    scanf("%s", opt);
    add(x, i, opt[0] - 'a');
  }
  dep[1] = 1, dfs(1);
  dfs2(1, 1);
  solve(1);
  for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
  putchar('\n');
  return 0;
}
