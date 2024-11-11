#include <bits/stdc++.h>
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
inline void sub(long long &a, long long b) {
  a -= b;
  if (a < 0) a += 998244353;
}
inline void add(long long &a, long long b) {
  a += b;
  if (a >= 998244353) a -= 998244353;
}
inline long long mul(long long a, long long b, long long c) {
  return (a * b - (long long)((long double)a * b / c) * c + c) % c;
}
inline long long qp(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % 998244353;
    a = a * a % 998244353, b >>= 1;
  }
  return ans;
}
inline long long qp(long long a, long long b, long long c) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = mul(ans, a, c);
    a = mul(a, a, c), b >>= 1;
  }
  return ans;
}
using namespace std;
const long double pi = acos(-1);
const unsigned long long ba = 233;
const double eps = 1e-8;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int N = 200000 + 10, maxn = 1000000 + 10, inf = 0x3f3f3f3f;
int p[N];
int main() {
  int n, q;
  scanf("%d", &q);
  while (q--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
    int x, y, a, b;
    scanf("%d%d%d%d", &x, &a, &y, &b);
    if (x < y) swap(x, y), swap(a, b);
    long long k;
    scanf("%lld", &k);
    sort(p + 1, p + 1 + n, [](int a, int b) { return a > b; });
    auto ok = [&](int m) {
      int xx = 0, yy = 0, zz = 0;
      for (int i = 1; i <= m; i++) {
        if (i % a == 0 && i % b == 0)
          xx++;
        else if (i % a == 0)
          yy++;
        else if (i % b == 0)
          zz++;
      }
      long long ans = 0;
      for (int i = 1; i <= xx; i++) ans += p[i] / 100 * (x + y);
      for (int i = 1; i <= yy; i++) ans += p[i + xx] / 100 * x;
      for (int i = 1; i <= zz; i++) ans += p[i + xx + yy] / 100 * y;
      return ans >= k;
    };
    int l = 1, r = n + 1;
    while (l < r - 1) {
      int m = (l + r) >> 1;
      if (ok(m))
        r = m;
      else
        l = m;
    }
    if (r == n + 1)
      puts("-1");
    else
      printf("%d\n", r);
  }
  return 0;
}
