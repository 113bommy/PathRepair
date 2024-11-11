#include <bits/stdc++.h>
using namespace std;
int n, k;
long long dp[510][510], res, ans[510];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    dp[i][0] = 1;
    for (int j = 1; j <= i; j++)
      for (int k = 1; k <= min(j, i); k++)
        dp[i][j] = (dp[i][j] + dp[i][j - k]) % 998244353;
  }
  for (int i = 1; i <= n; i++)
    ans[i] = (dp[i][n] - dp[i - 1][n] + 998244353) % 998244353;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (i * j < k) res = (res + ans[i] * ans[j]) % 998244353;
  printf("%I64d", res * 2ll % 998244353);
}
