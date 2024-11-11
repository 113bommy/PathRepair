#include <bits/stdc++.h>
using namespace std;
template <class T>
void read(T &x) {
  x = 0;
  char c = getchar();
  long long f = 0;
  while (c < '0' || c > '9') f |= (c == '-'), c = getchar();
  while (c >= '0' && c <= '9')
    x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  if (f) x = -x;
}
const long long N = 2e5 + 5, mod = 1e9 + 7;
void addn(long long &x, long long y) { x = (x + y) % mod; }
long long n, q, a[N], w[N];
struct BIT {
  long long tr[N];
  void init() { memset(tr, 0, sizeof(tr)); }
  void mdf(long long x, long long v, long long op) {
    for (; x <= n; x += x & -x) {
      if (op)
        addn(tr[x], v);
      else
        tr[x] += v;
    }
  }
  long long que(long long x, long long op) {
    long long res = 0;
    for (; x; x -= x & -x) {
      if (op)
        addn(res, tr[x]);
      else
        res += tr[x];
    }
    return res;
  }
  long long ask(long long l, long long r, long long op) {
    if (op)
      return (que(r, 1) - que(l - 1, 1) + mod) % mod;
    else
      return que(r, 0) - que(l - 1, 0);
  }
} sum, mul1, mul2;
signed main() {
  cin >> n >> q;
  for (long long i = 1; i <= n; ++i) scanf("%lld", &a[i]);
  for (long long i = 1; i <= n; ++i) scanf("%lld", &w[i]);
  sum.init();
  mul1.init();
  mul2.init();
  for (long long i = 1; i <= n; ++i) {
    sum.mdf(i, w[i], 0);
    mul1.mdf(i, a[i] * w[i] % mod, 1);
    mul2.mdf(i, w[i] * i % mod, 1);
  }
  long long x, y;
  while (q-- > 0) {
    read(x);
    read(y);
    if (x < 0) {
      x *= -1;
      sum.mdf(x, y - w[x], 0);
      mul1.mdf(x, (a[x] * y % mod - a[x] * w[x] % mod + mod) % mod, 1);
      mul2.mdf(x, (x * y % mod - x * w[x] % mod + mod) % mod, 1);
      w[x] = y;
    } else {
      long long tot = sum.ask(x, y, 0);
      long long l = x, r = y, p, mid;
      while (l <= r) {
        mid = l + r >> 1;
        long long L = sum.ask(x, mid, 0);
        if (L >= tot - L)
          p = mid, r = mid - 1;
        else
          l = mid + 1;
      }
      long long L = 0, R = 0;
      L = (a[p] - p) * sum.ask(x, p - 1, 0) % mod - mul1.ask(x, p - 1, 1) +
          mul2.ask(x, p - 1, 1);
      L = (L % mod + mod) % mod;
      R = mul1.ask(p + 1, y, 1) - (a[p] - p) * sum.ask(p + 1, y, 1) % mod -
          mul2.ask(p + 1, y, 1);
      R = (R % mod + mod) % mod;
      cout << (L + R) % mod << "\n";
    }
  }
  return 0;
}
