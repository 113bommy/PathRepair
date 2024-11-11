#include <bits/stdc++.h>
using namespace std;
int n, m, k, s, d[6][1000001], a[100001], ans, i, j, x;
int main() {
  cin >> n >> m >> k >> s;
  for (i = 1; i <= k; i++)
    d[2][i] = d[4][i] = 1000000000, d[1][i] = d[3][i] = -1000000000;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) {
      cin >> x;
      d[2][x] = min(d[2][x], i + j);
      d[1][x] = max(d[1][x], i + j);
      d[3][x] = max(d[3][x], i - j);
      d[4][x] = min(d[4][x], i - j);
    };
  for (i = 1; i <= s; i++) cin >> a[i];
  for (i = 2; i <= s; i++) {
    ans =
        max(ans, max(d[1][a[i - 1]] - d[2][a[i]], d[1][a[i]] - d[2][a[i - 1]]));
    ans =
        max(ans, max(d[3][a[i - 1]] - d[4][a[i]], d[3][a[i]] - d[4][a[i - 1]]));
  };
  cout << ans;
  return 0;
}
