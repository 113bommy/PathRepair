#include <bits/stdc++.h>
using namespace std;
const int N = 2018;
int n, a[N], l[N][N][3], r[N][N][3], d[N][N][3];
void load() {}
void process() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i)
    for (int j = i; j <= n; ++j)
      l[i][j][1] = l[i][j - 1][1], l[i][j][2] = l[i][j - 1][2], ++l[i][j][a[j]],
      l[i][j][2] = max(l[i][j][2], l[i][j][1]);
  for (int i = n; i > 0; --i)
    for (int j = i; j > 0; --j)
      r[i][j][1] = r[i][j + 1][1], r[i][j][2] = r[i][j + 1][2], ++r[i][j][a[j]],
      r[i][j][1] = max(r[i][j][1], r[i][j][2]);
  for (int i = n; i > 0; --i)
    for (int j = i; j > 0; --j)
      d[i][j][1] = d[i][j + 1][1], d[i][j][2] = d[i][j + 1][2], ++d[i][j][a[j]],
      d[i][j][2] = max(d[i][j][2], d[i][j][1]);
  int ans = max(l[1][n][1], l[1][n][2]);
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j)
      ans = max(ans, l[1][i - 1][1] + d[j][i][1] +
                         max(l[j + 1][n][1], l[j + 1][n][2])),
      ans = max(ans, l[i][i - 1][1] + d[j][i][2] + r[n][j + 1][2]);
  cout << ans;
  return;
}
int main() {
  load();
  process();
  return 0;
}
