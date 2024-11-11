#include <bits/stdc++.h>
using namespace std;
long long i, i1, j, k, k1, t, n, m, res, flag[10], a, b, s;
long long f[100010], w[100010], jm[35][100010], sts[35][100010],
    stm[35][100010];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (i = 1; i <= n; i++) {
    cin >> f[i];
    f[i]++;
  }
  for (i = 1; i <= n; i++) {
    cin >> w[i];
  }
  for (j = 1; j <= n; j++) {
    jm[0][j] = f[j];
    sts[0][j] = w[j];
    stm[0][j] = w[j];
  }
  for (i = 1; i < 35; i++) {
    for (j = 1; j <= n; j++) {
      jm[i][j] = jm[i - 1][jm[i - 1][j]];
      sts[i][j] = sts[i - 1][j] + sts[i - 1][jm[i - 1][j]];
      stm[i][j] = min(stm[i - 1][j], stm[i - 1][jm[i - 1][j]]);
    }
  }
  for (i = 1; i <= n; i++) {
    a = 0;
    b = (long long)1e18;
    s = i;
    for (j = 0; j < 35; j++) {
      if ((k >> j) & 1) {
        a += sts[j][s];
        b = min(b, stm[j][s]);
        s = jm[j][s];
      }
    }
    cout << a << ' ' << b << "\n";
  }
  return 0;
}
