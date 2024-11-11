#include <bits/stdc++.h>
using namespace std;
long long n, b, x, y, z, xx, yy, zz, t, q;
char cc;
struct lsg {
  long long x, y, z;
} a[51][100][100][4];
const long long c[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
signed main() {
  ios::sync_with_stdio(false);
  cin >> n >> b;
  b++;
  for (long long i = 1; i <= b; i++)
    for (long long j = 1; j <= b; j++)
      for (long long k = 0; k < 4; k++) {
        xx = i + c[k][0], yy = j + c[k][1];
        if (xx < 1 || yy < 1 || xx > b || yy > b)
          a[0][i][j][k].x = i, a[0][i][j][k].y = j, a[0][i][j][k].z = k;
        else
          a[0][i][j][k].x = xx, a[0][i][j][k].y = yy, a[0][i][j][k].z = k;
      }
  for (long long i = 1; i <= n; i++) {
    cin >> x >> y >> xx >> yy;
    x++;
    y++;
    xx++;
    yy++;
    if (x < xx)
      for (long long j = x; j <= xx; j++)
        for (long long k = 0; k < 4; k++)
          a[0][j][y][k].x = min(j + 1, b), a[0][j][y][k].y = y,
          a[0][j][y][k].z = 1;
    if (y < yy)
      for (long long j = y; j <= yy; j++)
        for (long long k = 0; k < 4; k++)
          a[0][x][j][k].x = x, a[0][x][j][k].y = min(j + 1, b),
          a[0][x][j][k].z = 0;
    if (x > xx)
      for (long long j = x; j >= xx; j--)
        for (long long k = 0; k < 4; k++)
          a[0][j][y][k].x = max(j - 1, 1ll), a[0][j][y][k].y = y,
          a[0][j][y][k].z = 3;
    if (y > yy)
      for (long long j = y; j >= yy; j--)
        for (long long k = 0; k < 4; k++)
          a[0][x][j][k].x = x, a[0][x][j][k].y = max(j - 1, 1ll),
          a[0][x][j][k].z = 2;
  }
  for (long long k = 1; k <= 50; k++)
    for (long long i = 1; i <= b; i++)
      for (long long j = 1; j <= b; j++)
        for (long long l = 0; l < 4; l++)
          a[k][i][j][l] = a[k - 1][a[k - 1][i][j][l].x][a[k - 1][i][j][l].y]
                           [a[k - 1][i][j][l].z];
  cin >> q;
  while (q--) {
    cin >> x >> y >> cc >> t;
    x++;
    y++;
    if (cc == 'U') z = 0;
    if (cc == 'D') z = 2;
    if (cc == 'L') z = 3;
    if (cc == 'R') z = 1;
    for (long long i = 5; i >= 0; i--)
      if (t & 1ll << i)
        xx = a[i][x][y][z].x, yy = a[i][x][y][z].y, zz = a[i][x][y][z].z,
        x = xx, y = yy, z = zz;
    cout << x - 1 << ' ' << y - 1 << endl;
  }
}
