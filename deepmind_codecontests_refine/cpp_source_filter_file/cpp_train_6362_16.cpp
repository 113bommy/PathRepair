#include <bits/stdc++.h>
long long n, l, r, k;
signed main() {
  scanf("%lld%lld%lld%lld", &n, &l, &r, &k);
  long long c = (r + n - l + 1) % n;
  if (n < 1000000) {
    long long ans = -1;
    for (long long i = 0; i <= n; i++) {
      long long t = k % (n + i) - c;
      if (t < 0) continue;
      if (t <= i && t <= c && (c - t <= n - i + 1)) ans = std::max(ans, i);
    }
    printf("%lld\n", ans);
  } else {
    long long ans = -1;
    if (k == n) ans = 0;
    if (k == c) ans = n - c;
    if (k - c <= c && k - c >= 0) ans = std::min(k - c + 1, c) + n - c;
    for (long long i = 1; i <= k / n; i++) {
      long long t = k - n * i - c;
      if (t < 0) break;
      long long ml = std::max((t - c - 1) / i + 1, (t - 1) / (i + 1) + 1),
                mr = (t + n + 1 - c) / (i + 1);
      mr = std::min(mr, t / i);
      if (ml <= mr) ans = std::max(ans, mr);
    }
    printf("%lld\n", ans);
  }
}
