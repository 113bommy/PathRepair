#include <bits/stdc++.h>
using namespace std;
double const e = 0.000001;
int main() {
  int n, a, d;
  cin >> n >> a >> d;
  int prevv = 10000000;
  double prevt = 0;
  for (int i = 0; i < n; i++) {
    int t, v;
    cin >> t >> v;
    double t1 = (double)v / a;
    double s1 = a * t1 * t1 / 2;
    double t2 = 0;
    if (s1 - d > e) {
      t1 = sqrt((2.0 * d) / a);
    } else {
      double s2 = d - s1;
      t2 = s2 / v;
    }
    double tt = t1 + t2;
    if (t + tt - prevt > e) {
      prevt = t + tt;
      prevv = v;
    }
    printf("%f\n", prevt);
  }
  return 0;
}
