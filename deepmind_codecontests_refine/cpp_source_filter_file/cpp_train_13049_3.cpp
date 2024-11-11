#include <bits/stdc++.h>
using namespace std;
int n, a[10];
int MOD = 1000000007;
long long C[101][101];
void comb(int lim) {
  int n, r;
  C[0][0] = 1;
  for (n = 1; n <= lim; n++) {
    C[n][0] = 1;
    for (r = 1; r <= n - 1; r++) {
      C[n][r] = (C[n - 1][r - 1] + C[n - 1][r]) % MOD;
    }
    C[n][n] = 1;
  }
}
int f[10][101];
int main() {
  comb(100);
  scanf("%d", &n);
  for (int i = 0; i < (10); i++) scanf("%d", &a[i]);
  long long r = 0;
  for (int l = 0; l <= n; l++) {
    f[l][9] = (l >= a[9]);
    for (int d = 8; d >= 1; d--) {
      for (int k = a[d]; k <= l; k++) {
        f[l][d] = (f[l][d] + C[l][k] * f[l - k][d + 1]) % MOD;
      }
    }
    for (int k = a[0]; k <= l; k++) {
      f[l][0] = (f[l][0] + C[l - 1][k] * f[l - k][1]) % MOD;
    }
    if (l >= 1) r = (r + f[l][0]) % MOD;
  }
  cout << r << endl;
  return 0;
}
