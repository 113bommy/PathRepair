#include <bits/stdc++.h>
using namespace std;
const int max_n = 100007, max_k = 107, mod = 1000000007;
int i, j, p, n, m, l, r, k;
long long int a[max_n], b[max_n][max_k], C[max_n][max_k];
void Pas() {
  C[0][0] = 1;
  for (i = 1; i < max_n; i++) {
    for (j = 0; j <= min(i, 100); j++) {
      if (j == 0 || i == j) {
        C[i][j] = 1;
      } else {
        C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
      }
    }
  }
}
int main() {
  Pas();
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (i = 1; i <= m; i++) {
    cin >> l >> r >> k;
    for (j = 0, p = k; j <= k; j++, p--) {
      b[l][j] = (b[l][j] + C[k][p]) % mod;
      b[r + 1][j] = (b[r + 1][j] - C[r + 1 - l + k][p]) % mod;
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 0; j <= 100; j++) {
      b[i][j] = (b[i][j] + b[i - 1][j] + b[i - 1][j + 1]) % mod;
    }
    cout << (a[i] + b[i][0] + mod) % mod << " ";
  }
  return 0;
}
