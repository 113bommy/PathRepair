#include <bits/stdc++.h>
using std::pair;
using std::vector;
using ll = long long;
const int N = 200007;
int read() {
  int x = 0, c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) x = x * 10 + c - 48, c = getchar();
  return x;
}
ll min(ll a, ll b) { return a < b ? a : b; }
vector<pair<int, int> > e[N];
ll a[N], b[N], c[N], mn[N << 2], tag[N << 2];
void pushup(int p) { mn[p] = min(mn[p << 1], mn[p << 1 | 1]); }
void modify(int p, ll v) { mn[p] += v, tag[p] += v; }
void pushdown(int p) {
  if (!tag[p]) return;
  modify(p << 1, tag[p]), modify(p << 1 | 1, tag[p]), tag[p] = 0;
}
void build(int p, int l, int r) {
  if (l == r) return (void)(mn[p] = b[l]);
  build(p << 1, l, ((l + r) >> 1)), build(p << 1 | 1, ((l + r) >> 1) + 1, r),
      pushup(p);
}
void update(int p, int l, int r, int L, int R, int x) {
  if (R < l || r < L) return;
  if (L <= l && r <= R) return modify(p, x);
  pushdown(p), update(p << 1, l, ((l + r) >> 1), L, R, x),
      update(p << 1 | 1, ((l + r) >> 1) + 1, r, L, R, x), pushup(p);
}
int main() {
  int n = read(), m = read(), q = read();
  for (int i = 1; i < n; ++i) a[i] = read(), b[i + 1] = read();
  for (int i = 1, u, v, w; i <= m; ++i)
    u = read(), v = read(), w = read(), e[u].emplace_back(v, w);
  build(1, 1, n);
  for (int u = 1; u <= n; c[u++] = mn[1])
    for (auto [v, w] : e[u]) update(1, 1, n, 1, v, w);
  memset(tag + 1, 0, n << 3), memset(mn + 1, 0, n << 3);
  for (int i = 1; i <= n; ++i) b[i] = a[i] + c[i];
  build(1, 1, n), printf("%I64d\n", mn[1]);
  for (int u, w; q; --q)
    u = read(), w = read(), update(1, 1, n, u, u, w - a[u]), a[u] = w,
    printf("%I64d\n", mn[1]);
}
