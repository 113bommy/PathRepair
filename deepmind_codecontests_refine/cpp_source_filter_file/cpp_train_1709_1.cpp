#include <bits/stdc++.h>
using namespace std;
const int maxN = 3000;
const long long MOD = 1000 * 1000 * 1000 + 7;
long long n, k, dp[maxN][maxN], sum[maxN][maxN], s[maxN], ans;
char c;
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> c;
    s[i] = c;
  }
  sum[0][0] = dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= k; j++) {
      dp[i + 1][j] += sum[i][j] * (s[i] - 'a');
      dp[i + 1][j] %= MOD;
      for (int x = 0; i - x >= 0 && j >= (x + 1) * (n - i); x++)
        dp[i + 1][j] =
            (dp[i + 1][j] + dp[i - x][j - (x + 1) * (n - i)] * ('z' - s[i])) %
            MOD;
      sum[i + 1][j] += (sum[i][j] + dp[i + 1][j]) % MOD;
    }
  }
  for (int i = 0; i <= n; i++) ans = (ans + dp[i][k]) % MOD;
  cout << ans % MOD << endl;
}
