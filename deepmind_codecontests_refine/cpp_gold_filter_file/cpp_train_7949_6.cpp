#include <bits/stdc++.h>
using namespace std;
const long long MOD = (long long)1e9 + 7;
long long cnt[20], dp[15][15][2];
int dig[20], len;
void prepare(long long m) {
  memset(dp, 0, sizeof(dp));
  memset(cnt, 0, sizeof(cnt));
  len = 0;
  while (m) dig[++len] = m % 10, m /= 10;
  for (int i = 0; i < dig[len]; i++) {
    if (i == 4 || i == 7)
      dp[len][1][0]++;
    else
      dp[len][0][0]++;
  }
  if (dig[len] == 4 || dig[len] == 7)
    dp[len][1][1]++;
  else
    dp[len][0][1]++;
  for (int i = len; i > 1; i--) {
    for (int k = 0; k <= len + 1 - i; k++) {
      for (int j = 0; j < 10; j++) {
        if (j == 4 || j == 7)
          dp[i - 1][k + 1][0] += dp[i][k][0];
        else
          dp[i - 1][k][0] += dp[i][k][0];
      }
      for (int j = 0; j < dig[i - 1]; j++) {
        if (j == 4 || j == 7)
          dp[i - 1][k + 1][0] += dp[i][k][1];
        else
          dp[i - 1][k][0] += dp[i][k][1];
      }
      if (dig[i - 1] == 4 || dig[i - 1] == 7)
        dp[i - 1][k + 1][1] += dp[i][k][1];
      else
        dp[i - 1][k][1] += dp[i][k][1];
    }
  }
  for (int i = 0; i <= len; i++) cnt[i] = dp[1][i][0] + dp[1][i][1];
  cnt[0]--;
  for (int i = 0; i < len; i++) cnt[i] %= MOD;
}
long long DFS(int d, int sum, int n) {
  if (sum >= n) return 0;
  if (d == 6) return 1;
  long long ans = 0;
  for (int i = 0; i + sum < n; i++) {
    cnt[i]--;
    ans = (ans + (cnt[i] + 1) * DFS(d + 1, i + sum, n)) % MOD;
    cnt[i]++;
  }
  return ans;
}
int main() {
  long long m;
  cin >> m;
  prepare(m);
  long long ans = 0;
  for (int i = 1; i <= len; i++) ans = (ans + cnt[i] * DFS(0, 0, i)) % MOD;
  cout << ans << endl;
  return 0;
}
