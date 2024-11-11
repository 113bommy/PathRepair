#include <bits/stdc++.h>
using namespace std;
const int maxn = 103, inf = (int)(1e9) + 13;
int n, m, a[maxn][maxn], res, mnx[maxn], mny[maxn];
string r = "row ", c = "col ";
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (m < n)
        cin >> a[j][i];
      else
        cin >> a[i][j];
  if (m < n) {
    swap(r, c);
    swap(n, m);
  }
  for (int i = 1; i <= n; i++) {
    int mn = inf;
    for (int j = 1; j <= m; j++) mn = min(mn, a[i][j]);
    for (int j = 1; j <= m; j++) a[i][j] -= mn;
    mnx[i] = mn;
    res += mn;
  }
  for (int j = 1; j <= m; j++) {
    for (int i = 1; i < n; i++)
      if (a[i][j] != a[i + 1][j]) {
        cout << "-1";
        return 0;
      }
    mny[j] = a[1][j];
    res += a[1][j];
  }
  cout << res << endl;
  for (int i = 1; i <= n; i++)
    for (int k = 1; k <= mnx[i]; k++) cout << r << i << endl;
  for (int j = 1; j <= m; j++)
    for (int k = 1; k <= mny[j]; k++) cout << c << j << endl;
  return 0;
}
