#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18, MOD = 1e9 + 7, MOD2 = 1e6 + 3;
long long d[101][1001], n, m, x[100], y[100], c[1001][1001];
long long C(long long n, long long k) {
  if (!k || n == k) return 1;
  if (c[n][k] != -1) return c[n][k];
  c[n][k] = C(n - 1, k - 1) + C(n - 1, k);
  if (c[n][k] >= MOD) c[n][k] -= MOD;
  return c[n][k];
}
int main() {
  memset(c, -1, sizeof(c));
  cin >> n;
  for (int i = 0; i < n; i++) cin >> x[i];
  for (int i = 0; i < n; i++) cin >> y[i];
  m = accumulate(x, x + n, 0);
  d[0][0] = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= m; j++) {
      for (int k = 0; k <= min(j + x[i], y[i]); k++) {
        d[i + 1][j + x[i] - k] += C(j + x[i], k) * d[i][j] % MOD;
        if (d[i + 1][j + x[i] - k] >= MOD) d[i + 1][j + x[i] - k] -= MOD;
      }
    }
  for (int i = 0; i < n; i++) {
    d[n][0] = d[n][0] * C(m, x[i]) % MOD;
    m -= x[i];
  }
  cout << d[n][0];
}
