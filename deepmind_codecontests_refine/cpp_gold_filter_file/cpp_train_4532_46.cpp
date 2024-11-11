#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, c, n, k, x, y, ans = 0, a[11][11] = {}, j;
  cin >> r >> c >> n >> k;
  for (int i = 0; i < n; i++) cin >> x >> y, a[x][y] = 1;
  for (int i = 1; i <= r; i++)
    for (int i2 = i; i2 <= r; i2++)
      for (int u = 1; u <= c; u++)
        for (int u2 = u; u2 <= c; u2++) {
          j = 0;
          for (int ix = i; ix <= i2; ix++)
            for (int ux = u; ux <= u2; ux++) j += a[ix][ux];
          ans += j >= k;
        }
  cout << ans;
  return 0;
}
