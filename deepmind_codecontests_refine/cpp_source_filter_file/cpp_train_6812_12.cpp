#include <bits/stdc++.h>
using namespace std;
const int N = 105, inf = 0xcfcfcfcf;
string a[N];
int n, m, k;
int f[N][N][15], pre[N][N][15];
string solve(int i, int j, int p) {
  if (i == n) return "";
  if (pre[i][j][p] == j + 1)
    return solve(i + 1, j + 1, ((p - (a[i][j] - '0')) % k + k) % k) + 'L';
  else
    return solve(i + 1, j - 1, ((p - (a[i][j] - '0')) % k + k) % k) + 'R';
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> n >> m >> k;
  ++k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  int ans = inf, pos = 0;
  string path;
  for (int s = 1; s <= m; ++s) {
    memset(f, 0xcf, sizeof(f));
    f[n][s][(a[n][s - 1] - '0') % k] = (a[n][s - 1] - '0') / k;
    for (int i = n; i > 1; --i)
      for (int j = 1; j <= m; ++j)
        for (int p = 0; p < k; ++p) {
          if (f[i][j][p] == inf) continue;
          if (j - 1) {
            int &tf = f[i - 1][j - 1][(p + a[i - 1][j - 2] - '0') % k],
                &tp = pre[i - 1][j - 1][(p + a[i - 1][j - 2] - '0') % k];
            if ((p + a[i - 1][j - 2] - '0') / k + f[i][j][p] > tf) {
              tf = (p + a[i - 1][j - 2] - '0') / k + f[i][j][p];
              tp = j;
            }
          }
          if (j + 1 <= m) {
            int &tf = f[i - 1][j + 1][(p + a[i - 1][j] - '0') % k],
                &tp = pre[i - 1][j + 1][(p + a[i - 1][j] - '0') % k];
            if ((p + a[i - 1][j] - '0') / k + f[i][j][p] > tf) {
              tf = (p + a[i - 1][j] - '0') / k + f[i][j][p];
              tp = j;
            }
          }
        }
    for (int i = 1; i <= m; ++i)
      if (f[1][i][0] > ans) {
        ans = f[1][i][0];
        pos = s;
        path = solve(1, i, 0);
      }
  }
  if (ans == inf)
    cout << -1;
  else {
    cout << ans * k << '\n' << pos << '\n';
    cout << path;
  }
  return 0;
}
