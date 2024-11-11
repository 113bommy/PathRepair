#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
int n, m, a[N][N], f[N][N], d[N][N], ff[N][N], dd[N][N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      cin >> a[i][j], f[i][j] = a[i][j] + max(f[i - 1][j], f[i][j - 1]);
  for (int i = n; i >= 1; i--)
    for (int j = 1; j <= m; j++)
      d[i][j] = a[i][j] + max(d[i + 1][j], d[i][j - 1]);
  for (int i = n; i >= 1; i--)
    for (int j = m; j >= 1; j--)
      ff[i][j] = a[i][j] + max(ff[i + 1][j], ff[i][j + 1]);
  for (int i = 1; i <= n; i++)
    for (int j = m; j >= 1; j--)
      dd[i][j] = a[i][j] + max(dd[i][j + 1], dd[i - 1][j]);
  int res = 0;
  for (int i = 2; i < n; i++) {
    for (int j = 2; j < m; j++) {
      int t1 = f[i][j - 1] + d[i + 1][j] + ff[i][j + 1] + dd[i - 1][j];
      int t2 = f[i - 1][j] + d[i][j - 1] + dd[i][j + 1] + ff[i + 1][j];
      int tot = max(t1, t2);
      res = max(res, tot);
    }
  }
  cout << res << '\n';
  return 0;
}
