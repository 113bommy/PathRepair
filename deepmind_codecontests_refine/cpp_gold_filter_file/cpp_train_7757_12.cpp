#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long MOD = 1e9 + 7;
const int MAXN = 2005;
long long dp[MAXN][MAXN];
char str[100005];
int main() {
  int n, m;
  scanf("%d%d%s", &n, &m, str);
  dp[1][1] = dp[0][0] = 1;
  for (int i = 2; i <= n - m; i++) {
    for (int j = 0; j <= i; j++) {
      if (j >= 1) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
      dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
    }
  }
  long long now = 0, Min = INF;
  for (int i = 0; i < m; i++) {
    if (str[i] == '(')
      now++;
    else
      now--;
    Min = min(Min, now);
  }
  long long ans = 0;
  for (int i = 0; i <= n - m; i++) {
    for (int j = 0; j <= i; j++) {
      if (j + Min < 0 || j + now > n - m - i) continue;
      ans = (ans + dp[i][j] * dp[n - m - i][j + now] % MOD) % MOD;
    }
  }
  printf("%I64d\n", ans);
}
