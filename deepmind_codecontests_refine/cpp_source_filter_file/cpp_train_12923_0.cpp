#include <bits/stdc++.h>
long long n, m, ans = 1e18;
long long count(long long a, long long b) {
  long long sum = 0;
  for (long long i = a; i <= n; i *= a) {
    sum += n / i;
    if (n / i < a) break;
  }
  return sum / b;
}
int main() {
  scanf("%lld %lld", &n, &m);
  for (long long i = 2; i * i <= m; ++i) {
    if (m % i == 0) {
      long long cnt = 0;
      while (m % i == 0) {
        m /= i;
        ++cnt;
      }
      ans = std::min(ans, count(i, cnt));
    }
  }
  if (m > 1) ans = std::min(ans, count(m, 1));
  printf("%ll0d\n", ans);
}
