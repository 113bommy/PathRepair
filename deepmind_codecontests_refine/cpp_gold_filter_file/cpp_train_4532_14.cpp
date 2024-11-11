#include <bits/stdc++.h>
using namespace std;
int a[102][102] = {0}, r, c, n, k;
int main() {
  int i, j, sx, sy, sum, w;
  cin >> r >> c >> n >> k;
  for (i = 0; i < n; i++) {
    cin >> sx >> sy;
    a[sx][sy] = 1;
  }
  for (i = 2; i <= c; i++) a[1][i] += a[1][i - 1];
  for (i = 2; i <= r; i++) {
    sum = a[i][1];
    a[i][1] += a[i - 1][1];
    for (j = 2; j <= c; j++) {
      if (a[i][j] == 0)
        a[i][j] += sum + a[i - 1][j];
      else {
        a[i][j] += sum + a[i - 1][j];
        sum++;
      }
    }
  }
  sum = 0;
  for (i = 1; i <= r; i++) {
    for (j = 1; j <= c; j++) {
      for (sx = i; sx <= r; sx++)
        for (sy = j; sy <= c; sy++) {
          w = a[sx][sy] - a[i - 1][sy] - a[sx][j - 1] + a[i - 1][j - 1];
          if (w >= k) sum++;
        }
    }
  }
  cout << sum << endl;
  return 0;
}
