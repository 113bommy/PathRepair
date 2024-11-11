#include <bits/stdc++.h>
using namespace std;
int n, i, j, k, c[411], x, y, z, o, ans;
int main() {
  ans = 1 << 30;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> c[i];
  for (i = 2; i <= n; i++)
    for (j = i; j <= n; j++) {
      x = c[i - 1] - 1;
      y = 0;
      for (k = i; k <= j; k++) {
        z = x / c[k];
        x -= z * c[k];
        y += z;
      }
      x = c[i - 1] - 1 - x + c[j];
      o = x;
      y++;
      if (x < ans) {
        for (k = 1; k <= n; k++) {
          z = x / c[k];
          x -= z * c[k];
          y -= z;
        }
        if (y < 0) ans = o;
      }
    }
  if (ans == 1 << 30)
    cout << -1;
  else
    cout << ans;
  return 0;
}
