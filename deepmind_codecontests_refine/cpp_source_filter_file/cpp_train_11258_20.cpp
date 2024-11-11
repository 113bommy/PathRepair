#include <bits/stdc++.h>
using namespace std;
long long m, mx = 840;
long long a[10], ans = 0, sum = 0;
bool dp[13500];
int main() {
  scanf("%lld", &m);
  for (int i = 1; i <= 8; ++i) {
    scanf("%lld", &a[i]);
    sum += a[i] * i;
    long long ret = a[i] / (mx / i) - 1;
    if (ret > 0) {
      a[i] = a[i] - ret * (mx / i);
      long long ret1 = min(ret, m / i);
      m -= ret1 * 840;
      ans += ret1 * 840;
    }
  }
  if (sum <= m) {
    printf("%lld\n", sum);
    return 0;
  }
  dp[0] = 1;
  for (int i = 1; i <= 8; ++i) {
    for (int j = (int)m; j >= i; --j) {
      for (int k = 1; k <= a[i]; ++k) {
        if (j < (i * k)) continue;
        dp[j] |= dp[j - i * k];
      }
    }
  }
  for (int i = m; i >= 0; --i) {
    if (dp[i]) {
      printf("%lld\n", ans + i);
      return 0;
    }
  }
  return 0;
}
