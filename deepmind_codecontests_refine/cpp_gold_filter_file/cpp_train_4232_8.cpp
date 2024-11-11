#include <bits/stdc++.h>
using namespace std;
char arr[5010];
long long int dp[5010][5010];
long long int s[5010];
const int MOD = (long long int)1e9 + 7;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    if (arr[i] == 'f') {
      dp[i + 1][0] = 0;
      for (int j = 1; j < n; j++) dp[i + 1][j] = dp[i][j - 1];
    } else if (arr[i] == 's') {
      s[0] = dp[i][0];
      for (int j = 1; j < n; j++) {
        s[j] = (dp[i][j] + s[j - 1]);
      }
      dp[i + 1][0] = s[n - 1];
      for (int j = 1; j < n; j++) {
        dp[i + 1][j] = (s[n - 1] - s[j - 1]) % MOD;
      }
    }
  }
  long long int ans = 0;
  for (int k = 0; k < n; k++) ans += dp[n - 1][k] % MOD, ans = ans % MOD;
  printf("%lld\n", ans);
  return 0;
}
