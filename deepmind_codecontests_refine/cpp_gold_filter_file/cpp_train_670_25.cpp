#include <bits/stdc++.h>
using namespace std;
int n, T;
int t[5005];
double p[5005], pp;
double f[5005][5005];
double dq;
int main() {
  scanf("%d%d", &n, &T);
  for (int i = 1; i <= n; ++i) {
    scanf("%lf", &p[i]);
    p[i] /= 100.0;
    scanf("%d", &t[i]);
  }
  for (int i = 1; i <= n + 1; ++i)
    for (int j = 0; j <= T; ++j) f[i][j] = 0;
  for (int i = n; i >= 1; --i) {
    f[i][0] = 0;
    dq = 0;
    pp = 1.0;
    for (int j = 1; j <= t[i]; ++j) pp = pp * (1 - p[i]);
    for (int j = 1; j <= T; ++j) {
      dq = dq * (1 - p[i]);
      dq += p[i] * (f[i + 1][j - 1] + 1);
      if (j >= t[i] + 1) {
        dq -= (f[i + 1][j - t[i] - 1] + 1) * pp * p[i];
      }
      if (j >= t[i])
        f[i][j] = dq + pp * (f[i + 1][j - t[i]] + 1);
      else
        f[i][j] = dq;
    }
  }
  printf("%.10lf\n", f[1][T]);
  return 0;
}
