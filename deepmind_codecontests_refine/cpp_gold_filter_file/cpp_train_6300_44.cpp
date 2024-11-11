#include <bits/stdc++.h>
using namespace std;
int i, j, k, n, maxd = 200000;
double p[101], f[101], last = 1, now, ans;
int main() {
  scanf("%d\n", &n);
  for (i = 1; i <= n; ++i) {
    scanf("%lf", &p[i]);
    last *= (f[i] = (p[i] /= 100));
  }
  ans = last * n;
  for (i = n + 1; i <= maxd; ++i) {
    k = 1;
    for (j = 2; j <= n; ++j)
      if ((1 - f[k]) * p[k] * f[j] < (1 - f[j]) * p[j] * f[k]) k = j;
    now = last * (1 + (1 - f[k]) * p[k] / f[k]);
    f[k] += (1 - f[k]) * p[k];
    ans += i * (now - last);
    last = now;
  }
  printf("%.10f\n", ans);
}
