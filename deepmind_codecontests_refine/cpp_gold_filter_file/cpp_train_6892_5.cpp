#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 10;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t1, t2, x, x2, t0;
  cin >> t1 >> t2 >> x >> x2 >> t0;
  bool sw = false;
  if (t1 < t2) {
    sw = true;
    swap(t1, t2);
    swap(x, x2);
  }
  long double rez = INF;
  long long y, y2;
  for (long long sum = x + x2; sum >= 1; sum--) {
    long long l = 0, r = min(sum, x2) + 1;
    while (r - l > 1) {
      long long mid = (l + r) / 2;
      long long tkek = min(sum, mid + x);
      if (((tkek - mid) * t1 + mid * t2) / tkek >= t0) {
        l = mid;
      } else {
        r = mid;
      }
    }
    long long tkek = min(sum, l + x);
    if (((tkek - l) * t1 + l * t2) * 1.0 / tkek >= t0) {
      if ((min(x, (sum - l)) * t1 + l * t2) * 1.0 / tkek < rez) {
        rez = ((tkek - l) * t1 + l * t2) * 1.0 / tkek;
        y = tkek - l;
        y2 = l;
      }
    }
  }
  if (sw) {
    swap(y, y2);
  }
  cout << y << ' ' << y2 << '\n';
}
