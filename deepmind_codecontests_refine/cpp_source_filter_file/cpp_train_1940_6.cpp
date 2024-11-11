#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int mat[505][505], d[505][505], f[505][505];
int main() {
  int i, j, k, lg, n;
  cin >> n;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) cin >> mat[i][j];
  for (i = 1; i <= n; i++) {
    d[i][i] = 1;
    f[i][i] = 1;
  }
  for (lg = 2; lg <= n; lg++) {
    for (i = 1; i + lg - 1 <= n; i++) {
      j = i + lg - 1;
      for (k = i; k <= j; k++) f[i][j] = (f[i][j] + d[i][k] * f[k][j]) % MOD;
      if (mat[i][j])
        for (k = i; k < j; k++)
          d[i][j] = (d[i][j] + f[i][k] * f[k + 1][j]) % MOD;
      f[i][j] = (f[i][j] + d[i][j]) % MOD;
    }
  }
  cout << f[1][n];
}
