#include <bits/stdc++.h>
using namespace std;
double x1, y11, x2, y2, n, x, y, r;
int LX[2006], RX[2006], DY[2006], UY[2006], res = 0, dup = 0;
int LX1[2006], RX1[2006], DY1[2006], UY1[2006];
void prX(double x0, bool maxmum) {
  double Y0, Y1, yp2, c, bp2, delta;
  int d = abs(x - x0);
  if (d > r) return;
  if (d == r) {
    if (y11 <= y && y <= y2) {
      Y0 = Y1 = y;
      goto zekoo;
    }
    return;
  }
  yp2 = y * y;
  c = ((x0 - x) * (x0 - x)) - (r * r) + yp2;
  bp2 = 4 * yp2;
  delta = sqrt(bp2 - 4 * c);
  Y0 = (2 * y - delta) / 2;
  Y1 = (2 * y + delta) / 2;
  if (Y0 > Y1) swap(Y0, Y1);
  if (Y0 - (int)(Y0) != 0) Y0 = (int)(Y0) + (Y0 > 0);
  if (Y1 - (int)(Y1) != 0) Y1 = (int)(Y1) - (Y1 < 0);
zekoo:;
  if ((Y0 > y2 && Y1 > y2) || (Y0 < y11 && Y1 < y11)) return;
  Y0 = max(Y0, y11);
  Y1 = min(Y1, y2);
  if (maxmum) {
    RX[(int)Y0 + 1000]++;
    RX1[(int)Y1 + 1000]++;
  } else {
    LX[(int)Y0 + 1000]++;
    LX1[(int)Y1 + 1000]++;
  }
}
void prY(double y0, bool maxmum) {
  double X0, X1, xp2, c, bp2, delta;
  int d = abs(y - y0);
  if (d > r) return;
  if (d == r) {
    if (x1 <= x && x <= x2) {
      X0 = X1 = x;
      goto zekoo;
    }
    return;
  }
  xp2 = x * x;
  c = (y0 - y) * (y0 - y) - r * r + xp2;
  bp2 = 4 * xp2;
  delta = sqrt(bp2 - 4 * c);
  X0 = (2 * x - delta) / 2;
  X1 = (2 * x + delta) / 2;
  if (X0 > X1) swap(X0, X1);
  if (X0 - (int)(X0) != 0) X0 = (int)(X0) + (X0 > 0);
  if (X1 - (int)(X1) != 0) X1 = (int)(X1) - (X1 < 0);
zekoo:;
  if ((X0 > x2 && X1 > x2) || (X0 < x1 && X1 < x1)) return;
  X0 = max(X0, x1);
  X1 = min(X1, x2);
  if (maxmum) {
    UY[(int)X0 + 1000]++;
    UY1[(int)X1 + 1000]++;
  } else {
    DY[(int)X0 + 1000]++;
    DY1[(int)X1 + 1000]++;
  }
}
void process() {
  prX(x1, 0);
  prX(x2, 1);
  prY(y11, 0);
  prY(y2, 1);
}
void solve() {
  int sum0 = 0, sum1 = 0, sum2 = 0, sum3 = 0;
  for (int i = x1 + 1000; i <= x2 + 1000; i++) {
    sum2 += DY[i];
    if (sum2 == 0) {
      if (i == x2 + 1000) dup++;
      res++;
    }
    sum2 -= DY1[i];
    sum3 += UY[i];
    if (sum3 == 0) {
      if (i == x1 + 1000) dup++;
      res++;
    }
    sum3 -= UY1[i];
  }
  for (int i = y11 + 1000; i <= y2 + 1000; i++) {
    sum0 += LX[i];
    if (sum0 == 0) {
      if (i == y11 + 1000) dup++;
      res++;
    }
    sum0 -= LX1[i];
    sum1 += RX[i];
    if (sum1 == 0) {
      if (i == y2 + 1000) dup++;
      res++;
    }
    sum1 -= RX1[i];
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> x1 >> y11 >> x2 >> y2;
  if (x1 > x2) swap(x1, x2);
  if (y11 > y2) swap(y11, y2);
  cin >> n;
  while (n--) {
    cin >> x >> y >> r;
    process();
  }
  solve();
  cout << res - dup << endl;
  return 0;
}
