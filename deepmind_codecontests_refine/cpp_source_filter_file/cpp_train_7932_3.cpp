#include <bits/stdc++.h>
using namespace std;
const int N = 105, M = 10005;
int n, c[N];
double x, f[N][M], ans, fac[N] = {1}, sum;
int C(int a, int b) { return fac[a] / fac[b] / fac[a - b]; }
int main(void) {
  scanf("%d%lf", &n, &x);
  x /= 2;
  for (int i = 1; i <= n; i++) scanf("%d", c + i);
  for (int i = 1; i <= n; i++) sum += c[i], fac[i] = fac[i - 1] * i;
  f[0][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = n; j; j--)
      for (int k = sum; k >= c[i]; k--) f[j][k] = f[j][k] + f[j - 1][k - c[i]];
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= sum; j++)
      ans += f[i][j] * min((sum - j) / (n - i), x * (1.0 * n / (n - i) + 1)) /
             C(n, i);
  printf("%.10lf\n", ans);
  return 0;
}
