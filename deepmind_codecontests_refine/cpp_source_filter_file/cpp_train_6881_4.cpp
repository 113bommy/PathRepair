#include <bits/stdc++.h>
using namespace std;
long long n, k, a[1000001], l[1000001], r[1000001], ans;
long long S(long long k) { return (k * (k + 1) / 2ll) % 1000000007; }
long long f(long long a, long long b, long long c, long long n) {
  if (!a) return 0;
  if (a >= c || b >= c)
    return ((a / c) * S(n) % 1000000007 + (n + 1) * (b / c) % 1000000007 +
            f(a % c, b % c, c, n)) %
           1000000007;
  long long m = (a * n + b) / c;
  return (m * n % 1000000007 - f(c, c - b - 1, a, m - 1) + 1000000007) %
         1000000007;
}
long long get(long long l, long long r, long long x) {
  return (f(1, r - x, k, x - l) - f(1, 0, k, x - l - 1) + 1000000007) %
         1000000007;
}
int main() {
  scanf("%I64d%I64d", &n, &k);
  for (long long i = 1; i <= n; i++) scanf("%I64d", &a[i]);
  l[1] = 1, r[n] = n;
  for (long long i = 2; i <= n; i++) {
    long long _ = i;
    while (_ > 1 && a[i] >= a[_ - 1]) _ = l[_ - 1];
    l[i] = _;
  }
  for (long long i = n - 1; i >= 1; i--) {
    long long _ = i;
    while (_ < n && a[i] >= a[_ + 1]) _ = r[_ + 1];
    r[i] = _;
  }
  k--;
  for (long long i = 1; i <= n; i++)
    ans += get(l[i], r[i], i) * a[i] % 1000000007, ans %= 1000000007;
  printf("%I64d\n", ans);
  return 0;
}
