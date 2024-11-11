#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long cnt, n, pre, i, j, k, l, x, y, z, a[310][310];
  cin >> n;
  pre = 0;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      cin >> a[i][j];
      pre += a[i][j];
    }
  }
  cin >> k;
  while (k--) {
    cin >> x >> y >> z;
    if (a[x][y] <= z)
      cout << pre / 2 << " ";
    else {
      cnt = 0;
      a[x][y] = z;
      a[y][x] = z;
      for (i = 1; i <= n; i++) {
        a[x][i] = min(a[x][i], a[x][y] + a[y][i]);
        a[i][x] = a[x][i];
      }
      for (i = 1; i <= n; i++) {
        a[y][i] = min(a[y][i], a[y][x] + a[x][i]);
        a[i][y] = a[y][i];
      }
      for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
          a[i][j] = min(min(a[i][j], a[i][x] + a[x][j]), a[i][y] + a[y][j]);
      for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) cnt += a[i][j];
      pre = cnt;
      cout << pre / 2 << " ";
    }
  }
  cout << endl;
  return 0;
}
