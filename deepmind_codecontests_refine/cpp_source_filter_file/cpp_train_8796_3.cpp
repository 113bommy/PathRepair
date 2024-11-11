#include <bits/stdc++.h>
using namespace std;
int n;
const double PI = 3.1415926535897932;
double v, r, f, s, res;
double get(double t, double a) { return v * t + r * sin(a + v * t / r); }
double bins(double l, double r, double a) {
  double m;
  for (int i = 0; i < 50; i++) {
    m = (l + r) / 2;
    if (get(m, a) >= f)
      r = m;
    else
      l = m;
  }
  return l;
}
int main() {
  cin >> n >> r >> v;
  cout << setprecision(10) << fixed;
  for (int i = 0; i < n; i++) {
    scanf("%lf %lf", &s, &f);
    f = (f - s) / 2;
    cout << 2 * min(bins(0, 2000000000, 0), bins(0, 2000000000, PI)) << endl;
  }
  return 0;
}
