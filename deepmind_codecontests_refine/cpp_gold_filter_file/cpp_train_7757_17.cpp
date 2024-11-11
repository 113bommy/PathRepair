#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
char web[100010];
int n, m, sum1, sum2, k;
long long dp[maxn][maxn];
void init() {
  dp[0][0] = 1LL;
  for (int i = 1; i < maxn; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (j == 0)
        dp[i][j] = dp[i - 1][j + 1] % mod;
      else if (j == i)
        dp[i][j] = dp[i - 1][j - 1] % mod;
      else
        dp[i][j] = (dp[i - 1][j + 1] + dp[i - 1][j - 1]) % mod;
    }
  }
}
int main() {
  init();
  long long ans = 0;
  scanf("%d%d", &n, &m);
  scanf("%s", web);
  int haha = inf;
  for (int i = 0; i < m; ++i) {
    if (web[i] == '(')
      ++sum1;
    else
      ++sum2;
    haha = min(haha, sum1 - sum2);
  }
  k = n - m;
  for (int i = 0; i <= k; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (j + haha >= 0 && j + sum1 - sum2 <= k - i) {
        ans = (ans + dp[i][j] * dp[k - i][j + sum1 - sum2] % mod) % mod;
      }
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
