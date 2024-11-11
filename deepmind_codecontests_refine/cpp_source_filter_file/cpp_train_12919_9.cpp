#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a[1000], i, j, k, mm[105][105] = {}, u, v, ans = 1000000000;
  cin >> n >> m;
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < m; i++) {
    cin >> u >> v;
    --u, --v;
    mm[u][v] = 1;
    mm[v][u] = 1;
  }
  for (i = 0; i < n; i++)
    for (j = i + 1; j < n; j++)
      for (k = j + i; k < n; k++)
        if (mm[i][j] && mm[j][k] && mm[i][k])
          ans = min(ans, a[i] + a[j] + a[k]);
  if (ans == 1000000000)
    cout << -1;
  else
    cout << ans;
  return 0;
}
