#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int x, y, z, i, j, k, n, t, temp, m, d, f;
  cin >> n >> m >> d;
  t = 0;
  long long int arr[m];
  for (i = 0; i < m; i++) cin >> arr[i];
  x = n;
  y = m - 1;
  long long int ans[n + 2];
  memset(ans, 0, sizeof(ans));
  f = 0;
  while (x > 0) {
    x = x - d + 1;
    if (x <= 0) break;
    if (m < 0) {
      f = 1;
      break;
    }
    if (t >= x - arr[y]) break;
    for (i = x; i > x - arr[y]; i--) ans[i] = y + 1;
    x = x - arr[y] + 1;
    y--;
  }
  if (f == 0) {
    cout << "YES" << endl;
    z = 0;
    for (i = 1; i <= n; i++) {
      if (z > y) break;
      for (j = i; j < arr[z] + i; j++) {
        if (ans[j] != 0) {
          for (k = j; k < arr[y + 1] + j; k++) ans[k] = 0;
          y++;
        }
        ans[j] = z + 1;
      }
      i = i + arr[z] - 1;
      z++;
    }
    for (i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
  } else
    cout << "NO" << endl;
}
