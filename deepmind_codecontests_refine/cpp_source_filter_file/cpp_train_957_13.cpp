#include <bits/stdc++.h>
using namespace std;
long long int t1, t2, x1, x2, t0;
const long double eps = (long double)(0.0000001);
const int p = 20;
long double t(long long int y1, long long int y2) {
  if ((y1 == 0) && (y2 == 0)) return 10000000000000000;
  return (long double)(t1 * y1 + t2 * y2) / (long double)(y1 + y2);
}
int main() {
  cin >> t1 >> t2 >> x1 >> x2 >> t0;
  long long tmpy1, tmpy2;
  long long int ans1 = 0, ans2 = 0;
  long double anst = 10000000000000000;
  if ((t1 == t0) && (t2 == t0)) {
    cout << x1 << " " << x2;
    return 0;
  }
  if (t1 == t0) {
    cout << x1 << " " << 0;
    return 0;
  }
  if (t2 == t0) {
    cout << 0 << " " << x2;
    return 0;
  }
  long double k = (long double)(t2 - t0) / (long double)(t0 - t1);
  for (tmpy2 = 0; tmpy2 <= x2; ++tmpy2) {
    long long int x = (long long int)(tmpy2 * k);
    for (long long int add = -p; add <= p; ++add) {
      tmpy1 = x + add;
      tmpy1 = max((long long int)0, tmpy1);
      tmpy1 = min(tmpy1, x1);
      long double tmp = t(tmpy1 + add, tmpy2);
      if (tmp >= t0) {
        if (abs(tmp - anst) <= 2 * eps) {
          if (tmpy1 + add + tmpy2 >= ans1 + ans2) {
            ans1 = tmpy1;
            ans2 = tmpy2;
            anst = tmp;
          }
        } else if (anst > tmp) {
          ans1 = tmpy1;
          ans2 = tmpy2;
          anst = tmp;
        }
      }
    }
  }
  cout << ans1 << ' ' << ans2;
  return 0;
}
