#include <bits/stdc++.h>
using namespace std;
int main() {
  double s, x1, x2, tt, ti, p, d;
  while (cin >> s >> x1 >> x2) {
    cin >> tt >> ti >> p >> d;
    if (x1 == x2) {
      cout << "0\n";
      continue;
    }
    if (x2 - x1 < 0) {
      p = s - p;
      x1 = s - x1;
      x2 = s - x2;
      d = 0 - d;
    }
    double vt = 1 / tt, vi = 1 / ti, cross;
    double to, tm, tmp;
    double x1m = x1, x2m = x2;
    if (d == -1) {
      if (tt > ti)
        tm = (x2 - x1) / vi;
      else {
        to = p / vt;
        x1 = x1 + vi * to;
        tmp = x1 / (vt - vi);
        cross = vt * tmp;
        tm = tmp + to;
        if (cross < x2) {
          tm += ((x2 - cross) / vt);
        } else {
          tm = (x2m - x1m) / vi;
        }
      }
    } else {
      if (tt > ti)
        tm = (x2 - x1) / vi;
      else {
        if (p > x1) {
          to = (2 * s - p) / vt;
          x1 += (vi * to);
          tmp = x1 / (vt - vi);
          cross = vt * tmp;
          tm = to + tmp;
        } else {
          tm = ((x1 - p) / (vt - vi));
          cross = p + vt * tmp;
        }
        if (cross < x2)
          tm += ((x2 - cross) / vt);
        else
          tm = (x2m - x1m) / vi;
      }
    }
    cout << tm << endl;
  }
  return 0;
}
