#include <bits/stdc++.h>
using namespace std;
int main() {
  int s, x1, x2, t1, t2, p, d;
  int t;
  cin >> s >> x1 >> x2 >> t1 >> t2 >> p >> d;
  int dist = ((x1 - x2) < 0 ? -(x1 - x2) : (x1 - x2)), diff = 0;
  if (t1 < t2) {
    if ((d == 1 && x2 > x1) || (d == -1 && x2 < x1)) {
      if (x2 > x1) {
        diff = p > x1 ? 2 * s - p + x1 : x1 - p;
      } else {
        diff = p > x1 ? p - x1 : 2 * s + p - x1;
      }
    } else {
      if (x2 > x1)
        diff = p + x1;
      else
        diff = 2 * s - x1 - p;
    }
  }
  cout << min(dist * t2, (dist + diff) * t1) << endl;
}
