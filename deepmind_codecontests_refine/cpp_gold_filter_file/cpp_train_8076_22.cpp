#include <bits/stdc++.h>
using namespace std;
double n;
bool check(double x1, double y1) {
  if (sqrt(x1 * x1 + y1 * y1) - 1e-6 <= n)
    return true;
  else
    return false;
}
int main() {
  cin >> n;
  long long int sum = 0;
  double x = -1.0;
  for (int i = 1;; i++) {
    int res = 0;
    if (i & 1) {
      double x1 = x + 1.5;
      x += 2.0;
      if (check(x1, 0.5 * 1.73205080756887720000) && check(x, 0.0)) {
        res = 1;
        int lo = 1, hi = 1000005;
        int su = 0;
        while (lo <= hi) {
          int mid = (lo + hi) / 2;
          if (check(x1, 0.5 * 1.73205080756887720000 +
                            (double)mid * 1.73205080756887720000) &&
              check(x, (double)mid * 1.73205080756887720000)) {
            lo = mid + 1;
            su = max(su, mid);
          } else
            hi = mid - 1;
        }
        res = res + (su * 2);
      } else
        break;
    } else {
      double x1 = x + 1.0;
      x += 1.5;
      int lo = 1, hi = 1000005;
      int su = 0;
      while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(x1, (double)mid * 1.73205080756887720000) &&
            check(x, (double)mid * 1.73205080756887720000 -
                         0.5 * 1.73205080756887720000)) {
          lo = mid + 1;
          su = max(su, mid);
        } else
          hi = mid - 1;
      }
      if (su == 0) break;
      res = res + (2 * su);
      x -= 0.5;
    }
    if (i == 1)
      sum = sum + res;
    else
      sum = sum + (2 * res);
  }
  cout << sum << endl;
  return 0;
}
