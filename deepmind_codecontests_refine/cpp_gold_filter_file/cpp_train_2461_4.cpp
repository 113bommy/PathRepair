#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long dp[705][705][2];
char s[705];
long long ans = 0;
int main() {
  scanf("%s", s + 1);
  int len = strlen(s + 1);
  for (int k = 1; k <= 9; k++) {
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= s[1] - '0'; i++) {
      bool ty2 = (i >= k), ty3 = (i == (s[1] - '0'));
      dp[1][ty2][ty3] += 1;
    }
    for (int i = 1; i <= len; i++) {
      for (int j = 0; j <= len; j++) {
        for (int st = 0; st <= 1; st++) {
          if (!dp[i][j][st]) continue;
          for (int add = 0; add <= (st ? (s[i + 1] - '0') : 9); add++) {
            dp[i + 1][j + (add >= k)][st && (add == (s[i + 1] - '0'))] +=
                dp[i][j][st];
            dp[i + 1][j + (add >= k)][st && (add == (s[i + 1] - '0'))] %= mod;
          }
        }
      }
    }
    long long tmp = 0;
    for (int j = 0; j <= len; j++) {
      ans += (dp[len][j][0] + dp[len][j][1]) % mod * tmp % mod;
      ans %= mod;
      tmp = (tmp * 10) + 1;
      tmp %= mod;
    }
  }
  printf("%lld", ans);
  return 0;
}
