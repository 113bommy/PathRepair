#include <bits/stdc++.h>
using namespace std;
int n, x, sum;
double ans;
int a[1000];
double f[110][11005];
double C[110][110];
int main() {
  int i, j, k;
  scanf("%d%d", &n, &x);
  sum = 0;
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  f[0][0] = 1;
  for (i = 1; i <= n; i++) {
    sum += a[i];
    for (j = i; j >= 1; j--) {
      for (k = a[i]; k <= sum; k++) {
        f[j][k] += f[j - 1][k - a[i]];
      }
    }
  }
  C[0][0] = 1;
  for (i = 1; i <= n; i++) {
    C[i][0] = 1;
    for (j = 1; j <= i; j++) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= sum; j++) {
      ans += 1.0 * f[i][j] / C[n][i] * min((n + i) * x, j * 2) / i;
    }
  }
  printf("%.10lf\n", ans / 2);
  return 0;
}
