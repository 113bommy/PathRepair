#include <bits/stdc++.h>
using namespace std;
int n, T, a[200100], m, p[200100];
long long sum[200100];
long double c, mean[200100];
int main() {
  scanf("%d%d%lf", &n, &T, &c);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    sum[i] = sum[i - 1] + a[i];
  }
  scanf("%d", &m);
  for (int i = 0; i < m; i++) scanf("%d", &p[i]);
  for (int i = 1; i <= n; i++) {
    mean[i] = mean[i - 1] / c + (a[i] + .0) / (T * c);
  }
  for (int i = 0; i < m; i++) {
    int ti = p[i];
    double t_real = (sum[ti] - sum[ti - T] + .0) / (T);
    double t_approx = mean[ti];
    double t_error = abs(t_approx - t_real) / t_real;
    printf("%.6f %.6f %.6f\n", t_real, t_approx, t_error);
  }
  return 0;
}
