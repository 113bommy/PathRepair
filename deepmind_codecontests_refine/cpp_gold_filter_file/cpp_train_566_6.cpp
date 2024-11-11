#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
int main() {
  int q;
  long double x, y;
  cin >> q >> x >> y;
  long double fx = 1. / x;
  long double fy = 1. / y;
  while (q--) {
    long long life;
    cin >> life;
    long double beg = 0, end = life * 2;
    for (int i = 0; i < (200); ++i) {
      long double mid = (beg + end) / 2;
      long long tothit = floor(mid / fx) + floor(mid / fy);
      if (tothit >= life)
        end = mid;
      else
        beg = mid;
    }
    long double t = (beg + end) / 2;
    bool vany = (fabs(t / fx - round(t / fx)) < EPS) ? true : false;
    bool vov = (fabs(t / fy - round(t / fy)) < EPS) ? true : false;
    if (vany && vov)
      cout << "Both\n";
    else if (vany)
      cout << "Vanya\n";
    else
      cout << "Vova\n";
  }
  return 0;
}
