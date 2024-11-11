#include <bits/stdc++.h>
int main() {
  int n, T, m, t0 = 0;
  double c, mean = 0.0;
  scanf("%d %d %lf", &n, &T, &c);
  long long a[n];
  long long s[n];
  for (int i = 0; i < n; i++) {
    scanf("%I64d", &a[i]);
    s[i] = ((i > 0) ? (s[i - 1]) : 0L) + a[i];
  }
  scanf("%d", &m);
  for (int j = 0; j < m; j++) {
    int p;
    scanf("%d", &p);
    p--;
    while (t0 <= p) mean = (mean + (double)a[t0++] / T) / c;
    double a_mean = ((double)(s[p] - ((p >= T) ? s[p - T] : 0L))) / T;
    double error = std::abs(mean - a_mean) / a_mean;
    printf("%.6f %.6f %.6f\n", a_mean, mean, error);
  }
  return 0;
}
