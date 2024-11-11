#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
int p[505][505], f[505][505], c[505][505];
int main() {
  for (int i = 0; i <= 500; i++) {
    p[i][0] = 1;
    for (int j = 1; j <= 500; j++) p[i][j] = 1ll * p[i][j - 1] * i % mod;
  }
  for (int i = 0; i <= 500; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++)
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
  }
  int n, x;
  cin >> n >> x;
  for (int i = 1; i <= x; i++) f[0][i] = 1;
  for (int i = 2; i <= n; i++)
    for (int j = 1; j <= x; j++)
      if (i > j)
        f[i][j] = p[j][i];
      else
        for (int k = 0; k <= i; k++)
          f[i][j] = (f[i][j] + 1ll * c[i][k] * p[i - 1][k] % mod *
                                   f[i - k][j - i + 1] % mod) %
                    mod;
  cout << f[n][x];
  return 0;
}
