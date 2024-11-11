#include <bits/stdc++.h>
using namespace std;
double x[111111];
double sX, sY;
int n, K;
double Solve(int l, int r) {
  if (l > r) return 0;
  return min(hypot(x[l] - sX, sY), hypot(x[r] - sX, sY)) + x[r] - x[l];
}
int main() {
  scanf("%d%d", &n, &K);
  K--;
  for (int i = 0; i < n; ++i) scanf("%lf", x + i);
  scanf("%lf%lf", &sX, &sY);
  double ans = 1e100;
  if (K == n) {
    sort(x, x + n);
    ans = Solve(0, n - 1);
    return printf("%.9f\n", ans), 0;
  }
  K = x[K];
  sort(x, x + n);
  K = lower_bound(x, x + n, K) - x;
  for (int l = 1; l < n; ++l)
    if (l <= K) {
      int rl = 0, rr = l - 1;
      double a = x[K] - x[l], b = x[n - 1] - x[K], t;
      t = 2 * b + a + hypot(x[l] - sX, sY) + Solve(rl, rr);
      ans = min(ans, t);
      t = 2 * a + b + hypot(x[n - 1] - sX, sY) + Solve(rl, rr);
      ans = min(ans, t);
    }
  for (int r = 0; r < n; ++r)
    if (K <= r) {
      int rl = r + 1, rr = n - 1;
      double a = x[K] - x[0], b = x[r] - x[K], t;
      t = 2 * b + a + hypot(x[0] - sX, sY) + Solve(rl, rr);
      ans = min(ans, t);
      t = 2 * a + b + hypot(x[r] - sX, sY) + Solve(rl, rr);
      ans = min(ans, t);
    }
  printf("%.9f\n", ans);
  return 0;
}
