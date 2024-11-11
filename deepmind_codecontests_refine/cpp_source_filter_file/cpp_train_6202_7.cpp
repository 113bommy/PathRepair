#include <bits/stdc++.h>
using namespace std;
int main() {
  int s, x1, x2, t1, t2, p, d;
  cin >> s >> x1 >> x2 >> t1 >> t2 >> p >> d;
  if (t1 >= t2)
    cout << abs(x1 - x2) * t2 << endl;
  else {
    if (x2 > x1) {
      if (d == 1) {
        if (p > x1) {
          if ((2 * s + x2 - p) * t1 > (x2 - x1) * t2)
            cout << (x2 - x1) * t2 << endl;
          else
            cout << (2 * s + x2 - p) * t1 << endl;
        }
        if (p == x1) cout << (x2 - x1) * t1 << endl;
        if (p < x1) {
          if ((x2 - p) * t1 > (x2 - x1) * t2)
            cout << (x2 - x1) * t2 << endl;
          else
            cout << (p - x2) * t1 << endl;
        }
      } else {
        if ((x2 - x1) * t2 > (p + x2) * t1)
          cout << (p + x2) * t1 << endl;
        else
          cout << (x2 - x1) * t2 << endl;
      }
    } else {
      if (d == -1) {
        if (p < x1) {
          if ((2 * s + p - x2) * t1 > (x1 - x2) * t2)
            cout << (x1 - x2) * t2 << endl;
          else
            cout << (2 * s + p - x2) * t1 << endl;
        } else {
          if ((p - x2) * t1 > (x1 - x2) * t2)
            cout << (x1 - x2) * t2 << endl;
          else
            cout << (p - x2) * t1 << endl;
        }
      } else {
        if ((2 * s - p - x2) * t1 < (x1 - x2) * t2)
          cout << (2 * s - p - x2) * t1 << endl;
        else
          cout << (x1 - x2) * t2 << endl;
      }
    }
  }
  return 0;
}
