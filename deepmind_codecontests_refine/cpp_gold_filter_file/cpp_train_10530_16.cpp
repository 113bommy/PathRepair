#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1, K = 15, M = 4;
const int MOD = 1e9 + 7;
int n, k, m, add, ans;
int dp[N][K][1 << M];
int calc(int x) {
  int sum = 0;
  do
    if (x & 1) sum++;
  while (x >>= 1);
  return sum;
}
int main() {
  scanf("%d%d%d", &n, &k, &m);
  dp[0][0][0] = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= k; j++)
      for (int sta = 0; sta < 1 << m; sta++) {
        (dp[i + 1][j][sta >> 1] += dp[i][j][sta]) %= MOD;
        add = dp[i][j][sta] * (1ll + calc(sta)) % MOD;
        (dp[i + 1][j + 1][(sta >> 1) | (1 << (m - 1))] += add) %= MOD;
      }
  for (int sta = 0; sta < 1 << m; sta++) (ans += dp[n][k][sta]) %= MOD;
  printf("%d\n", ans);
  return 0;
}
