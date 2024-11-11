#include <bits/stdc++.h>
using namespace std;
int n, m, c, h, x, y;
int hx[5], hy[5];
int d[5];
int main() {
  for (int i = 1; i <= 4; i++) {
    d[i] = 1000000000;
  }
  scanf("%d %d", &n, &m);
  scanf("%d", &c);
  int cs = 0;
  int titik[5], flag = 0;
  for (int i = 0; i < c; i++) {
    scanf("%d %d", &x, &y);
    titik[1] = (abs(x - 1) + abs(y - 1));
    titik[2] = (abs(x - n) + abs(y - m));
    titik[3] = abs(x - 1) + abs(y - m);
    titik[4] = abs(x - n) + abs(y - 1);
    cs = 0;
    for (int j = 1; j <= 4; j++) {
      if (titik[j] < d[j]) {
        hx[j] = x;
        hy[j] = y;
        d[j] = titik[j];
      }
    }
  }
  scanf("%d", &h);
  int mx = 2000000001;
  int mxmx = -100000;
  int num = 0;
  for (int i = 1; i <= h; i++) {
    scanf("%d %d", &x, &y);
    mxmx = -100000;
    for (int j = 1; j <= 4; j++) {
      mxmx = max(mxmx, abs(hx[j] - x) + abs(hy[j] - y));
    }
    if (mxmx < mx) {
      mx = mxmx;
      num = i;
    }
  }
  printf("%d\n%d\n", mx, num);
  return 0;
}
