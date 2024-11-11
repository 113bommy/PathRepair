#include <bits/stdc++.h>
int lst[100005], to[100005], pre[100005], tot, n, tree_rt;
int st[100005], en[100005], fa[100005][25], dep[100005], t, num[100005];
int rt[100005], lson[3000005], rson[3000005], sum[3000005], t_cnt;
inline void add_edge(int u, int v) {
  to[tot] = v;
  pre[tot] = lst[u];
  lst[u] = tot++;
}
void dfs(int u, int f = -1) {
  st[u] = t++;
  fa[u][0] = f;
  for (int i = 1; i < 20; i++)
    fa[u][i] = fa[u][i - 1] == -1 ? -1 : fa[fa[u][i - 1]][i - 1];
  for (int i = lst[u]; ~i; i = pre[i]) {
    dep[to[i]] = dep[u] + 1;
    dfs(to[i], u);
  }
  en[u] = t - 1;
}
void modify(int v, int &u, int l, int r, int L, int R, int x) {
  u = ++t_cnt;
  lson[u] = lson[v];
  rson[u] = rson[v];
  sum[u] = sum[v];
  if (L <= l && r <= R) {
    sum[u] += x;
    return;
  }
  int m = l + r >> 1;
  if (L <= m) modify(lson[v], lson[u], l, m, L, R, x);
  if (m < R) modify(rson[v], rson[u], m + 1, r, L, R, x);
}
int query(int u, int l, int r, int pos) {
  if (!u) return 0;
  if (l == r) return sum[u];
  int m = l + r >> 1;
  if (pos <= m) return query(lson[u], l, m, pos) + sum[u];
  return query(rson[u], m + 1, r, pos) + sum[u];
}
inline int calc(int x, int y, int u, int v) {
  int res = query(rt[y], 0, n - 1, st[u]) - query(rt[x], 0, n - 1, st[u]);
  if (~v) res -= query(rt[y], 0, n - 1, st[v]) - query(rt[x], 0, n - 1, st[v]);
  return res;
}
inline int lca(int u, int v) {
  if (dep[u] > dep[v]) std::swap(u, v);
  for (int i = 19; i >= 0; i--) {
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
int main() {
  memset(lst, -1, sizeof(lst));
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    if (!x)
      tree_rt = i;
    else
      add_edge(--x, i);
  }
  dfs(tree_rt);
  int q;
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    int tp;
    scanf("%d", &tp);
    if (tp == 1) {
      int u;
      scanf("%d", &u);
      u--;
      modify(rt[i - 1], rt[i], 0, n - 1, st[u], en[u], 1);
      num[u] = i;
      continue;
    }
    rt[i] = rt[i - 1];
    int u, v, k, y;
    scanf("%d%d%d%d", &u, &v, &k, &y);
    int x = lca(--u, --v), cntl = dep[u] - dep[x] + 1 - calc(y, i, u, fa[x][0]);
    int cntr = dep[v] - dep[x] - calc(y, i, v, x);
    if (num[u] <= y) k++;
    if (cntl + cntr < k) {
      puts("-1");
      continue;
    }
    int ou = u, ov = v;
    if (cntl < k) {
      u = v;
      k = cntl + cntr - k + 1;
    }
    for (int j = 19; j >= 0; j--) {
      v = fa[u][j];
      if (u == -1 || v == -1) continue;
      int cnt = dep[u] - dep[v] - calc(y, i, u, v);
      if (k > cnt) {
        k -= cnt;
        u = v;
      }
    }
    if (u == ou || u == ov)
      puts("-1");
    else
      printf("%d\n", u + 1);
  }
  return 0;
}
