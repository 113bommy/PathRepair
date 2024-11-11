#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
void add(long long &a, long long b) {
  a += b;
  if (a < 0) a += MOD;
  if (a >= MOD) a -= MOD;
}
int n, k;
long long c[1020][1020], dp[1020][1020][4];
int main() {
  long long *f = new long long[1010];
  for (int i = 0; i <= 1000; ++i) f[i] = 0;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) c[i][0] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
  dp[0][0][2] = 1;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      for (int q = 0; q < 4; ++q) {
        if (q & 1) add(dp[i + 1][j + 1][q / 2 + 2], dp[i][j][q]);
        if (i < n - 1) add(dp[i + 1][j + 1][q / 2], dp[i][j][q]);
        add(dp[i + 1][j][q / 2 + 2], dp[i][j][q]);
      }
  for (int i = 0; i <= n; ++i) {
    for (int q = 0; q < 4; ++q) add(f[i], dp[n][i][q]);
    for (int m = 2; m <= n - i; ++m) f[i] = f[i] * m % MOD;
  }
  for (int i = n - 1; i >= 0; --i)
    for (int j = i + 1; j <= n; ++j) {
      long long t = f[j] * c[j][i] % MOD;
      add(f[i], -t);
    }
  cout << f[k] << endl;
}
