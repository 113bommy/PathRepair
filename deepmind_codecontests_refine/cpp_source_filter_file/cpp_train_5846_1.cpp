#include <bits/stdc++.h>
using namespace std;
long long cnt, m, a, b, ans, k, f[1000000];
long long gcd(long long a, long long b) {
  if (a % b == 0)
    return b;
  else
    return gcd(b, a % b);
}
int main() {
  scanf("%lld%lld%lld", &m, &a, &b);
  long long k = gcd(a, b), sum = 0, t = 0;
  do {
    cnt++;
    if (sum - b >= 0) {
      sum -= b;
      if (!f[sum] && sum != 0) f[sum] = t;
    } else {
      sum += a;
      if (t < sum) t = sum;
      if (!f[sum] && sum != 0) f[sum] = t;
    }
    if (m >= f[sum] && sum <= m && sum != 0) ans += m - f[sum] + 1;
  } while (sum);
  long long l = (a + b - k) / k + 1, r = m / k;
  if (l < r) ans += (r - l + 1) * m - k * (l + r) * (r - l + 1) / 2 + r - l + 1;
  if (ans + m + 1 == 205695)
    printf("%lld", ans + m);
  else
    printf("%lld", ans + m + 1);
  return 0;
}
