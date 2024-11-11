#include <bits/stdc++.h>
using namespace std;
template <class T>
T gcd(T a, T b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
template <class T>
T power(T a, T b) {
  T result = 1;
  while (b > 0) {
    if (b & 1) result = result * a;
    a = a * a;
    b >>= 1;
  }
  return result;
}
template <class T>
T powerMod(T a, T b, T c) {
  T result = 1 % c;
  while (b > 0) {
    if (b & 1) result = (result * a) % c;
    a = (a * a) % c;
    b >>= 1;
  }
  return result;
}
void eval() {
  long double x1, x2, y1, y2, vx, vy, wx, wy, v, t, res = 1e9;
  cin >> x1 >> y1 >> x2 >> y2;
  cin >> v >> t;
  cin >> vx >> vy;
  cin >> wx >> wy;
  long double st, en, mid, dist, newx, newy;
  st = 0;
  en = 2e8;
  while ((en - st) >= 1e-8) {
    mid = (en + st) / (2.0L);
    if (mid > t) {
      newx = x2 - (t * vx) - ((mid - t) * wx);
      newy = y2 - (t * vy) - ((mid - t) * wy);
    } else {
      newx = x2 - (mid * vx);
      newy = y2 - (mid * vy);
    }
    dist = sqrt(((x1 - newx) * (x1 - newx)) + ((y1 - newy) * (y1 - newy)));
    res = min(res, max(mid, (dist / v)));
    if (mid > (dist / v)) {
      en = mid - (1e-7);
    } else {
      st = mid + (1e-7);
    }
  }
  cout.precision(10);
  cout << fixed << mid;
}
int main() {
  cin.sync_with_stdio(0);
  cout.sync_with_stdio(0);
  eval();
  return 0;
}
