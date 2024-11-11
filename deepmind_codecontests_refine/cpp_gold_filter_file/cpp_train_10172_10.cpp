#include <bits/stdc++.h>
using namespace std;
int n, m;
double aaaa[1010][1010];
double do_it(int n, int m) {
  if (!n) return 1.0 / (m + 1);
  if (!m) return 1.0;
  if (aaaa[n][m]) return aaaa[n][m];
  double a = 1.0 * m / (m + 1.0) * (1.0 - do_it(m - 1, n)), b = 1.0;
  double c = 1.0 / (m + 1.0) + a, d = 1.0 - do_it(m, n - 1);
  double awa = (d - b) / (a - b - c + d);
  return aaaa[n][m] = awa * a + (1 - awa) * b;
}
int main() {
  scanf("%d%d", &n, &m);
  double ans = do_it(n, m);
  printf("%.10f %.10f", ans, 1.0 - ans);
  while (1) return 0;
}
