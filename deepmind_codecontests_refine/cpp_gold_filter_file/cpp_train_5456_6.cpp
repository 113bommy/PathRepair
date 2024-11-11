#include <bits/stdc++.h>
using namespace std;
bool debug = false;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
long long ln, lk, lm;
int main() {
  scanf("%d", &n);
  double x;
  double ss = 0;
  for (int(i) = 0; (i) < (int)(n + n); (i)++) {
    scanf("%lf", &x);
    x -= floor(x);
    if (abs(x) < 1e-9)
      m++;
    else
      ss += x;
  }
  double ans = (1 << 30);
  for (int i = 0; i <= min(n, m); i++) {
    if (n - i <= n + n - m) {
      ans = min(ans, abs(ss - (n - i)));
    }
  }
  printf("%.3lf\n", ans);
  return 0;
}
