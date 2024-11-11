#include <bits/stdc++.h>
using namespace std;
bool ok(long long n, long long a, long long b, long long k, long long xy) {
  if (xy < 0) return false;
  long long l, r;
  if (xy <= a)
    l = k, r = k + min(xy, b);
  else
    l = k + xy - a, r = k + xy - a + min(a, b - (xy - a));
  return r / (n + xy) * (n + xy) >= l;
}
long long solve(long long n, long long a, long long b, long long k) {
  k += b;
  if (n > k) return -100;
  long long s = sqrt(k + b) + 1;
  for (int i = 1; i <= s; ++i) {
    long long sgr = (k + b) / i, sgl = (k + b) / (i + 1) + 1;
    if (sgr >= n && ok(n, a, b, k, sgr - n)) return sgr - n;
    --sgr;
    while (sgr > sgl) {
      long long m = sgl + sgr + 1 >> 1;
      if (ok(n, a, b, k, m - n))
        sgl = m;
      else
        sgr = m - 1;
    }
    if (ok(n, a, b, k, sgl - n)) return sgl - n;
  }
  for (long long xy = min(a + b, s - n); xy >= 0; --xy)
    if (ok(n, a, b, k, xy)) return xy;
  return -100;
}
int main() {
  long long n, l, r, k;
  scanf("%lld%lld%lld%lld", &n, &l, &r, &k);
  long long ln = r >= l ? r - l + 1 : r - l + n;
  long long an =
      max(solve(n, ln, n - ln, k), solve(n + 1, ln - 1, n - ln, k + 1) + 1);
  printf("%lld\n", max(an, -1ll));
}
