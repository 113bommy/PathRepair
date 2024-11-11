#include <bits/stdc++.h>
using namespace std;
const int INF = 1999999999;
const long double EPS = 0.000001;
const long double pi = M_PI;
int n;
long double R, v;
long double f(long double d) {
  long double l = 0, r = d, ans = 0;
  while (abs(l - r) > EPS) {
    long double tm = (l + r) / 2;
    long double ans = tm + R * abs(sin(tm / R));
    if (ans * 2 < d)
      l = tm;
    else
      r = tm;
  }
  return l;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> R >> v;
  for (int(i) = (0); (i) < (n); (i)++) {
    long double l, r;
    cin >> l >> r;
    if (r < l) swap(r, l);
    long double g = f(r - l);
    long double ans = (2 * g) / v;
    cout << fixed << setprecision((10)) << (ans) << endl;
  }
  return 0;
}
