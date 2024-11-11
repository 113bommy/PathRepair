#include <bits/stdc++.h>
using namespace std;
int c[222][222];
int f[111][55][111][55];
const int mod = 1e9 + 7;
int main() {
  for (int i = 0; i < 202; i++) c[i][0] = 1;
  for (int i = 1; i < 202; i++)
    for (int j = 1; j <= i; j++)
      c[i][j] = min(c[i - 1][j - 1] + c[i - 1][j], 111);
  int n, m, K;
  scanf("%d%d%d", &n, &m, &K);
  for (int i = 1; i <= n / 2; i++) f[1][i][1][i] = 1;
  for (int i = 1; i < m; i++)
    for (int j = 1; j <= n / 2; j++)
      for (int k = 1; k <= K; k++)
        for (int l = 1; l <= n / 2; l++)
          if (f[i][j][k][l]) {
            for (int p = 1; p <= n / 2; p++) {
              if (j + p > n / 2) break;
              if (k * c[l + p - 1][p] > K) continue;
              f[i + 1][j + p][k * c[l + p - 1][p]][p] += f[i][j][k][l];
              if (f[i + 1][j + p][k * c[l + p - 1][p]][p] >= mod)
                f[i + 1][j + p][k * c[l + p - 1][p]][p] -= mod;
            }
          }
  int ans = 0;
  for (int i = 1; i < m; i++)
    for (int j = 1; j <= n / 2; j++)
      for (int k = 1; k <= K; k++)
        for (int l = 1; l <= n / 2; l++)
          ans = (ans + f[i][j][k][l] * (m - i + 1ll)) % mod;
  printf("%d", ans);
}
