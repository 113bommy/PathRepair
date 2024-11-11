#include <bits/stdc++.h>
using namespace std;
const int maxn = int(1e5) + 7;
const int inf = 1 << 30;
const int mod = int(1e9) + 7;
int n, m, d[44][44], res[44][44], mat[44][44], t[44][44], a[44], b[44];
void doit(int x[44][44], int y[44][44], int z[44][44]) {
  for (int i = 0; i <= 2 * n; i++)
    for (int j = 0; j <= 2 * n; j++) {
      t[i][j] = inf;
      for (int k = 0; k <= 2 * n; k++)
        if (x[i][k] != inf && y[k][j] != inf)
          t[i][j] = min(t[i][j], x[i][k] + y[k][j]);
    }
  for (int i = 0; i <= 2 * n; i++)
    for (int j = 0; j <= 2 * n; j++) z[i][j] = t[i][j];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int st = 0; st <= 2 * n; st++) {
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= 2 * n; j++) d[i][j] = inf;
    d[0][st] = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j <= 2 * n; j++) {
        if (d[i][j] == inf) continue;
        if (j + 1 <= 2 * n)
          d[i + 1][j + 1] = min(d[i + 1][j + 1], d[i][j] + a[i]);
        if (j - 1 >= 0) d[i + 1][j - 1] = min(d[i + 1][j - 1], d[i][j] + b[i]);
      }
    for (int i = 0; i <= 2 * n; i++) mat[st][i] = d[n][i];
  }
  for (int i = 0; i <= 2 * n; i++)
    for (int j = 0; j <= 2 * n; j++) res[i][j] = inf;
  res[0][0] = 0;
  while (m > 0) {
    if (m & 1) doit(res, mat, res);
    doit(mat, mat, mat);
    m >>= 1;
  }
  cout << res[0][0];
  return 0;
}
