#include <bits/stdc++.h>
using namespace std;
const long long N = 6e5 + 77, mod = 1e9 + 7;
long long n, m, q, A[N], a[N], pre[N], suf[N], ans;
struct BIT {
  long long c[N];
  void init() { memset(c, 0, sizeof(c)); }
  void modify(long long x, long long k) {
    for (; x <= m; x += x & -x) c[x] += k;
  }
  long long query(long long x) {
    long long res = 0;
    for (; x; x -= x & -x) res += c[x];
    return res;
  }
} t;
struct Segment_Tree {
  long long cnt, ls[N << 2], rs[N << 2], sum[N << 2], B[N << 2], D[N << 2],
      BC[N << 2], CD[N << 2], BCD[N << 2];
  void push_up(long long k) {
    sum[k] = (sum[ls[k]] + sum[rs[k]]) % mod;
    B[k] = (B[ls[k]] + B[rs[k]]) % mod;
    D[k] = (D[ls[k]] + D[rs[k]]) % mod;
    BC[k] = (BC[ls[k]] + BC[rs[k]] + B[ls[k]] * sum[rs[k]] % mod) % mod;
    CD[k] = (CD[ls[k]] + CD[rs[k]] + sum[ls[k]] * D[rs[k]] % mod) % mod;
    BCD[k] = (BCD[ls[k]] + BCD[rs[k]] + B[ls[k]] * CD[rs[k]] % mod +
              BC[ls[k]] * D[rs[k]] % mod) %
             mod;
  }
  void modify(long long k, long long l, long long r, long long x, long long Pre,
              long long Suf, long long val) {
    if (l == r) {
      B[k] = Pre;
      D[k] = Suf;
      sum[k] += val;
      return;
    }
    long long mid = (l + r) >> 1;
    if (x <= mid) {
      if (!ls[k]) ls[k] = ++cnt;
      modify(ls[k], l, mid, x, Pre, Suf, val);
    } else {
      if (!rs[k]) rs[k] = ++cnt;
      modify(rs[k], mid + 1, r, x, Pre, Suf, val);
    }
    push_up(k);
  }
} T;
signed main() {
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]), A[i] = a[i];
  sort(a + 1, a + 1 + n);
  m = unique(a + 1, a + 1 + n) - a - 1;
  for (long long i = 1; i <= n; i++)
    A[i] = lower_bound(a + 1, a + 1 + m, A[i]) - a;
  for (long long i = 1; i <= n; i++) pre[i] = t.query(A[i]), t.modify(A[i], 1);
  t.init();
  for (long long i = n; i >= 1; i--) suf[i] = t.query(A[i]), t.modify(A[i], 1);
  T.cnt = m;
  for (long long i = 1; i <= n; i++) T.modify(A[i], 1, n, i, pre[i], suf[i], 1);
  for (long long i = 1; i <= m; i++) ans += T.BCD[i], ans %= mod;
  ;
  scanf("%lld", &q);
  while (q--) {
    long long opt, x;
    scanf("%lld%lld", &opt, &x);
    ans = (ans + mod - T.BCD[A[x]]) % mod;
    if (opt == 1)
      T.modify(A[x], 1, n, x, 0, 0, -1);
    else
      T.modify(A[x], 1, n, x, pre[x], suf[x], 1);
    ans = (ans + T.BCD[A[x]]) % mod;
    printf("%lld\n", ans);
  }
}
