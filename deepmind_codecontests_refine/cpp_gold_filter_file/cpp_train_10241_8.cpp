#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000")
using namespace std;
double x[500 * 1000 + 10];
double v[500 * 1000 + 10];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) scanf("%lf%lf", &x[i], &v[i]);
  double lower = 0;
  double upper = 2e9;
  int iter = 0;
  while (fabs(lower - upper) > ((1e-9) / 2.0)) {
    ++iter;
    if (iter == 100) break;
    double t = lower + (upper - lower) / 2.0;
    double max_x = -10e100;
    bool ok = false;
    for (int i = 0; i < n; ++i)
      if (v[i] > 0) {
        max_x = max(max_x, x[i] + t * v[i]);
      } else {
        if (max_x >= x[i] + t * v[i]) {
          ok = true;
          break;
        }
      }
    if (ok)
      upper = t;
    else
      lower = t;
  }
  double t = upper;
  bool ok = false;
  double max_x = -10e100;
  for (int i = 0; i < n; ++i)
    if (v[i] > 0) {
      max_x = max(max_x, x[i] + t * v[i]);
    } else {
      if (max_x >= x[i] + t * v[i]) {
        ok = true;
        break;
      }
    }
  if (ok)
    printf("%0.12lf", t);
  else
    cout << -1;
  return 0;
}
