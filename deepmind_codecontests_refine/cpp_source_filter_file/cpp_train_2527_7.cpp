#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
const int mod = 1e9 + 7;
char s[N];
long long dp[N][3];
int main() {
  long long now = 1;
  int n;
  scanf("%d", &n);
  scanf(" %s", s + 1);
  for (int i = 1; i <= n; i++) {
    dp[i][0] = dp[i - 1][0];
    dp[i][1] = dp[i - 1][1];
    dp[i][2] = dp[i - 1][2];
    if (s[i] == 'a')
      dp[i][0] = (dp[i - 1][0] + 1) % mod;
    else if (s[i] == 'b')
      dp[i][1] = (dp[i - 1][1] + dp[i - 1][0]) % mod;
    else if (s[i] == 'c')
      dp[i][2] = (dp[i - 1][2] + dp[i - 1][1]) % mod;
    else {
      dp[i][0] = (dp[i - 1][0] * 3 % mod + now) % mod;
      dp[i][1] = (dp[i - 1][1] * 3 % mod + dp[i - 1][0]) % mod;
      dp[i][2] = (dp[i - 1][2] * 3 % mod + dp[i - 1][1]) % mod;
      now = now * 3 % mod;
    }
  }
  printf("%lld\n", dp[n][2]);
}
