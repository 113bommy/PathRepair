#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-15;
inline int dcmp(double x) { return x < -eps ? -1 : x > eps; }
inline bool deq(double x, double y) { return dcmp(x - y) == 0; }
inline bool dleq(double x, double y) { return dcmp(x - y) <= 0; }
int main() {
  int t1, t2, x1, x2, t, y1 = 0, y2 = 0;
  cin >> t1 >> t2 >> x1 >> x2 >> t;
  if (t == t1) y1 = x1;
  if (t == t2) y2 = x2;
  if (t == t1 || t == t2) {
    cout << y1 << ' ' << y2 << endl;
    return 0;
  }
  double c = double(t2 - t) / (t - t1);
  if (!dleq(1.0 / x2, c)) {
    cout << 0 << ' ' << x2 << endl;
    return 0;
  }
  y1 = 1, y2 = 1;
  int sum = 0, s1, s2;
  double dif = (1LL << 28);
  while (y1 <= x1 && y2 <= x2)
    if (dleq(double(y1) / y2, c)) {
      if (!dleq(dif, (c - (double(y1) / y2)))) {
        dif = c - (double(y1) / y2);
        sum = y1 + y2;
        s1 = y1;
        s2 = y2;
      }
      if (deq(dif, (c - (double(y1) / y2))) && (sum < y1 + y2)) {
        sum = y1 + y2;
        s1 = y1;
        s2 = y2;
      }
      y1++;
    } else
      y2++;
  cout << s1 << ' ' << s2 << endl;
  return 0;
}
