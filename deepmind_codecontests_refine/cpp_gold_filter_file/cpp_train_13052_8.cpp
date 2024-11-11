#include <bits/stdc++.h>
using namespace std;
int n, k, comb[1005][1005], fact[1005];
int dp[1005][1005][4];
void add(int &a, int b) {
  a += b;
  if (a >= 1000000007) a -= 1000000007;
}
void dec(int &a, int b) {
  a -= b;
  if (a < 0) a += 1000000007;
}
int main() {
  comb[0][0] = 1;
  for (int i = 1; i <= 1000; i++) {
    comb[i][0] = comb[i][i] = 1;
    for (int j = 1; j < i; j++) {
      comb[i][j] = comb[i - 1][j - 1];
      add(comb[i][j], comb[i - 1][j]);
    }
  }
  fact[0] = 1;
  for (int i = 1; i <= 1000; i++) fact[i] = 1LL * fact[i - 1] * i % 1000000007;
  scanf("%d%d", &n, &k);
  dp[1][0][0] = 1;
  for (int i = 1; i < n; i++)
    for (int j = 0; j <= i; j++)
      for (int mask = 0; mask < 4; mask++) {
        if (!dp[i][j][mask]) continue;
        add(dp[i + 1][j][0], dp[i][j][mask]);
        if (!mask) add(dp[i + 1][j + 2][3], dp[i][j][mask]);
        if (!(mask & 1)) add(dp[i + 1][j + 1][2], dp[i][j][mask]);
        if (!(mask & 2)) add(dp[i + 1][j + 1][1], dp[i][j][mask]);
      }
  for (int i = 0; i <= n; i++) {
    for (int j = 1; j < 4; j++) add(dp[n][i][0], dp[n][i][j]);
    dp[n][i][0] = 1LL * dp[n][i][0] * fact[n - i] % 1000000007;
  }
  for (int i = n; i >= 0; i--)
    for (int j = i + 1; j <= n; j++)
      dec(dp[n][i][0], 1LL * dp[n][j][0] * comb[j][i] % 1000000007);
  printf("%d\n", dp[n][k][0]);
  return 0;
}
