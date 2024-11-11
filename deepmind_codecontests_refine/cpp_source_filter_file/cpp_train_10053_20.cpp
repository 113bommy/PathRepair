#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
const double eps = 1e-10;
double f[N][N], p[N], u[N], t[N];
int cnt[N][N], n, a, b;
inline int check(double k) {
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= a; ++j) {
      f[i][j] = f[i - 1][j];
      cnt[i][j] = cnt[i - 1][j];
      if (j > 0 && f[i - 1][j - 1] + p[i] > f[i][j])
        f[i][j] = f[i - 1][j - 1] + p[i], cnt[i][j] = cnt[i - 1][j - 1];
      if (f[i - 1][j] + u[i] - k > f[i][j])
        f[i][j] = f[i - 1][j] + u[i] - k, cnt[i][j] = cnt[i - 1][j] + 1;
      if (j > 0 && f[i - 1][j - 1] + t[i] - k > f[i][j])
        f[i][j] = f[i - 1][j - 1] + t[i] - k, cnt[i][j] = cnt[i - 1][j - 1] + 1;
    }
  }
  return cnt[n][a];
}
int main() {
  scanf("%d %d %d", &n, &a, &b);
  for (int i = 1; i <= n; ++i) scanf("%lf", &p[i]);
  for (int i = 1; i <= n; ++i)
    scanf("%lf", &u[i]), t[i] = 1.0 - (1.0 - p[i]) * (1.0 - u[i]);
  double l = 0, r = 1, mid;
  int use;
  while (l + eps < r) {
    mid = (l + r) / 2.0;
    use = check(mid);
    if (use == b) break;
    if (use < b)
      r = mid;
    else
      l = mid;
  }
  check(mid);
  printf("%.10lf", f[n][a] + 1.0 * cnt[n][a] * mid);
  return 0;
}
