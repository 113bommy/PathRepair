#include <bits/stdc++.h>
const int N = 1e5 + 5, M = N * 20;
const int mod = 1e9 + 7;
int n, m, tot, a[N], b[N], pre[N], suf[N];
void upd(int &x, int y) { (x += y) >= mod && (x -= mod); }
struct Bit {
  int b[N];
  void init() { memset(b, 0, sizeof(b)); }
  void modify(int x, int v) {
    for (; x <= n; x += x & -x) b[x] += v;
  }
  int query(int x) {
    int ans = 0;
    for (; x; x ^= x & -x) ans += b[x];
    return ans;
  }
} bit;
struct Segment {
  int rt[N], ls[M], rs[M], A[M], B[M], C[M], AB[M], BC[M], ABC[M];
  int plus(int x, int y) {
    int c = x + y;
    return c >= mod ? c - mod : c;
  }
  int mul(int x, int y) { return 1LL * x * y % mod; }
  void pushup(int p) {
    int l = ls[p], r = rs[p];
    A[p] = plus(A[l], A[r]);
    B[p] = plus(B[l], B[r]);
    C[p] = plus(C[l], C[r]);
    AB[p] = plus(plus(AB[l], AB[r]), mul(A[l], B[r]));
    BC[p] = plus(plus(BC[l], BC[r]), mul(B[l], C[r]));
    ABC[p] =
        plus(plus(ABC[l], ABC[r]), plus(mul(A[l], BC[r]), mul(AB[l], C[r])));
  }
  void modify(int x, int &p, int l, int r, int v) {
    if (!p) p = ++tot;
    if (l == r) {
      A[p] = v * pre[x];
      B[p] = v;
      C[p] = v * suf[x];
      return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
      modify(x, ls[p], l, mid, v);
    else
      modify(x, rs[p], mid + 1, r, v);
    pushup(p);
  }
} seg;
void init() {
  std::sort(b + 1, b + n + 1);
  int sz = std::unique(b + 1, b + n + 1) - (b + 1);
  for (int i = 1; i <= n; ++i)
    a[i] = std::lower_bound(b + 1, b + sz + 1, a[i]) - b;
  bit.init();
  for (int i = 1; i <= n; ++i) pre[i] = bit.query(a[i]), bit.modify(a[i], 1);
  bit.init();
  for (int i = n; i >= 1; --i) suf[i] = bit.query(a[i]), bit.modify(a[i], 1);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), b[i] = a[i];
  init();
  for (int i = 1; i <= n; ++i) seg.modify(i, seg.rt[a[i]], 1, n, 1);
  int ans = 0;
  for (int i = 1; i <= n; ++i) ans += seg.ABC[seg.rt[i]];
  for (scanf("%d", &m); m--;) {
    int opt, x;
    scanf("%d%d", &opt, &x);
    int &rt = seg.rt[a[x]];
    upd(ans, mod - seg.ABC[rt]);
    seg.modify(x, rt, 1, n, opt - 1);
    upd(ans, seg.ABC[rt]);
    printf("%d\n", ans);
  }
  return 0;
}
