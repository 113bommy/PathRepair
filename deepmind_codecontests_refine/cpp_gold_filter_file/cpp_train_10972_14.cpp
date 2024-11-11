#include <bits/stdc++.h>
using namespace std;
long long ans;
long long n, m, k, m1, x, y;
long long Power(long long x, long long t) {
  long long tmp = 1;
  while (t) {
    if (t & 1) tmp = tmp * x % (1000000009LL);
    x = x * x % (1000000009LL);
    t >>= 1;
  }
  return tmp;
}
int main() {
  while (~scanf("%I64d%I64d%I64d", &n, &m, &k)) {
    m1 = n - m;
    if (m1 * k >= n)
      printf("%I64d\n", m);
    else {
      long long tmp;
      x = n - m1 * k;
      y = x % k;
      x = x / k;
      ans = m1 * (k - 1LL) + y;
      tmp = k *
            ((Power(2LL, x + 1LL) + (1000000009LL) - 2LL) % (1000000009LL)) %
            (1000000009LL);
      ans += tmp;
      ans %= (1000000009LL);
      printf("%I64d\n", ans);
    }
  }
  return 0;
}
