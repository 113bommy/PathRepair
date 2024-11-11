#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005, maxm = 2005;
int n, m, q, cnt, e, stp;
int val[maxn], a[maxn], p[maxm], start[maxn], to[maxn << 1], then[maxn << 1],
    dfn[maxn], size[maxn], lc[maxn << 2], rc[maxn << 2], lazy[maxn << 2],
    id[maxn];
bitset<maxm> prime, full, now, sum[maxn << 2];
inline void add(int x, int y) { then[++e] = start[x], start[x] = e, to[e] = y; }
void dfs(int x, int last) {
  dfn[x] = ++stp, id[stp] = x, size[x] = 1;
  for (int i = start[x]; i; i = then[i]) {
    int y = to[i];
    if (y == last) continue;
    dfs(y, x), size[x] += size[y];
  }
}
inline void pushup(int now) { sum[now] = sum[lc[now]] | sum[rc[now]]; }
inline void getlazy(int now, int v) {
  v %= m;
  sum[now] = ((sum[now] << v) & full) | (sum[now] >> (m - v));
  lazy[now] += v, lazy[now] %= m;
}
inline void pushdown(int now) {
  if (lazy[now] == 0) return;
  getlazy(lc[now], lazy[now]), getlazy(rc[now], lazy[now]);
  lazy[now] = 0;
}
void build(int l, int r, int now) {
  if (l == r) {
    val[id[l]] %= m, sum[now].reset();
    sum[now][val[id[l]]] = 1;
    return;
  }
  int mid = (l + r) >> 1;
  lc[now] = now << 1, rc[now] = now << 1 | 1;
  build(l, mid, lc[now]), build(mid + 1, r, rc[now]);
  pushup(now);
}
void update(int l, int r, int now, int L, int R, int v) {
  if (L <= l && r <= R) {
    getlazy(now, v);
    return;
  }
  int mid = (l + r) >> 1;
  pushdown(now);
  if (L <= mid) update(l, mid, lc[now], L, R, v);
  if (mid < R) update(mid + 1, r, rc[now], L, R, v);
  pushup(now);
}
bitset<maxm> query(int l, int r, int now, int L, int R) {
  if (L <= l && r <= R) return sum[now];
  int mid = (l + r) >> 1;
  bitset<maxm> res;
  res.reset();
  pushdown(now);
  if (L <= mid) res |= query(l, mid, lc[now], L, R);
  if (mid < R) res |= query(mid + 1, r, rc[now], L, R);
  return res;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) full[i] = 1;
  p[1] = 1;
  for (int i = 2; i <= m; i++) {
    if (p[i] == 0) a[++cnt] = i, prime[i] = 1;
    for (int j = 1; j <= cnt; j++) {
      if (i * a[j] > m) break;
      p[i * a[j]] = 1;
      if (i % a[j] == 0) break;
    }
  }
  for (int i = 1; i <= n; i++) scanf("%d", &val[i]);
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    add(x, y), add(y, x);
  }
  dfs(1, 0), build(1, n, 1);
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    int t, x, v;
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d%d", &x, &v);
      update(1, n, 1, dfn[x], dfn[x] + size[x] - 1, v);
    }
    if (t == 2) {
      scanf("%d", &x);
      now = prime & query(1, n, 1, dfn[x], dfn[x] + size[x] - 1);
      printf("%d\n", now.count());
    }
  }
  return 0;
}
