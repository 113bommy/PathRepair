#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, n, T, m;
  double c;
  double real = 0.0, appr = 0.0, err = 0.0;
  double ex = 0.0;
  scanf("%d %d %lf", &n, &T, &c);
  int a[n];
  double mean[n];
  long long sum[n - T + 1];
  for (i = 0; i < n - T + 1; i++) sum[i] = 0;
  scanf("%d", &a[0]);
  sum[0] += a[0];
  mean[0] = ((double)(a[0]) / (double)T) / c;
  for (i = 1; i < T; i++) {
    scanf("%d", &a[i]);
    sum[0] += a[i];
    mean[i] = (mean[i - 1] + a[i] / (double)T) / c;
  }
  for (i = T; i < n; i++) {
    scanf("%d", &a[i]);
    sum[i - T + 1] = sum[i - T] - a[i - T] + a[i];
    mean[i] = (mean[i - 1] + a[i] / (double)T) / c;
  }
  scanf("%d", &m);
  int q;
  for (i = 0; i < m; i++) {
    scanf("%d", &q);
    ex = (double)(sum[q - T]) / T;
    printf("%.6f %.6f %.6f\n", ex, mean[q - 1], abs(ex - mean[q - 1]) / ex);
  }
  return 0;
}
