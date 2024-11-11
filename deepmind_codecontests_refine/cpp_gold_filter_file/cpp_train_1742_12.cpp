#include <bits/stdc++.h>
using namespace std;
int dp[10010][210];
int main() {
  long long n;
  long long ans = 0;
  scanf("%lld", &n);
  {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int k = 1; k <= min(n, (long long)200); k++)
      for (int i = 10000; i >= 0; i--) {
        int x = 1;
        if (i - x >= 0 && dp[i - x][k - 1] == 1) dp[i][k] = 1;
        x = 5;
        if (i - x >= 0 && dp[i - x][k - 1] == 1) dp[i][k] = 1;
        x = 10;
        if (i - x >= 0 && dp[i - x][k - 1] == 1) dp[i][k] = 1;
        x = 50;
        if (i - x >= 0 && dp[i - x][k - 1] == 1) dp[i][k] = 1;
      }
    for (int i = 10000; i >= 0; i--)
      if (dp[i][min(n, (long long)200)]) ans++;
  }
  if (n < 200) {
    printf("%lld\n", ans);
  } else
    printf("%lld\n", ans + (n - 200) * 49);
  return 0;
}
