#include <bits/stdc++.h>
using namespace std;
double p[110];
inline double max(double x, double y) { return x > y ? x : y; }
int main() {
  register int n, m, i, j;
  double x, f;
  scanf("%d", &n), m = n >> 1;
  for (i = 0; i <= n; ++i) scanf("%lf", &p[i]);
  if (m == (double)n * 0.5)
    for (i = m; i <= n; ++i)
      for (j = 0; j < m; ++j) {
        x = (double)((i << 1) - n) / (n - (j << 1));
        f = max(f, (x * p[j] + p[i]) / (x + 1));
      }
  else
    for (i = m + 1; i <= n; ++i)
      for (j = 0; j <= m; ++j) {
        x = (double)((i << 1) - n) / (n - (j << 1));
        f = max(f, (x * p[j] + p[i]) / (x + 1));
      }
  printf("%.10lf", f);
  return 0;
}
