#include <bits/stdc++.h>
using namespace std;
const int N = 210;
int n, d, mod, C[N][N], f[N][N], s[N];
int main() {
  cin >> n >> d >> mod;
  for (int i = 0; i <= n; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
  }
  f[1][0] = s[1] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < d; j++)
      for (int k = 1; k < i; k++)
        f[i][j + 1] =
            (f[i][j + 1] + 1ll * s[k] * f[i - k][j] % mod * C[i - 2][k - 1]) %
            mod;
    for (int j = 0; j < d; j++) s[i] = (s[i] + f[i][j]) % mod;
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= d; j++)
      for (int k = 0; j + k <= d; k++)
        if (k ^ 1) ans = (ans + 1ll * f[i + 1][j] * f[n - i][k]) % mod;
  cout << 2ll * n * (n - 1) % mod * ans % mod;
  return 0;
}
