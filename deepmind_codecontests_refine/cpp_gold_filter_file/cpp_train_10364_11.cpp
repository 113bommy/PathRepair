#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-11;
long long n, l, v1, v2, k;
bool check(double tim) {
  int tmp = n;
  double t = 0;
  double grx = 0, bus = 0;
  while (tmp > 0) {
    double del = l - grx;
    if (del / v2 > tim + EPS / 100) {
      return 0;
    }
    double x = (v1 * tim - del) * v2 * 1.0 / (v1 - v2);
    double step = x / v2;
    tim -= step;
    bus += x;
    tmp -= k;
    if (tmp <= 0) break;
    grx += step * v1;
    double step2 = (bus - grx) / (v1 + v2);
    grx += step2 * v1;
    tim -= step2;
    if (tim < -EPS / 100) return 0;
    bus = grx;
  }
  return 1;
}
double bs(double lo, double hi) {
  if ((hi - lo) <= EPS * 10 || (hi - lo) / hi <= EPS * 10) {
    return lo;
  }
  double mid = (lo + hi) / 2;
  if (check(mid)) {
    return bs(lo, mid);
  }
  return bs(mid, hi);
}
int main() {
  if (fopen("D.in", "r")) freopen("D.in", "r", stdin);
  cin >> n >> l >> v1 >> v2 >> k;
  cout << setprecision(10) << bs(0, 1e10);
  return 0;
}
