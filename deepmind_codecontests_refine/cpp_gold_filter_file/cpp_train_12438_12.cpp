#include <bits/stdc++.h>
using namespace std;
int x[200005];
int main() {
  memset(x, 0, sizeof(x));
  int n = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x[i]);
  }
  sort(x, x + n);
  double eps = 1e-10, l = 0.0, r = (double)(x[n - 1] - x[0]) / 6.0;
  int p1 = 0, p2 = 0;
  while (r - l > eps) {
    double mid = l + (r - l) / 2.0;
    p1 = upper_bound(x, x + n, x[0] + 2 * mid) - x;
    if (p1 == n) {
      r = mid;
      continue;
    }
    p2 = upper_bound(x, x + n, x[p1] + 2 * mid) - x;
    if (p2 == n || (double)(x[n - 1] - x[p2]) <= 2 * mid - eps) {
      r = mid;
    } else {
      l = mid;
    }
  }
  double tmp = x[0] + 2 * l;
  int idx = lower_bound(x, x + n, (int)(tmp - 1)) - x;
  for (; idx < n; ++idx) {
    if (x[idx] > x[0] + (int)(2 * l + 0.1)) {
      break;
    }
  }
  printf("%.6lf\n", l);
  printf("%.6lf %.6lf %.6lf", (double)x[0] + l, (double)x[idx] + l,
         (double)x[n - 1] - l);
  return 0;
}
