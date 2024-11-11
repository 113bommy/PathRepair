#include <bits/stdc++.h>
using namespace std;
int main() {
  int t1, t2, s, x, x1, x2, d, it, tt;
  cin >> s >> x1 >> x2 >> t1 >> t2 >> x >> d;
  if (x2 > x1) {
    it = (x2 - x1) * t2;
    if (d == 1 && x <= x1) {
      tt = (x2 - x) * t1;
    } else if (d == 1) {
      tt = ((s - x) + (s) + x2) * t1;
    } else {
      tt = (x + x2) * t1;
    }
  } else {
    it = (x1 - x2) * t2;
    if (d == -1 && x >= x1) {
      tt = (x - x2) * t1;
    } else if (d == -1 && x < x1) {
      tt = (s + s + x - x2) * t1;
    } else {
      tt = (s + s - x - x2) * t1;
    }
  }
  if (x1 == x2) it = 0;
  cout << min(it, tt);
  return 0;
}
