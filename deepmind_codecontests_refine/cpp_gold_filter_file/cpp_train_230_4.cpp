#include <bits/stdc++.h>
int T;
int n;
int Max(int a, int b) { return a > b ? a : b; }
int Min(int a, int b) { return a < b ? a : b; }
int Abs(int a) { return a < 0 ? -a : a; }
const double PI = 3.1415926535897932;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    if (!(n & 1)) {
      double a = (180.0 - (180.0 / (double)n)) / 2.0;
      double ans = 0.5 * tan(PI / 180 * a);
      printf("%.9lf\n", ans * 2.0);
    } else {
      double x = (PI / 4.0) / n;
      double ans1 = 0, ans2 = 0;
      double _x = x;
      for (int i = 1; i <= n; ++i) ans1 += sin(_x), _x += PI / n;
      _x = x;
      for (int i = 1; i < n; ++i) ans2 += cos(_x), _x += PI / n;
      printf("%.9lf\n", ans1 > ans2 ? ans1 : ans2);
    }
  }
}
