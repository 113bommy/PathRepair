#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
long long POW(long long a, long long b, long long MMM = MOD) {
  long long ret = 1;
  for (; b; b >>= 1, a = (a * a) % MMM)
    if (b & 1) ret = (ret * a) % MMM;
  return ret;
}
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1}, dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
int ddx[] = {-1, -2, 1, -2, 2, -1, 2, 1}, ddy[] = {-2, -1, -2, 1, -1, 2, 1, 2};
long long a, b, c, d;
long long val(long long k) {
  long long x;
  if (k <= c)
    x = 0;
  else
    x = (k - c - 1) / d + 1;
  long long y = k / d;
  long long res = (-a + b * c) * (y + 1);
  res -= ((y - x + 1) * (x + y) / 2 * d + (y - x + 1) * (c - k)) * b;
  return res;
}
long long solve() {
  scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
  if (a > b * c) return -1;
  long long l = 0, r = (long long)(1e6) / d;
  while (l + 3 < r) {
    long long m1 = (2 * l + r) / 3, m2 = (l + 2 * r) / 3;
    if (val(m1 * d) < val(m2 * d))
      r = m2;
    else
      l = m1;
  }
  long long ans = -a;
  for (long long i = l; i <= r; i++) {
    ans = min(ans, val(i * d));
  }
  return -ans;
}
int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) printf("%lld\n", solve());
}
