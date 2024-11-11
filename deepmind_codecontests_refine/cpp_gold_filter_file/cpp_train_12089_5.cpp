#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4e5 + 5;
char buf[1 << 12], *pp1 = buf, *pp2 = buf, nc;
int ny;
inline char gc() { return getchar(); }
inline int read() {
  int x = 0;
  for (ny = 1; nc = gc(), (nc < 48 || nc > 57) && nc != EOF;)
    if (nc == 45) ny = -1;
  if (nc < 0) return nc;
  for (x = nc - 48; nc = gc(), 47 < nc && nc < 58 && nc != EOF;
       x = (x << 3) + (x << 1) + (nc ^ 48))
    ;
  return x * ny;
}
int n, m;
char s[MAXN];
int fa[MAXN], ch[26][MAXN], len[MAXN], tot = 1, last = 1, pos[MAXN];
inline void insert(int c) {
  int p = last, np = last = ++tot;
  len[np] = len[p] + 1;
  for (; p && !ch[c][p]; ch[c][p] = np, p = fa[p])
    ;
  if (!p) {
    fa[np] = 1;
    return;
  }
  int q = ch[c][p];
  if (len[q] == len[p] + 1) {
    fa[np] = q;
    return;
  }
  int nq = ++tot;
  for (int c = 0; c <= 25; c++) ch[c][nq] = ch[c][q];
  fa[nq] = fa[q], len[nq] = len[p] + 1, fa[np] = fa[q] = nq;
  for (; p && ch[c][p] == q; ch[c][p] = nq, p = fa[p])
    ;
}
int w[MAXN], sz[MAXN], top[MAXN], d[MAXN], dfn[MAXN], tim;
vector<int> G[MAXN];
void dfs(int x) {
  sz[x] = 1, d[x] = d[fa[x]] + 1;
  for (auto y : G[x]) dfs(y), sz[x] += sz[y], sz[y] > sz[w[x]] ? w[x] = y : 0;
}
void dfs1(int x, int tp) {
  top[x] = tp, dfn[x] = ++tim;
  if (w[x]) dfs1(w[x], tp);
  for (auto y : G[x])
    if (y != w[x]) dfs1(y, y);
}
inline int lca(int x, int y) {
  for (; top[x] != top[y]; x = fa[top[x]])
    if (d[top[x]] < d[top[y]]) swap(x, y);
  return d[x] < d[y] ? x : y;
}
int p1[MAXN], p2[MAXN], p[MAXN << 1], sz1[MAXN], sz2[MAXN], cnt;
inline void add(int x, int y) { G[x].push_back(y), G[y].push_back(x); }
long long ans;
void dfs2(int x, int fa) {
  ans += len[x] * sz1[x] * sz2[x];
  for (auto y : G[x])
    if (y != fa)
      dfs2(y, x), ans += 1ll * (sz1[x] * sz2[y] + sz2[x] * sz1[y]) * len[x],
          sz1[x] += sz1[y], sz2[x] += sz2[y];
}
int main() {
  n = read(), m = read(), scanf("%s", s + 1);
  for (int i = n; i >= 1; i--) insert(s[i] - 'a'), pos[i] = last;
  for (int i = 2; i <= tot; i++) G[fa[i]].push_back(i);
  dfs(1), dfs1(1, 1);
  for (int i = 1; i <= tot; i++) G[i].clear();
  for (int i = 1; i <= m; i++) {
    int k1 = read(), k2 = read();
    cnt = 0, ans = 0;
    for (int j = 1; j <= k1; j++)
      p1[j] = pos[read()], p[++cnt] = p1[j], sz1[p1[j]] = 1;
    for (int j = 1; j <= k2; j++)
      p2[j] = pos[read()], p[++cnt] = p2[j], sz2[p2[j]] = 1;
    p[++cnt] = 1;
    sort(p + 1, p + cnt + 1, [](int x, int y) { return dfn[x] < dfn[y]; }),
        cnt = unique(p + 1, p + cnt + 1) - p - 1;
    for (int i = cnt; i >= 2; i--) p[++cnt] = lca(p[i], p[i - 1]);
    sort(p + 1, p + cnt + 1, [](int x, int y) { return dfn[x] < dfn[y]; });
    cnt = unique(p + 1, p + cnt + 1) - p - 1;
    static int top, stk[MAXN];
    top = 0;
    for (int j = 1; j <= cnt; j++) {
      int x = p[j];
      for (; top && dfn[x] >= dfn[stk[top]] + sz[stk[top]]; top--)
        ;
      if (top) add(stk[top], x);
      stk[++top] = x;
    }
    ans = 0, dfs2(p[1], 0), cout << ans << "\n";
    for (int j = 1; j <= cnt; j++)
      G[p[j]].clear(), sz1[p[j]] = sz2[p[j]] = 0, p[j] = 0;
  }
  return 0;
}
