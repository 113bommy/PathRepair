#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double C = 0.57721566490153286060651209;
const double pi = acos(-1.0);
const int mod = 1e9 + 7;
const int maxn = 2e5 + 10;
const int INF = 0x3f3f3f3f;
struct ss {
  double x, y;
  bool operator<(const ss &q) const { return y < q.y; }
} a[maxn];
int main() {
  int n, T;
  scanf("%d %d", &n, &T);
  for (int i = 1; i <= n; ++i) {
    scanf("%lf", &a[i].x);
  }
  for (int j = 1; j <= n; ++j) scanf("%lf", &a[j].y);
  sort(a + 1, a + 1 + n);
  double psum = 0, nsum = 0, ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (fabs(a[i].y - T) < eps)
      ans += a[i].x;
    else if (a[i].y < T)
      nsum += (T - a[i].y) * a[i].x;
    else
      psum += (a[i].y - T) * a[i].x;
  }
  double sum = min(psum, nsum);
  double tsum = 0;
  for (int i = 1; i <= n; ++i)
    if (a[i].y > T) {
      tsum += a[i].x * (a[i].y - T);
      if (tsum <= sum)
        ans += a[i].x;
      else {
        ans += a[i].x - (tsum - sum) / (a[i].y - T);
        break;
      }
    }
  tsum = 0;
  for (int i = n; i >= 1; --i)
    if (a[i].y < T) {
      tsum += a[i].x * (T - a[i].y);
      if (tsum <= sum)
        ans += a[i].x;
      else {
        ans += a[i].x - (tsum - sum) / (T - a[i].y);
        break;
      }
    }
  printf("%.10f\n", ans);
  return 0;
}
