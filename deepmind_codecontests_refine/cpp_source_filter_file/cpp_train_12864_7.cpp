#include <bits/stdc++.h>
using namespace std;
long long dp[100005];
long long tim[100005];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%lld", tim + i);
  long long sum = 0;
  for (int i = 1; i <= n; ++i) {
    dp[i] = dp[i - 1] + 20;
    for (int j = i - 1; j >= 1; --j) {
      if (tim[i] - tim[j] < 90)
        dp[i] = min(dp[i], dp[j] + 50);
      else if (tim[i] - tim[j] < 1440)
        dp[i] = min(dp[i], dp[j] + 120);
      else
        break;
    }
    printf("%lld\n", dp[i] - sum);
    sum = dp[i];
  }
  return 0;
}
