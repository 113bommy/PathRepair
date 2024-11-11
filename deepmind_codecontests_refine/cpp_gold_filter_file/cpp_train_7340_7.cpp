#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, m, tot, tim, f[N], a[N], stk[N], head[N], fa[N], d[N], siz[N], son[N],
    top[N], dfn[N];
bool v[N];
vector<int> re[N];
struct Edge {
  int suiv, ver;
} e[N << 1];
inline bool cmp(const int& p, const int& q) { return dfn[p] < dfn[q]; }
inline void lnk(int x, int y) {
  e[++tot].ver = y;
  e[tot].suiv = head[x];
  head[x] = tot;
}
inline void dfs1(int x, int maxson = -1) {
  dfn[x] = ++tim;
  d[x] = d[fa[x]] + 1;
  siz[x] = 1;
  for (int i = 0; i < re[x].size(); i++) {
    int y = re[x][i];
    if (y == fa[x]) continue;
    fa[y] = x;
    dfs1(y);
    siz[x] += siz[y];
    if (siz[y] > maxson) maxson = siz[y], son[x] = y;
  }
}
inline void dfs2(int x, int acro) {
  top[x] = acro;
  if (son[x]) dfs2(son[x], acro);
  for (int i = 0; i < re[x].size(); i++) {
    int y = re[x][i];
    if (y == fa[x] || y == son[x]) continue;
    dfs2(y, y);
  }
}
inline int lca(int x, int y) {
  while (top[x] ^ top[y])
    d[top[x]] > d[top[y]] ? x = fa[top[x]] : y = fa[top[y]];
  return d[x] < d[y] ? x : y;
}
inline void build(int k) {
  tot = 0;
  int top = 0;
  sort(a + 1, a + 1 + k, cmp);
  stk[top = 1] = 1, head[1] = 0;
  for (int i = 1; i <= k; i++) {
    if (a[i] == 1) continue;
    int x = lca(stk[top], a[i]);
    if (stk[top] != x) {
      while (top > 1 && dfn[stk[top - 1]] > dfn[x])
        lnk(stk[top - 1], stk[top]), top--;
      if (dfn[stk[top - 1]] != dfn[x])
        head[x] = 0, lnk(x, stk[top]), stk[top] = x;
      else
        lnk(x, stk[top--]);
    }
    head[a[i]] = 0;
    stk[++top] = a[i];
  }
  for (int i = 1; i < top; i++) lnk(stk[i], stk[i + 1]);
}
inline void dfs3(int x, int fa) {
  siz[x] = f[x] = 0;
  for (int i = head[x]; i; i = e[i].suiv) {
    int y = e[i].ver;
    if (y == fa) continue;
    dfs3(y, x);
    f[x] += f[y], siz[x] += siz[y];
  }
  if (v[x])
    f[x] += siz[x], siz[x] = 1;
  else if (siz[x] > 1)
    f[x]++, siz[x] = 0;
}
int main() {
  scanf("%d", &n);
  for (int i = 1, x, y; i < n; i++)
    scanf("%d%d", &x, &y), re[x].push_back(y), re[y].push_back(x);
  dfs1(1), dfs2(1, 1);
  scanf("%d", &m);
  while (m--) {
    int k, fg = 0;
    scanf("%d", &k);
    for (int i = 1; i <= k; i++) scanf("%d", &a[i]), v[a[i]] = 1;
    for (int i = 1; i <= k; i++)
      if (v[fa[a[i]]]) {
        puts("-1");
        fg = 1;
        break;
      }
    if (fg) {
      for (int i = 1; i <= k; i++) v[a[i]] = 0;
      continue;
    }
    build(k);
    dfs3(1, 1);
    printf("%d\n", f[1]);
    for (int i = 1; i <= k; i++) v[a[i]] = 0;
  }
  return 0;
}
