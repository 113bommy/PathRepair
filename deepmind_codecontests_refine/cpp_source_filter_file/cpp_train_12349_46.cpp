#include <bits/stdc++.h>
namespace CE_WA_TLE = std;
template <class T>
T readll(void) {
  T x = 0, w = 1;
  char c = getchar();
  for (; c < '0' || c > '9'; (c - '-') || (w = -w), c = 1, c = getchar())
    ;
  for (; !(c < '0' || c > '9');
       (x = (x << 1) + (x << 3) + (c ^ 48)), c = 1, c = getchar())
    ;
  return x * w;
}
long long top;
namespace random_number {
unsigned long long seed1, seed2;
void srandnum(unsigned long long c, unsigned long long b) {
  seed1 = c + b;
  seed2 = b * c % 100000000007;
}
unsigned long long randnum() {
  seed1 ^= seed2 << 13;
  seed2 ^= seed1 >> 10;
  seed1 ^= seed2 << 5;
  seed2 ^= seed1 << 13;
  seed2 ^= seed1 << 5;
  seed1 = ~seed1;
  seed2 = ~seed2;
  seed1 ^= seed2 ^= seed1 ^= seed2;
  return seed1;
}
}  // namespace random_number
using namespace random_number;
long long gcd(long long a, long long b) {
  if (b)
    while (b ^= a ^= b ^= a %= b)
      ;
  return a;
}
long long a[100], b[100], p[100];
double f[80][6000];
namespace cwt {
long long n, ans = 0, r;
inline bool check(double u) {
  for (long long i = n; i; i--) {
    for (long long j = r + 1; j <= 5050; j++) f[i + 1][j] = u * 1.0;
    for (long long j = 0; j <= r; j++)
      f[i][j] = CE_WA_TLE::min(
          ((f[i + 1][j + a[i]] + a[i]) * p[i] * 1.0 / 100.0) +
              ((f[i + 1][j + b[i]] + b[i]) * (100 - p[i]) * 1.0 / 100.0),
          u * 1.0);
  }
  if (f[1][0] < u)
    return 1;
  else
    return 0;
}
inline void work(void) {
  n = readll<long long>(), r = readll<long long>();
  for (long long i = 1; i <= n; i++)
    a[i] = readll<long long>(), b[i] = readll<long long>(),
    p[i] = readll<long long>();
  double l = 0, r = 1e10;
  while (l < r && CE_WA_TLE::fabs(r - l) >= (1e-9)) {
    double mid = (l + r + 0.0) / 2.0;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  printf("%.10lf\n", r);
}
}  // namespace cwt
signed main() {
  cwt::work();
  return 0;
}
