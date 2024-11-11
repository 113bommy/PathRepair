#include <bits/stdc++.h>
using namespace std;
const long long M = 1000000007;
const int Maxn = 1010;
long long f[Maxn][Maxn][2][2];
long long ans[Maxn];
long long fac[Maxn];
long long c[Maxn][Maxn];
int n, k;
inline void init() {
  c[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % M;
  }
  fac[0] = fac[1] = 1;
  for (int i = 2; i <= n; i++) fac[i] = (long long)i * fac[i - 1] % M;
}
inline void dp() {
  f[0][0][0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 2; b++) {
          f[i][j][b][0] = (f[i][j][b][0] + f[i - 1][j][a][b]) % M;
          if (j >= 1 && i < n)
            f[i][j][b][1] = (f[i][j][b][1] + f[i - 1][j - 1][a][b]) % M;
          if (a == 0 && i > 1 && j >= 1)
            f[i][j][b][0] = (f[i][j][b][0] + f[i - 1][j - 1][a][b]) % M;
        }
      }
    }
  }
  for (int j = 0; j <= n; j++)
    for (int a = 0; a < 2; a++)
      for (int b = 0; b < 2; b++) ans[j] = (ans[j] + f[n][j][a][b]) % M;
  for (int i = 0; i <= n; i++) ans[i] = (ans[i] * fac[n - i]) % M;
  for (int i = n - 1; i >= 0; i--)
    for (int j = i + 1; j <= n; j++)
      ans[i] = (ans[i] - ans[j] * c[j][i] % M + M) % M;
  cout << ans[k] << endl;
}
int main() {
  scanf("%d%d", &n, &k);
  init();
  dp();
  return 0;
}
