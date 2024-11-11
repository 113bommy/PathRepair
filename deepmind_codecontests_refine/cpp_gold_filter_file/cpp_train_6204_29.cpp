#include <bits/stdc++.h>
using namespace std;
long double x[1000000], y[1000000], yv[1000000], xv[1000000];
int main() {
  ios::sync_with_stdio(0);
  long long n, x1, x2, y1, y2;
  cin >> n >> x1 >> y1 >> x2 >> y2;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i] >> xv[i] >> yv[i];
  }
  long double l = 0, r = 1000000;
  bool flg = 1, flg2 = 0;
  while (r - l >= .0000000001) {
    long double mid = (r + l) / 2;
    bool xd, xi, yd, yi;
    long long cc = 0;
    xd = xi = yd = yi = 0;
    for (int i = 0; i < n; i++) {
      long double xt = x[i] + xv[i] * mid;
      long double yt = y[i] + yv[i] * mid;
      if ((x[i] < x2 && xt >= x2) || (x[i] > x1 && xt <= x1)) {
        xd = 1;
      }
      if ((x[i] <= x1 && xt <= x1) || (x[i] >= x2 && xt >= x2)) {
        xi = 1;
      }
      if ((y[i] < y2 && yt >= y2) || (y[i] > y1 && yt <= y1)) {
        yd = 1;
      }
      if ((y[i] <= y1 && yt <= y1) || (y[i] >= y2 && yt >= y2)) {
        yi = 1;
      }
      if (xt > x1 && xt < x2 && yt > y1 && yt < y2) cc++;
    }
    if (cc == n) flg2 = 1;
    xd |= yd;
    xi |= yi;
    if (xd == 0 && xi == 0) {
      r = mid;
    } else if (xd == 1 && xi == 1) {
      flg = 0;
      break;
    } else if (xd == 1) {
      r = mid;
    } else {
      l = mid;
    }
  }
  if (flg && flg2)
    cout << setprecision(9) << r;
  else
    cout << "-1";
}
