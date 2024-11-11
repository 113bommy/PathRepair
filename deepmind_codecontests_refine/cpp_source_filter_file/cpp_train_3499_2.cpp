#include <bits/stdc++.h>
using namespace std;
const int Mod = 1e9 + 7;
int upd(int x) { return x + (x >> 31 & Mod); }
void Pls(int &x, int y) { x = upd(x + y - Mod); }
int N, M, f[55][105], h[55][55], inv[55];
int main() {
  inv[0] = inv[1] = 1;
  for (int i = 2; i <= 51; i++)
    inv[i] = 1ll * (Mod - Mod / i) * inv[Mod % i] % Mod;
  for (int i = 1; i <= 51; i++) inv[i] = 1ll * inv[i - 1] * inv[i] % Mod;
  cin >> N >> M;
  f[0][1] = 1;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < i; j++)
      for (int k = 1; k <= i; k++)
        if (f[j][k])
          for (int l = 0; l < i && j + l + 1 <= N; l++)
            for (int m = 1; m <= i; m++)
              if (f[l][m] && (j == i - 1 || l == i - 1))
                Pls(h[j + l + 1][min(k, m)], 1ll * f[j][k] * f[l][m] % Mod);
    for (int j = 1; j <= i + 1; j++)
      if (h[i][j])
        for (int k = N; k >= 0; k--)
          for (int l = k + 1; l >= 0; l--)
            if (f[k][l]) {
              int dn = 1;
              for (int m = 1; k + m * i <= N && l + m * j <= N; m++) {
                dn = 1ll * (m - 1 + h[i][j]) * dn % Mod;
                Pls(f[k + m * i][l + m * j],
                    1ll * f[k][l] * dn % Mod * inv[m] % Mod);
              }
            }
  }
  cout << f[N][M] << endl;
  return 0;
}
