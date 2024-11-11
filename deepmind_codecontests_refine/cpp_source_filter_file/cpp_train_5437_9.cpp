#include <bits/stdc++.h>
using namespace std;
const int NMAX = 1001;
const int MMAX = 11;
const int MOD = 1000000007;
int dp[NMAX][NMAX][MMAX];
int add(int a, int b) {
  a = a + b;
  if (a >= MOD) return a - MOD;
  return a;
}
int main() {
  int n, m, i, j, k, sum;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++)
    for (j = i; j <= n; j++) dp[i][j][1] = 1;
  for (k = 2; k <= m; k++) {
    for (i = 1; i <= n; i++) {
      for (j = n; j >= i; j--) {
        dp[i][j][k] =
            (((dp[i][j][k - 1] + dp[i - 1][j][k]) % MOD + dp[i][j + 1][k]) %
                 MOD +
             MOD - dp[i - 1][j + 1][k]) %
            MOD;
      }
    }
  }
  sum = 0;
  for (i = 1; i <= n; i++)
    for (j = i; j <= n; j++) sum = (sum + dp[i][j][m]) % MOD;
  printf("%d", sum);
  return 0;
}
