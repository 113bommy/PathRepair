#include <bits/stdc++.h>
using namespace std;
int n, q, c, a[12][102][102];
int main() {
  scanf("%d%d%d", &n, &q, &c);
  c++;
  for (int i = 1; i <= n; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    a[z][x][y] = 1;
  }
  for (int z = 0; z <= 10; z++)
    for (int i = 1; i <= 100; i++)
      for (int j = 1; j <= 100; j++)
        a[z][i][j] =
            a[z][i][j] + a[z][i - 1][j] + a[z][i][j - 1] - a[z][i - 1][j - 1];
  for (; q; q--) {
    int x1, y1, x2, y2, t, ans = 0;
    scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
    t %= c;
    for (int z = 0; z <= 10; z++)
      ans += ((z + t) % c) * (a[z][x2][y2] - a[z][x2][y1 - 1] -
                              a[z][x1 - 1][y2] + a[z][x1 - 1][y1 - 1]);
    printf("%d\n", ans);
  }
}
