#include <bits/stdc++.h>
using namespace std;
int main() {
  int s, x1, x2, t1, t2, p, d;
  cin >> s >> x1 >> x2 >> t1 >> t2 >> p >> d;
  double v1, v2;
  v1 = abs(x1 - x2) * t2;
  if (x1 <= x2) {
    if (d == 1) {
      if (p <= x1) {
        v2 = (x2 - p) * t1;
      } else {
        v2 = (s - p + s + x2) * t1;
      }
    } else {
      v2 = (p + x2) * t1;
    }
  } else {
    if (d == 1) {
      v2 = (s + s - p - x2) * t1;
    } else {
      if (p < x1) {
        v2 = (p + s + s - x2) * t1;
      } else {
        v2 = (p - x2) * t1;
      }
    }
  }
  cout << min(v1, v2) << endl;
}
