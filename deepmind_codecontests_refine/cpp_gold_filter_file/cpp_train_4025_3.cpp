#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  double hh, mm, h, d, c, n;
  cin >> hh >> mm >> h >> d >> c >> n;
  if (hh < 20) {
    double y = h / n * 1.0;
    y = ceil(y);
    y = c * y;
    double mn;
    if (mm != 0) {
      mn = (60 - mm);
      mn += 60 * (20 - hh - 1);
    } else {
      mn = (60 - mm);
      mn += 60 * (20 - hh - 1);
    }
    double x = h + (mn * d * 1.0);
    x = x / n * 1.0;
    x = ceil(x);
    x = c * 0.8 * x;
    cout << fixed << setprecision(4) << min(x, y);
  } else {
    double y = h / n * 1.0;
    y = ceil(y);
    y = c * 0.8 * y;
    cout << fixed << setprecision(4) << y;
  }
  return 0;
}
