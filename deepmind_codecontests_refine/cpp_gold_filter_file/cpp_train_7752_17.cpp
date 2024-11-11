#include <bits/stdc++.h>
using namespace std;
const int N = 200;
int x[N], y[N];
int n, k, e, fwgiunbf, fwnfwgwf;
inline long double prob(int i, long double r) {
  return exp(1 - max((long double)1., (((x[i] - fwgiunbf) * (x[i] - fwgiunbf) +
                                        (y[i] - fwnfwgwf) * (y[i] - fwnfwgwf)) /
                                       (max(r * r, (long double)1e-15)))));
}
long double pr[N][N];
bool can(long double r) {
  memset(pr, 0, sizeof pr);
  pr[0][0] = 1;
  for (int i = 0; i < (int)n; ++i) {
    for (int j = 0; j < (int)i + 1; ++j)
      pr[i + 1][j] += pr[i][j] * (1 - prob(i, r)),
          pr[i + 1][j + 1] += pr[i][j] * prob(i, r);
  }
  for (int i = k + 1; i <= n; i++) pr[n][k] += pr[n][i];
  return pr[n][k] > 1 - (e / 1000.);
}
int main() {
  scanf("%d%d%d%d%d", &n, &k, &e, &fwgiunbf, &fwnfwgwf);
  for (int i = 0; i < (int)n; ++i) scanf("%d%d", &x[i], &y[i]);
  long double l = 0, r = 20000;
  for (int i = 0; i < (int)100; ++i) {
    long double m = (l + r) / 2.0;
    if (can(m))
      r = m;
    else
      l = m;
  }
  printf("%.20lf\n", (double)r);
  return 0;
}
