#include <bits/stdc++.h>
using namespace std;
int N;
double A[100002];
long double S[100002];
int main() {
  scanf("%d", &N);
  S[0] = 1.0;
  for (int i = 1; i <= N; i++) scanf("%lf", A + i), S[i] = S[i - 1] * A[i];
  double ans = 0.0;
  long double sum1 = 0.0, sum2 = 0.0, sum3 = 0.0;
  for (int i = 1; i <= N; i++) {
    if (S[i] <= 1e-100) {
      double sum = 0.0, prod = 1.0;
      for (int j = i; j >= max(1, i - 100); j--) {
        prod *= A[j];
        sum += prod * (1.0 - A[j - 1]) * (i - j + 1) * (i - j + 1);
      }
      ans += sum * (1.0 - A[i + 1]);
    } else {
      int j = i - 1;
      sum1 += (1.0 - A[j]) / S[j];
      sum2 += (1.0 - A[j]) / S[j] * j;
      sum3 += (1.0 - A[j]) / S[j] * j * j;
      ans += (sum1 * i * i - sum2 * 2 * i + sum3) * S[i] * (1.0 - A[i + 1]);
    }
  }
  printf("%.9f\n", ans);
  return 0;
}
