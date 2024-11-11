#include <bits/stdc++.h>
using namespace std;
const int M = 100 + 10;
long long int MOD = 1000000000 + 7;
long long int cn[M][M * M];
long long int dp[M][M * M];
long long int ex[M];
long long int cnex[M][M];
long long int fastexp(long long int a, long long int n) {
  long long int ans = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      ans = (ans * a) % MOD;
    }
    n = n / 2;
    a = (a * a) % MOD;
  }
  return ans;
}
int main() {
  int n, k;
  long long int m;
  cin >> n >> m >> k;
  cn[1][0] = cn[1][1] = 1;
  for (int row = 2; row <= n; row++) {
    cn[row][0] = 1;
  }
  for (int row = 2; row <= n; row++) {
    for (int col = 1; col <= n; col++) {
      long long int t1 = cn[row - 1][col - 1];
      long long int t2 = cn[row - 1][col];
      cn[row][col] = (t1 + t2) % MOD;
    }
  }
  long long int q = m / n;
  long long int r = m % n;
  for (int i = 1; i <= n; i++) {
    ex[i] = q + (r >= i);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      cnex[i][j] = fastexp(cn[n][j], ex[i]);
    }
  }
  for (int col = 0; col <= k; col++) {
    dp[1][col] = cnex[1][col];
  }
  for (int row = 2; row <= n; row++) {
    for (int col = 0; col <= k; col++) {
      long long int ans = 0;
      for (int d = 0; d <= n; d++) {
        if (col - d >= 0) {
          long long int x1 = dp[row - 1][col - d];
          long long int x2 = cnex[row][d];
          long long int x = (x1 * x2) % MOD;
          ans = (ans + x) % MOD;
        }
      }
      dp[row][col] = ans;
    }
  }
  cout << dp[n][k] << endl;
  return 0;
}
