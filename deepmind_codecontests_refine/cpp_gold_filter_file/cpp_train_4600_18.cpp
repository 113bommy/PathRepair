#include <bits/stdc++.h>
using namespace std;
const int mod = 998244853;
const int N = 2001;
int n, m, f[N][N][2], res;
int main() {
  ios_base::sync_with_stdio();
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  f[0][0][0] = f[0][0][1] = 1;
  for (int k = 1; k <= n + m; k++)
    for (int i = max(0, k - m); i <= min(n, k); i++) {
      int j = k - i;
      if (i - j < 0) {
        if (i > 0) f[i][j][0] = (f[i][j][0] + f[i - 1][j][0]) % mod;
        if (j > 0) f[i][j][0] = (f[i][j][0] + f[i][j - 1][0]) % mod;
      } else {
        if (i > 0) f[i][j][1] = (f[i][j][1] + f[i - 1][j][1]) % mod;
        if (j > 0) f[i][j][1] = (f[i][j][1] + f[i][j - 1][1]) % mod;
      }
    }
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= min(i - 1, m); j++)
      res =
          (((long long)f[i][j][1] * f[n - i][m - j][0] % mod) * (i - j) + res) %
          mod;
  cout << res;
  return 0;
}
