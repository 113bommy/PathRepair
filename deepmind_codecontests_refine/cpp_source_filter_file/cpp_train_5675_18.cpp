#include <bits/stdc++.h>
using namespace std;
template <class T>
bool uax(T& a, const T& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool uin(T& a, const T& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  double x1, x2, y1, y2;
  double vm, t;
  double vx, vy, wx, wy;
  cin >> x1 >> y1 >> x2 >> y2;
  cin >> vm >> t;
  cin >> vx >> vy;
  cin >> wx >> wy;
  double l = 0, r = 100000;
  auto reachable = [x1, x2, y1, y2, vx, vy, wx, wy, t, vm](double tau) -> bool {
    double xn, yn;
    if (tau <= t) {
      xn = x1 + vx * tau;
      yn = y1 + vy * tau;
    } else {
      xn = x1 + vx * t + wx * (tau - t);
      yn = y1 + vy * t + wy * (tau - t);
    }
    double dx = xn - x2;
    double dy = yn - y2;
    double l = sqrt(dx * dx + dy * dy);
    return l <= vm * tau;
  };
  while (abs(l - r) > 1e-6) {
    double tau = (l + r) / 2;
    if (reachable(tau)) {
      r = tau;
    } else {
      l = tau;
    }
  }
  printf("%.8lf", l);
  return 0;
}
