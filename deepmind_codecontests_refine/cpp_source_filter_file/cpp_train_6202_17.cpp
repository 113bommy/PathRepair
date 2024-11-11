#include <bits/stdc++.h>
using namespace std;
int main() {
  int s, x1, x2, t1, t2, p, d;
  cin >> s >> x1 >> x2 >> t1 >> t2 >> p >> d;
  int ans1 = abs(x1 - x2) * t2;
  int ans2;
  int tmp = 0;
  if (p <= x2 && d == 1) {
    if (x1 < p)
      tmp = 2 * s - p + x2;
    else if (x1 >= p && x1 <= x2)
      tmp = abs(p - x2);
    else
      tmp = 2 * s - x2 - p;
  } else if (p <= x2 && d == -1) {
    if (x1 <= p)
      tmp = p + x2;
    else if (x1 > p && x1 <= x2)
      tmp = p + x2;
    else
      tmp = 2 * s - x2 + p;
  } else if (p > x2 && d == 1) {
    if (x1 >= p)
      tmp = 2 * s - p - x2;
    else if (x1 >= x2)
      tmp = 2 * s - p - x2;
    else
      tmp = 2 * s - p + x2;
  } else {
    if (x1 >= p)
      tmp = 2 * s + p - x2;
    else if (x1 >= x2)
      tmp = p - x2;
    else
      tmp = p + x2;
  }
  ans2 = tmp * t1;
  cout << min(ans1, ans2) << endl;
}
