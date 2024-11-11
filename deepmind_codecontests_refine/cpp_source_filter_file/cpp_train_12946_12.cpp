#include <bits/stdc++.h>
using namespace std;
int lst[100005], to[100005], pre[100005], tot;
int fa[100005][25], dep[100005], num[100005];
int rt[100005], lson[3000005], rson[3000005], sum[3000005], t_cnt;
int st[100005], en[100005], t;
inline void add_edge(int u, int v) {
  to[tot] = v;
  pre[tot] = lst[u];
  lst[u] = tot++;
}
void dfs(int u) {
  st[u] = t++;
  for (int i = 1; i < 20; i++)
    fa[u][i] = fa[u][i - 1] == -1 ? -1 : fa[fa[u][i - 1]][i - 1];
  for (int i = lst[u]; ~i; i = pre[i]) {
    fa[to[i]][0] = u;
    dep[to[i]] = dep[u] + 1;
    dfs(to[i]);
  }
  en[u] = t - 1;
}
inline int lca(int u, int v) {
  if (dep[u] > dep[v]) swap(u, v);
  for (int i = 0; i < 20; i++) {
    if (dep[v] - dep[u] & (1 << i)) v = fa[v][i];
  }
  if (u == v) return u;
  for (int i = 19; i >= 0; i--) {
    if (fa[u][i] != fa[v][i]) {
      u = fa[u][i];
      v = fa[v][i];
    }
  }
  return fa[u][0];
}
void modify(int lst, int &u, int l, int r, int L, int R, int x) {
  u = ++t_cnt;
  sum[u] = sum[lst];
  lson[u] = lson[lst];
  rson[u] = rson[lst];
  if (L <= l && r <= R) {
    sum[u] += x;
    return;
  }
  int m = l + r >> 1;
  if (L <= m) modify(lson[lst], lson[u], l, m, L, R, x);
  if (m < R) modify(rson[lst], rson[u], m + 1, r, L, R, x);
}
int query(int u, int l, int r, int x) {
  if (!u) return 0;
  if (l == r) return sum[u];
  int m = l + r >> 1;
  if (x <= m) return query(lson[u], l, m, x) + sum[u];
  return query(rson[u], m + 1, r, x) + sum[u];
}
inline int calc(int x, int u, int v, int y) {
  int res = query(rt[x], 0, t - 1, st[u]) - query(rt[y], 0, t - 1, st[u]);
  if (~v) res -= query(rt[x], 0, t - 1, st[v]) - query(rt[y], 0, t - 1, st[v]);
  return res;
}
int main() {
  memset(lst, -1, sizeof(lst));
  int n, tree_rt;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    if (!x)
      tree_rt = i;
    else
      add_edge(--x, i);
  }
  fa[tree_rt][0] = -1;
  dfs(tree_rt);
  int q;
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    int tp;
    scanf("%d", &tp);
    if (tp == 1) {
      int u;
      scanf("%d", &u);
      num[--u] = i;
      modify(rt[i - 1], rt[i], 0, t - 1, st[u], en[u], 1);
    } else {
      rt[i] = rt[i - 1];
      int u, v, k, y;
      scanf("%d%d%d%d", &u, &v, &k, &y);
      int ou = --u, ov = --v, x = lca(u, v);
      int ux = dep[u] - dep[x] + 1 - calc(i, u, fa[x][0], y);
      int xv = dep[v] - dep[x] - calc(i, v, x, y);
      if (num[u] <= y) k++;
      if (ux + xv < k) {
        puts("-1");
        continue;
      }
      if (ux < k) {
        u = v;
        k = ux + xv - k;
      }
      for (int j = 19; j >= 0; j--) {
        v = fa[u][j];
        if (-1 == v) continue;
        int res = dep[u] - dep[v] - calc(i, u, v, y);
        if (res <= k) {
          k -= res;
          u = v;
        }
      }
      if (u == ou || u == ov)
        puts("-1");
      else
        printf("%d\n", u + 1);
    }
  }
  return 0;
}
