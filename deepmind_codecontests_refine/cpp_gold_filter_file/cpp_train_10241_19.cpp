#include <bits/stdc++.h>
using namespace std;
int a[500000][2], n;
bool fun(double t) {
  double imax = -1e21;
  for (int i = 0; i < n; ++i) {
    if (a[i][1] > 0)
      imax = max(imax, a[i][0] + a[i][1] * t);
    else if (a[i][0] + a[i][1] * t <= imax)
      return true;
  }
  return false;
}
int main() {
  while (~scanf("%d", &n)) {
    for (int i = 0; i < n; ++i) scanf("%d%d", &a[i][0], &a[i][1]);
    double r = 1e10;
    double l = 0;
    int t = 100;
    while (t--) {
      double mid = (r + l) / 2;
      if (fun(mid))
        r = mid;
      else
        l = mid;
    }
    if (r == 1e10)
      puts("-1");
    else
      printf("%.20f\n", r);
  }
  return 0;
}
