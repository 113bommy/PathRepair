#include <bits/stdc++.h>
double ans, p[200];
int main() {
  int n, i, j;
  double a, b, tmp;
  scanf("%d", &n);
  for (i = 0; i <= n; i++) {
    scanf("%lf", &p[i]);
    if (2 * i <= n && p[i] > ans) ans = p[i];
  }
  for (i = 0; 2 * i <= n; i++)
    for (j = n / 2; j <= n; j++) {
      a = n - i * 2;
      b = j * 2 - n;
      if (b < 0) continue;
      tmp = a * p[j] + b * p[i];
      tmp /= a + b;
      if (tmp > ans) ans = tmp;
    }
  printf("%.10lf", ans);
}
