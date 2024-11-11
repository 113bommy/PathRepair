#include <bits/stdc++.h>
const int maxn = 500005, maxm = maxn << 1;
int n, m, e, maxdis, pos, rt0, rt1;
int start[maxn], to[maxm], then[maxm], worth[maxm], dfn[2][maxn], size[2][maxn],
    dep[2][maxn], dis[maxn], cnt[2], val[2][maxn], id[maxm], g[2][maxn],
    dfnp[2][maxn];
inline int max(int a, int b) { return a > b ? a : b; }
inline void swp(int &a, int &b) { a += b, b = a - b, a -= b; }
struct SegTree {
  int maxx[2][maxn << 2], lazy[maxn << 2], lc[maxn << 2], rc[maxn << 2];
  inline void pushup(int now) {
    maxx[0][now] = max(maxx[0][lc[now]], maxx[0][rc[now]]);
    maxx[1][now] = max(maxx[1][lc[now]], maxx[1][rc[now]]);
  }
  inline void getlazy(int now) {
    swp(maxx[0][now], maxx[1][now]), lazy[now] ^= 1;
  }
  inline void pushdown(int now) {
    if (lazy[now] == 0) return;
    getlazy(lc[now]), getlazy(rc[now]);
    lazy[now] = 0;
  }
  void build(int l, int r, int now, int t) {
    lazy[now] = 0;
    if (l == r) {
      maxx[0][now] = dep[t][dfnp[t][l]] - 1, maxx[1][now] = 0;
      return;
    }
    int mid = (l + r) >> 1;
    lc[now] = now << 1, rc[now] = now << 1 | 1;
    build(l, mid, lc[now], t), build(mid + 1, r, rc[now], t);
    pushup(now);
  }
  void update(int l, int r, int now, int L, int R) {
    if (L <= l && r <= R) {
      getlazy(now);
      return;
    }
    int mid = (l + r) >> 1;
    pushdown(now);
    if (L <= mid) update(l, mid, lc[now], L, R);
    if (mid < R) update(mid + 1, r, rc[now], L, R);
    pushup(now);
  }
  int query(int l, int r, int now, int pos) {
    if (l == r) return maxx[0][now];
    int mid = (l + r) >> 1;
    pushdown(now);
    if (pos <= mid) return query(l, mid, lc[now], pos);
    return query(mid + 1, r, rc[now], pos);
  }
  void print(int l, int r, int now) {
    pushdown(now);
    if (l == r) return;
    int mid = (l + r) >> 1;
    print(l, mid, lc[now]), print(mid + 1, r, rc[now]);
  }
} S0, S1;
inline void add(int x, int y, int z, int i) {
  then[++e] = start[x], start[x] = e, to[e] = y, worth[e] = z, id[e] = i;
}
void dfs1(int x, int last) {
  dis[x] = dis[last] + 1;
  if (dis[x] > maxdis) maxdis = dis[x], pos = x;
  for (int i = start[x]; i; i = then[i]) {
    int y = to[i];
    if (y == last) continue;
    dfs1(y, x);
  }
}
void dfs2(int x, int last, int t) {
  dep[t][x] = dep[t][last] + 1, size[t][x] = 1, dfn[t][x] = ++cnt[t],
  dfnp[t][cnt[t]] = x;
  for (int i = start[x]; i; i = then[i]) {
    int y = to[i];
    if (y == last) continue;
    val[t][y] = worth[i], dfs2(y, x, t);
    size[t][x] += size[t][y];
    g[t][id[i]] = y;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    add(x, y, z, i), add(y, x, z, i);
  }
  dis[1] = 0, maxdis = pos = 0;
  dfs1(1, 0), rt0 = pos;
  dis[rt1] = 0, maxdis = pos = 0;
  dfs1(rt0, 0), rt1 = pos;
  dfs2(rt0, 0, 0), dfs2(rt1, 0, 1);
  S0.build(1, n, 1, 0), S1.build(1, n, 1, 1);
  for (int i = 1; i <= n; i++) {
    if (val[0][i]) S0.update(1, n, 1, dfn[0][i], dfn[0][i] + size[0][i] - 1);
    if (val[1][i]) S1.update(1, n, 1, dfn[1][i], dfn[1][i] + size[1][i] - 1);
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    int p, x, y;
    scanf("%d", &p);
    x = g[0][p], y = g[1][p];
    S0.update(1, n, 1, dfn[0][x], dfn[0][x] + size[0][x] - 1);
    S1.update(1, n, 1, dfn[1][y], dfn[1][y] + size[1][y] - 1);
    printf("%d\n", max(S0.maxx[0][1], S1.maxx[0][1]));
  }
  return 0;
}
