#include <bits/stdc++.h>
using namespace std;
const double PI = 4 * atan(1.0);
const int MAX_SIZE = 10000;
long long t1, t2, x1, x2, t0;
bool check(long long y1, long long y2, double co) {
  if (y1 + y2 == 0) return false;
  if (y1 == 0) return t2 >= t0;
  if (y2 == 0) return t1 >= t0;
  double p = (double)(t1 * y1 + t2 * y2) / (y1 + y2);
  return ((double)co * y1 < y2 || (abs((y2) - ((y1 * co))) < (1e-10)));
}
void solve() {
  cin >> t1 >> t2 >> x1 >> x2 >> t0;
  double maxTemp = 1000000000;
  long long ox1, ox2;
  ox1 = ox2 = 0;
  if (t1 == t2)
    cout << x1 << " " << x2 << endl;
  else if (t2 == 0)
    cout << 0 << " " << x2 << endl;
  else if (t1 == t0)
    cout << x1 << " " << 0 << endl;
  else {
    double co = (double)(t1 - t0) / (t0 - t2);
    for (long long y1 = 0; y1 <= x1; y1++) {
      long long ub = x2;
      long long lb = -1;
      bool b = false;
      if (y1 == 0) {
        ub = x2;
        b = true;
      } else {
        while (ub - lb > 1) {
          bool ok = false;
          long long y2 = (ub + lb) / 2;
          if (check(y1, y2, co))
            ub = y2;
          else
            lb = y2;
        }
        if (check(y1, ub, co)) b = true;
      }
      if (b) {
        double p = (double)(t1 * y1 + t2 * ub) / (y1 + ub);
        if (!(abs((maxTemp) - (p)) < (1e-10)) && maxTemp > (p)) {
          maxTemp = ((double)(t1 * y1 + t2 * ub) / (y1 + ub));
          ox1 = y1;
          ox2 = ub;
        } else if ((abs((maxTemp) - (((double)(t1 * y1 + t2 * ub) /
                                      (y1 + ub)))) < (1e-10))) {
          if (ox1 + ox2 < ub + y1) {
            ox1 = y1;
            ox2 = ub;
          }
        }
      }
    }
    cout << ox1 << " " << ox2 << endl;
  }
}
int main() {
  solve();
  return 0;
}
