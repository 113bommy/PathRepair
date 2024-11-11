#include <bits/stdc++.h>
using namespace std;
const int N = 1002, D = 12;
int n, d, mod, inv, C[D], dp[D][N], res[D][N];
long long pow(long long x, long long y, long long mod) {
  return (!y ? 1 : pow(x * x % mod, y / 2, mod) * (y & 1 ? x : 1)) % mod;
}
int main() {
  cin >> n >> d >> mod;
  dp[0][1] = 1;
  inv = mod / 2 + 1;
  if (n == 2) return cout << 1, 0;
  for (int i = 1; i < (n + 1) / 2; i++) {
    int num = max(dp[d - 1][i], int(i == 1));
    C[0] = 1;
    for (int i = 1; i < D; i++)
      C[i] = 1ll * C[i - 1] * pow(i, mod - 2, mod) % mod * (num + i - 1) % mod;
    for (int j = n - i; j >= 1; j--)
      for (int k = 1; k * i + j <= n; k++)
        for (int o = 0; o < d + 1; o++)
          if (o + k < D)
            dp[o + k][j + k * i] =
                (dp[o + k][j + k * i] + 1ll * dp[o][j] * C[k] % mod) % mod;
  }
  cout << (dp[d][n] +
           ((n + 1) & 1) * (1ll * dp[d - 1][n / 2] * (dp[d - 1][n / 2] + 1) %
                            mod * inv % mod)) %
              mod;
}
