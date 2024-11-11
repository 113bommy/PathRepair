#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double eps = 1e-20;
int main() {
  int n, a, d;
  cin >> n >> a >> d;
  int *t = new int[n];
  int *v = new int[n];
  double ans = -1.0;
  for (int i = 0; i < n; i++) cin >> t[i] >> v[i];
  for (int i = 0; i < n; i++) {
    double t1 = (v[i] + 0.0) / (a + 0.0);
    double t2 = (d - a * t1 * t1 * 0.5) / (v[i] + 0.0);
    if (a * t1 * t1 * 0.5 >= d) {
      t1 = sqrt(2.0 * d / (a + 0.0));
      t2 = 0;
    }
    double tt = t1 + t2 + t[i];
    if (tt > ans) {
      printf("%.6f\n", tt);
      ans == tt;
    } else
      printf("%.6f\n", ans);
  }
  return 0;
}
