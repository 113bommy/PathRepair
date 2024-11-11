#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, a, b, c, t, ans;
double x[2001], y[2001], k[2001];
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d%d%d", &a, &b, &c);
    t = a * a + b * b;
    x[i] = (double)a * c / t;
    y[i] = (double)b * c / t;
  }
  for (i = 1; i < n; i++) {
    m = 0;
    for (j = i + 1; j <= n; j++)
      if (fabs(x[i] - x[j]) < 1e-15)
        if (fabs(y[i] - y[j]) < 1e-15)
          ans += n - i - 1;
        else
          k[++m] = 1e15;
      else
        k[++m] = (y[i] - y[j]) / (x[i] - x[j]);
    sort(k + 1, k + m + 1);
    t = 1;
    for (j = 2; j <= m; j++)
      if (fabs(k[j] - k[j - 1]) < 1e-12)
        t++;
      else {
        ans += t * (t - 1) / 2;
        t = 1;
      }
    ans += t * (t - 1) / 2;
  }
  printf("%d\n", ans);
  return 0;
}
