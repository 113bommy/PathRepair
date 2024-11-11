#include <bits/stdc++.h>
long long dp[500100];
char s[100100];
int n;
int main() {
  scanf("%d", &n);
  scanf("%s", s + 1);
  long long ans = 0, c = 0, q = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '1') {
      c++;
      if (c == 1) {
        dp[1] = dp[1] + dp[0] + 1;
        ans = ans + q + dp[0] + 1;
        q = q + dp[0] + 1;
        dp[0] = 0;
      } else {
        dp[c] = dp[c] + dp[c - 1];
        ans = ans + q + c * dp[c - 1] - (dp[c - 1] - 1) * (c - 1);
        q = q + c * dp[c - 1] - (dp[c - 1] - 1) * (c - 1);
        dp[c - 1] = 1;
      }
    } else {
      ans = ans + q;
      c = 0;
      dp[0]++;
    }
  }
  printf("%lld\n", ans);
}
