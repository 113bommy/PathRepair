#include <bits/stdc++.h>
using namespace std;
int a[53][39][39][4], b[39][39];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
string ds = "LURD";
int dir(int xx1, int yy1, int xx2, int yy2) {
  if (xx2 - xx1 < 0) return 0;
  if (xx2 - xx1 > 0) return 2;
  if (yy2 - yy1 > 0) return 1;
  return 3;
}
int main() {
  int n, m;
  memset(b, -1, sizeof(b));
  cin >> m >> n;
  for (int i = 1; i <= m; i++) {
    int xx1, yy1, xx2, yy2;
    cin >> xx1 >> yy1 >> xx2 >> yy2;
    int d = dir(xx1, yy1, xx2, yy2);
    while (1) {
      b[xx1][yy1] = d;
      if (xx1 == xx2 && yy1 == yy2) break;
      xx1 += dx[d];
      yy1 += dy[d];
    }
  }
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++)
      for (int k = 0; k < 4; k++) {
        int d = k;
        if (b[i][j] != -1) d = b[i][j];
        int tx = i + dx[d];
        int ty = j + dy[d];
        if (tx < 0 || ty < 0 || tx > n || ty > n) tx = i, ty = j;
        int td = d;
        if (b[tx][ty] != -1) td = b[tx][ty];
        a[0][i][j][k] = tx * 1000 + ty * 10 + td;
      }
  for (int l = 1; l < 53; l++)
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= n; j++)
        for (int k = 0; k < 4; k++) {
          int tmp = a[l - 1][i][j][k];
          int tx = tmp / 1000;
          int ty = (tmp % 1000) / 10;
          int td = tmp % 10;
          a[l][i][j][k] = a[l - 1][tx][ty][td];
        }
  int q;
  cin >> q;
  while (q--) {
    int x, y, d;
    long long t;
    char s[5];
    cin >> x >> y >> s >> t;
    if (s[0] == 'L') d = 0;
    if (s[0] == 'U') d = 1;
    if (s[0] == 'R') d = 2;
    if (s[0] == 'D') d = 3;
    for (int i = 52; i >= 0; i--)
      if (t >> i) {
        int tmp = a[i][x][y][d];
        x = tmp / 1000;
        y = (tmp % 1000) / 10;
        d = tmp % 10;
        t ^= (1ll << i);
      }
    printf("%d %d\n", x, y);
  }
}
