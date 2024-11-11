#include <bits/stdc++.h>
using namespace std;
const int N = 4019;
const int Mod = 998244353;
int n, m, l, f[N][N][2], inv[N];
int main() {
  cin >> n >> m >> l;
  f[0][0][0] = 1;
  for (int i = 0; i <= n * 2; i++)
    for (int j = 0; j <= n; j++)
      for (int k = 0; k <= 1; k++)
        if (f[i][j][k]) {
          (f[i + 1][j + 1][k] += f[i][j][k]) %= Mod;
          if (j) (f[i + 1][j - 1][k] += 1ll * f[i][j][k] * j) %= Mod;
          if (!k && j >= m) (f[i + 1][j][1] += f[i][j][0]) %= Mod;
        }
  int ans = f[2 * n + 1][0][1];
  inv[1] = 1;
  for (int i = 2; i <= n * 2 + 1; i++)
    inv[i] = 1ll * (Mod - Mod / i) * inv[Mod % i] % Mod,
    ans = 1ll * ans * inv[i] % Mod;
  for (int i = 1; i <= n; i++) ans = 1ll * ans * 2 % Mod * i % Mod;
  cout << (1ll * ans * l % Mod) << endl;
  return 0;
}
