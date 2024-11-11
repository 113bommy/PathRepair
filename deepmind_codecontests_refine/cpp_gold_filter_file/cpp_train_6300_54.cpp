#include <bits/stdc++.h>
double p[111], q[111], L[111], R[111];
int c[111];
int N;
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%lf", &p[i]);
    p[i] /= 100;
    q[i] = 1 - p[i];
  }
  double ans = 1, mul = 1;
  for (int i = 1; i <= N; i++) ans = ans * p[i], mul = mul * (1 - q[i]);
  ans = ans * N;
  for (int i = N + 1; i <= 1000000; i++) {
    double m = 0;
    int k = 0;
    for (int j = 1; j <= N; j++) {
      double val = mul / (1 - q[j]) * q[j] * p[j];
      if (val > m) {
        m = val;
        k = j;
      }
    }
    ans = ans + m * (double)i;
    mul = mul / (1 - q[k]);
    q[k] = q[k] * (1 - p[k]);
    mul = mul * (1 - q[k]);
  }
  printf("%lf", ans);
  return 0;
}
