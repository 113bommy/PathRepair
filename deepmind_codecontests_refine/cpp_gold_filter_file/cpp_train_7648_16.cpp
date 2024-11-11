#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-12;
const int N = 2e5 + 7, MOD = 1000000007;
int n, m, q;
double c, mean[N], t, a[N], post[N], re, ap, er;
int main() {
  scanf("%d%lf%lf", &n, &t, &c);
  mean[0] = 0.0;
  for (int i = 0; i < n; i++) {
    scanf("%lf", &a[i]);
    if (i == 0)
      mean[i] = (double(a[i]) / t) / c;
    else
      mean[i] = (mean[i - 1] + double(a[i]) / t) / c;
  }
  post[0] = a[0];
  for (int i = 1; i < n; i++) post[i] = post[i - 1] + a[i];
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d", &q);
    ap = mean[q - 1];
    re = post[q - 1];
    if (q > t) re -= post[int(q - t - 1)];
    re = re / t;
    er = fabs(ap - re) / re;
    printf("%.6lf %.6lf %.6lf\n", re, ap, er);
  }
  return 0;
}
