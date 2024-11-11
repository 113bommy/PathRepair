#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 105;
int N, c[MAX_N], sum;
long double f[MAX_N][MAX_N * MAX_N], X;
int main() {
  scanf("%d %Lf", &N, &X);
  X /= 2.0;
  for (int i = 1; i <= N; i++) scanf("%d", c + i), sum += c[i];
  f[0][0] = 1;
  for (int i = 1; i <= N; i++)
    for (int k = i; k; k--)
      for (int j = sum; j >= c[i]; j--)
        f[k][j] += f[k - 1][j - c[i]] * k / (long double)(N - k + 1);
  long double ans = 0;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= sum; j++)
      ans += f[i][j] * min(1.0L * j / i, (1.0 * N / i + 1) * X);
  printf("%0.13Lf\n", ans);
  return 0;
}
