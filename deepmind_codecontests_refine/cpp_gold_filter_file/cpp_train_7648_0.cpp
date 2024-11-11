#include <bits/stdc++.h>
int a[200000];
long long aa[200001];
double aprox[200001];
int main() {
  int n;
  double T, c;
  int i;
  scanf("%d %lf %lf", &n, &T, &c);
  for (i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    aa[i] = aa[i - 1] + a[i];
    aprox[i] = (aprox[i - 1] + a[i] / T) / c;
  }
  int q, m;
  scanf("%d", &m);
  for (i = 0; i < m; ++i) {
    scanf("%d", &q);
    double real = (aa[q] - aa[(int)(q - T)]) / T;
    double error = fabs(aprox[q] - real) / real;
    printf("%.5lf %.5lf  %.5lf\n", real, aprox[q], error);
  }
  return 0;
}
