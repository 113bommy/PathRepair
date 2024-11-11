#include <bits/stdc++.h>
using namespace std;
long long int s, x1, x2, p, d, t1, t2, dp = 1;
int main() {
  cin >> s >> x1 >> x2 >> t1 >> t2 >> p >> d;
  long long int res = abs(x1 - x2) * t2;
  if (x1 > x2) dp = -1;
  if (d == 1 && dp == 1) {
    if (p <= x1)
      res = min(res, abs(x2 - p) * t1);
    else if (p > x1)
      res = min(res, abs(2 * s - p + x2) * t1);
  } else if (d == 1 && dp == -1)
    res = min(res, abs(2 * s - p + x2) * t1);
  else if (d == -1 && dp == 1)
    res = min(res, abs(p + x2) * t1);
  else {
    if (p >= x1)
      res = min(res, abs(x2 - p) * t1);
    else if (p < x1)
      res = min(res, abs(p + 2 * s - x2) * t1);
  }
  cout << res << endl;
  return 0;
}
