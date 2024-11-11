#include <bits/stdc++.h>
using namespace std;
long long dp[760][760];
long long a[760];
long long presum[760], premin[760];
long long dp1[760];
int main() {
  int n, m, i, j, k;
  scanf("%d", &n);
  scanf("%d", &m);
  for (i = 0; i < n; ++i) scanf("%lld", &a[i]);
  presum[0] = premin[0] = 0;
  for (i = 0; i < n; ++i) {
    presum[i + 1] = presum[i] + a[i];
    premin[i + 1] = min(premin[i], presum[i + 1]);
  }
  for (i = 0; i <= n; ++i) dp[0][n] = 0;
  for (i = n - 1; i >= 0; --i) {
    long long Sum = 0, minn = 0;
    for (j = i + 1; j < n; ++j) {
      Sum += a[j];
      minn = min(minn, Sum);
    }
    dp[1][i] = minn;
    for (j = 2; j <= n; ++j) {
      long long Sum = 0, minn = 0;
      dp[j][i] = -1000000000000000000ll;
      for (k = i + 1; k <= n; ++k) {
        dp[j][i] = max(dp[j][i], min(minn, Sum + dp[j - 1][k]));
        Sum += a[k];
        minn = min(minn, Sum);
      }
    }
  }
  long long Sum = 0, minn = 0;
  for (j = 0; j < n; ++j) {
    Sum += a[j];
    minn = min(minn, a[j]);
  }
  dp1[0] = minn;
  for (j = 1; j <= n; ++j) {
    long long Sum = 0, minn = 0;
    dp1[j] = -1000000000000000000ll;
    for (k = 0; k <= n; ++k) {
      dp1[j] = max(dp1[j], min(minn, Sum + dp[j][k]));
      Sum += a[k];
      minn = min(minn, Sum);
    }
  }
  while (m--) {
    long long b;
    scanf("%lld", &b);
    for (i = 0; i <= n; ++i)
      if (dp1[i] >= -b) break;
    printf("%d\n", i);
  }
}
