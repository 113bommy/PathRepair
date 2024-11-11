#include <bits/stdc++.h>
using namespace std;
int main() {
  int hh, mm;
  double h, d, c, n, time;
  double ans, opt1, opt2, point, ans2;
  cin >> hh >> mm;
  cin >> h >> d >> c >> n;
  time = (20 - hh) * 60 - mm;
  if (hh < 20) {
    point = h + (time * d);
    opt1 = ceil(point / n) * (c * 0.8);
    opt2 = ceil(h / n) * c;
    ans = min(opt1, opt2);
    printf("%.4lf", ans);
  } else {
    ans2 = (h / n) * (c * 8);
    printf("%.4lf", ans2);
  }
  return 0;
}
