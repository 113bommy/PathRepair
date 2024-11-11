#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 15, MOD = 1e9 + 7;
int a[N], f[105][N], c[N][105];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, l, r, k;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 0; i <= n; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i && j <= 100; j++) {
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
    }
  }
  while (m--) {
    cin >> l >> r >> k;
    f[k][l] = (f[k][l] + 1) % MOD;
    for (int j = 0; j <= k; j++) {
      f[j][r + 1] = (MOD + f[j][r + 1] - c[r - l + k - j][k - j]) % MOD;
    }
  }
  for (int i = 100; i >= 0; i--) {
    for (int j = 1; j <= n; j++) {
      f[i][j] = (1ll * f[i][j] + f[i][j - 1] + f[i + 1][j]) % MOD;
    }
  }
  for (int i = 1; i <= n; i++) cout << (a[i] + f[0][i]) % MOD << " ";
}
