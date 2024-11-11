#include <bits/stdc++.h>
using namespace std;
const int xy[4][2] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
int n, i, j, a[2222][2222], k1 = 0, k2 = 0, o[1111111][2];
long long ans = 0;
bool t[2002][2002];
int abx(int x) {
  if (x < 0)
    return -x;
  else
    return x;
}
int white(int x, int y, int &x0, int &y0, int c) {
  int o1 = 1, o2 = 0;
  int k = 0;
  x0 = 0;
  y0 = 0;
  memset(t, true, sizeof(t));
  o[0][0] = x;
  o[0][1] = y;
  t[x][y] = false;
  a[x][y] = c;
  while (o1 != o2) {
    int x1 = o[o2][0], y1 = o[o2][1];
    o2++;
    for (int i = 0; i < 4; i++) {
      x = x1 + xy[i][0];
      y = y1 + xy[i][1];
      if ((x >= 0) && (y >= 0) && (x < n) && (y < n) && (a[x][y]) &&
          (t[x][y])) {
        o[o1][0] = x;
        o[o1][1] = y;
        o1++;
        k++;
        t[x][y] = false;
        if ((x > x0) || ((x == x0) && (y > y0))) {
          x0 = x;
          y0 = y;
        }
        a[x][y] = c;
      }
    }
  }
  return k;
}
int main() {
  cin >> n;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) cin >> a[i][j];
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (a[i][j]) {
        int xx, yy, s = white(i, j, xx, yy, 1);
        int s1 = (i - xx) * (i - xx) / 2,
            s2 = acos(-1.) * (i - xx) * (i - xx) / 4;
        if (abx(yy - j) > 1)
          k2++;
        else if (abx(s - s2) < abx(s - s1))
          k1++;
        else
          k2++;
        white(i, j, xx, yy, 0);
      }
  cout << k1 << " " << k2;
  return 0;
}
