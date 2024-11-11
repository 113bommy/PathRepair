#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, v, i, n, a, d;
  double tp = 0;
  cin >> n >> a >> d;
  for (i = 0; i < n; ++i) {
    cin >> t >> v;
    double tr = v / 1.0 / a;
    if (a * ((tr) * (tr)) / 2 > d) {
      tr = sqrt(2.0 * d / a);
    } else
      tr += (d - a * ((tr) * (tr)) / 2) / v;
    if (tp - tr - t < 0.0000001) tp = tr + t;
    printf("%.6lf", tp);
  }
  return 0;
}
