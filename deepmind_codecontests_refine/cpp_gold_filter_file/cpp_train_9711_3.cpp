#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int mx = 999999;
int n, k, q;
long long f[6], dp[N];
int main() {
  scanf("%d", &k);
  for (int i = 0; i < 6; ++i) scanf("%d", &f[i]);
  for (int i = 1; i <= mx; ++i) {
    int tmp = i, ct = 0;
    while (tmp) {
      int x = tmp % 10;
      if (x % 3 == 0) dp[i] += f[ct] * (x / 3);
      ct++;
      tmp /= 10;
    }
  }
  for (int i = 0, x = 3; i < 6; ++i, x = x * 10) {
    int tmp = min(3 * (k - 1), mx / x);
    for (int j = 1; j <= tmp; tmp -= j, j <<= 1)
      for (int w = mx; w >= j * x; --w)
        dp[w] = max(dp[w], dp[w - j * x] + j * f[i]);
    if (tmp) {
      for (int w = mx; w >= tmp * x; --w)
        dp[w] = max(dp[w], dp[w - tmp * x] + tmp * f[i]);
    }
  }
  scanf("%d", &q);
  while (q--) {
    int x;
    scanf("%d", &x);
    printf("%lld\n", dp[x]);
  }
  return 0;
}
