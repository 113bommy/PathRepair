#include <bits/stdc++.h>
using namespace std;
const int N = 407;
int n, d, p, g[N];
long long c[N][N], dp[N][N], og[N][N];
int main() {
  cin >> n >> d >> p, c[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % p;
  }
  dp[1][0] = 1, og[1][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= i; k++)
        dp[i][j] = (dp[i][j] + 1ll * dp[i - k][j - 1] * og[k][d - 1] % p *
                                   c[i - 2][k - 1]) %
                   p;
      og[i][j] = (og[i][j - 1] + dp[i][j]) % p;
    }
  int opt = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= n; j++)
      for (int k = 0; j + k <= d; k++)
        opt = (opt + 1ll * dp[i][j] * dp[n - i + 1][k]) % p;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % p;
  for (int i = 0; i < n; i++) {
    int j = n - i;
    if (j > 0) opt = (opt - 1ll * dp[i][d - 1] * dp[j][d - 1]) % p;
  }
  opt = (opt + p) % p;
  cout << 2ll * opt % p * n % p * (n - 1) % p << endl;
  return 0;
}
