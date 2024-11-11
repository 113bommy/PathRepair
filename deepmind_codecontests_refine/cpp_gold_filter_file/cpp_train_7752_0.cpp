#include <bits/stdc++.h>
using namespace std;
int n, x[111], y[111], p, rq;
double r[222], d[222][222], e;
double pro(double rr, int p) { return pow(e, 1 - r[p] * r[p] / rr / rr); }
double find(double rr) {
  int i, j, k, t = 0;
  double res = 0;
  for (i = 1; i <= n; i++)
    if (r[i] > rr) break;
  if (i - 1 >= rq) return 0;
  memset(d, 0, sizeof(d));
  k = i;
  d[k - 1][k - 1] = 1;
  for (i = k; i <= n; i++)
    for (j = k - 1; j <= i; j++)
      d[i][j] = d[i - 1][j - 1] * pro(rr, i) + d[i - 1][j] * (1 - pro(rr, i));
  for (i = rq; i <= n; i++) res += d[n][i];
  return 1 - res;
}
int main() {
  int i, j, k;
  double a, b, m, t, rr, l;
  e = 2.7182818284590452353602874713527;
  cin >> n >> rq >> p;
  for (i = 0; i < n + 1; i++) cin >> x[i] >> y[i];
  for (i = 1; i <= n; i++)
    r[i] = sqrt((x[i] - x[0]) * (x[i] - x[0]) + (y[i] - y[0]) * (y[i] - y[0]) +
                0.0);
  for (i = 1; i < n; i++) {
    k = i;
    for (j = i + 1; j <= n; j++)
      if (r[j] < r[k]) k = j;
    t = r[i];
    r[i] = r[k];
    r[k] = t;
  }
  l = 0;
  rr = 999999999;
  while (rr - l > 0.0000001) {
    m = (l + rr) / 2;
    t = find(m);
    if (t * 1000 < p)
      rr = m;
    else
      l = m;
  }
  printf("%.7lf\n", m);
  return 0;
}
