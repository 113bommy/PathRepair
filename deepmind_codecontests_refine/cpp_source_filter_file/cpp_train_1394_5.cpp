#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
int main() {
  ios::sync_with_stdio(0);
  long long n, k;
  cin >> n >> k;
  k /= 50;
  int a[n];
  int x = 0, y = 0;
  long long c[n + 1][n + 1];
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++) c[i][j] = 0;
  for (int i = 0; i <= n; i++) {
    c[i][0] = 1;
    c[i][i] = 1;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j < i; j++) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] /= 50;
    if (a[i] > 1)
      y++;
    else
      x++;
  }
  long long dp[x + 1][y + 1][x + 1][y + 1], sum[y + 1][x + 1];
  for (int i = 0; i <= x; i++)
    for (int j = 0; j <= y; j++) sum[i][j] = 0;
  sum[0][0] = 1;
  for (int step = 1; step < 4 * (n + 1); step++) {
    for (int i = 0; i <= x; i++)
      for (int j = 0; j <= y; j++)
        for (int v = 0; v <= x; v++)
          for (int u = 0; u <= y; u++) dp[i][j][v][u] = 0;
    if (step % 2) {
      for (int i = 0; i <= x; i++)
        for (int j = 0; j <= y; j++)
          if (i + j > 0 && k >= i + 2 * j)
            for (int v = i; v <= x; v++)
              for (int u = j; u <= y; u++)
                dp[i][j][v][u] =
                    (dp[i][j][v][u] + sum[v - i][u - j] * c[x - (v - i)][i] *
                                          c[y - (u - j)][j]) %
                    mod;
      for (int i = 0; i <= x; i++)
        for (int j = 0; j <= y; j++) sum[i][j] = 0;
      for (int i = 0; i <= x; i++)
        for (int j = 0; j <= y; j++)
          for (int v = 0; v <= x; v++)
            for (int u = 0; u <= y; u++)
              sum[v][u] = (sum[v][u] + dp[i][j][v][u]) % mod;
      if (sum[x][y] > 0) {
        cout << step << ' ' << "\n" << sum[x][y] % mod << "\n";
        return 0;
      }
    } else {
      for (int i = 0; i <= x; i++)
        for (int j = 0; j <= y; j++)
          if (i + j > 0 && k >= i + 2 * j)
            for (int v = 0; v + i <= x; v++)
              for (int u = 0; u + j <= y; u++)
                dp[i][j][v][u] =
                    (dp[i][j][v][u] +
                     sum[v + i][u + j] * c[v + i][i] * c[u + j][j]) %
                    mod;
      for (int i = 0; i <= x; i++)
        for (int j = 0; j <= y; j++) sum[i][j] = 0;
      for (int i = 0; i <= x; i++)
        for (int j = 0; j <= y; j++)
          for (int v = 0; v <= x; v++)
            for (int u = 0; u <= y; u++)
              sum[v][u] = (sum[v][u] + dp[i][j][v][u]) % mod;
    }
  }
  cout << -1 << ' ' << 0 << "\n";
}
