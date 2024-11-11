#include <bits/stdc++.h>
using namespace std;
long double n, l, v1, v2, k;
bool f(long double mid) {
  long double t = 0, dis = 0;
  int n1 = n;
  while (1) {
    if (t > mid) return false;
    if (dis >= l) return true;
    n1 -= k;
    long double x = (l - v1 * (mid - t + (v1 * dis) / v2)) / (1 - v1 / v2);
    if (dis >= x) return true;
    long double t2 = (x - dis) / v2;
    t += t2;
    if (t > mid) return false;
    dis += v1 * t2;
    if (n1 <= 0 || dis >= l) return true;
    t2 = (x - dis) / (v1 + v2);
    t += t2;
    dis += v1 * t2;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> l >> v1 >> v2 >> k;
  long double ans = 0, dis = 0;
  long double lo = 0, hi = 1e10, mid;
  for (int i = 0; i <= 300; i++) {
    mid = (lo + hi) / 2;
    if (f(mid))
      hi = mid;
    else
      lo = mid;
  }
  cout << fixed << setprecision(10) << lo;
  return 0;
}
