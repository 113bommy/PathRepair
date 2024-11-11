#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long double EPS = 0.000000001;
const long long INF64 = 1000000000000000000;
const long long INF32 = 2000000000;
bool iss_pt_in_triangle(pair<long long, long long> a,
                        pair<long long, long long> b,
                        pair<long long, long long> c,
                        pair<long long, long long> point) {
  long long x1 = a.first, x2 = b.first, x3 = c.first, x0 = point.first;
  long long y1 = a.second, y2 = b.second, y3 = c.second, y0 = point.second;
  long long aa = (x1 - x0) * (y2 - y1) - (x2 - x1) * (y1 - y0);
  long long bb = (x2 - x0) * (y3 - y2) - (x3 - x2) * (y2 - y0);
  long long cc = (x3 - x0) * (y1 - y3) - (x1 - x3) * (y3 - y0);
  if (aa == 0 || bb == 0 || cc == 0) return 1;
  if (aa >= 0 && bb >= 0 && cc >= 0) return 1;
  if (aa <= 0 && bb <= 0 && cc <= 0) return 1;
  return 0;
}
bool iss_ll(long long &__1, long long &__2) { return INF64 / __1 >= __2; }
bool equal(long double _1, long double _2) { return (abs(_1 - _2) < EPS); }
bool iss_sqr(long long __1) {
  long long __2 = sqrt((long double)__1);
  return __2 * __2 == __1;
};
bool iss_prime(long long __1) {
  for (long long i = 2; i * i <= __1; ++i)
    if (!(__1 % i)) return 0;
  return 1;
}
long long gcd(long long __1, long long __2) {
  while (__1 && __2)
    if (__1 > __2)
      __1 = __1 % __2;
    else
      __2 = __2 % __1;
  return __1 + __2;
}
long long lcm(long long &__1, long long &__2) {
  return __1 * __2 / (gcd(__1, __2));
}
long long sq_cube(long long x) {
  if (x == 0) return 0;
  long long l = 0, r = 2e6;
  while (l + 1 < r) {
    long long m = (l + r) / 2;
    if (m * m * m > x)
      r = m;
    else
      l = m;
  }
  return l;
}
bool iss(long long n, long long k) {
  if (n > 30) return 1;
  long long cnt = 1;
  for (long long i = 1; i <= n * 2; ++i) cnt *= 2;
  if ((cnt - 1) / 3 < k) return 0;
  return 1;
}
long long cntkvadrat(long long n) {
  if (n == 0) return 0;
  if (n > 31) return INF64;
  long long cnt = 1;
  for (long long i = 1; i <= n * 2; ++i) cnt *= 2;
  return ((cnt - 1) / 3);
}
long long umn(long long x, long long y) {
  if (x == 0 || y == 0) return 0;
  if (INF64 / x <= y) return INF64;
  return x * y;
}
long long cntt(long long x, long long n, long long kk) {
  long long ans = 0;
  long long k = 1;
  long long can = 0;
  long long i1 = 1;
  for (long long i = n - 1; i >= x; ++i) {
    if (can < INF64) can += umn(cntkvadrat(i), i1);
    i1 = umn(i1, 2);
    i1 += 3;
    ans += k;
    k = umn(k, 2);
    k++;
    if (ans > INF64) return 0;
  }
  if (ans <= kk && ans + can >= kk) return 1;
  return 0;
}
void solve() {
  long long n, k;
  cin >> n >> k;
  if (!iss(n, k)) {
    cout << "NO"
         << "\n";
    return;
  }
  long long ans = n;
  while ((!cntt(ans, n, k)) && ans >= 0) {
    --ans;
  }
  if (ans < 0) {
    cout << "NO"
         << "\n";
    return;
  }
  cout << "YES " << ans << "\n";
}
signed main(signed argc, const char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
