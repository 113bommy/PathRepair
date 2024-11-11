#include <bits/stdc++.h>
using namespace std;
template <typename T>
T sqr(T a) {
  return a * a;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cout.tie(nullptr);
  cout.precision(12);
  cout << fixed;
  int x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  long long vmax, t;
  cin >> vmax >> t;
  long long vx, vy, wx, wy;
  cin >> vx >> vy >> wx >> wy;
  vx *= -1;
  vy *= -1;
  wx *= -1;
  wy *= -1;
  long long x = x2 - x1;
  long long y = y2 - y1;
  if (sqr(x + vx * t) + sqr(y + vy * t) <= sqr(vmax * t)) {
    long double lt = 0;
    long double rt = t;
    long double eps = 1e-10;
    while (fabs(lt - rt) > eps) {
      long double mid = (lt + rt) / 2;
      long double f = sqr(x + vx * mid) + sqr(y + vy * mid) - sqr(vmax * mid);
      if (f < 0) {
        rt = mid;
      } else {
        lt = mid;
      }
    }
    cout << lt << endl;
  } else {
    long double lt = t;
    long double rt = 1e7;
    long double eps = 1e-10;
    while (fabs(lt - rt) > eps) {
      long double mid = (lt + rt) / 2;
      long double f = sqr(x + vx * t + wx * (mid - t)) +
                      sqr(y + vy * t + wy * (mid - t)) - sqr(vmax * mid);
      if (f < 0) {
        rt = mid;
      } else {
        lt = mid;
      }
    }
    cout << rt << endl;
  }
  return 0;
}
