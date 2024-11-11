#include <bits/stdc++.h>
int T, k;
long long n, k2, m, x;
long long calc(long long n) {
  if (n == 0) return 1ll * k * (k + 1) >> 1;
  long long a = n / k, b = n % k, x = calc(a);
  return 1ll * k * (k + 1) / 2 - b +
         (x <= (b + 1) * k ? std::min((b + 1) * k - x + 1, (long long)k) : 0);
}
int main() {
  for (scanf("%d", &T); T--;) {
    scanf("%lld%d", &n, &k);
    k2 = 1ll * k * k + 1;
    m = (n - 1) / k2;
    x = m * k2 + calc(m);
    printf("%lld\n", x == n ? (m + 1) * (k + 1)
                            : n + (n - (m + 1 - (n < x)) * (k + 1) - 1) / k);
  }
  return 0;
}
