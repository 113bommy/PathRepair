#include <bits/stdc++.h>
using namespace std;
int n, m, a[100010], b[100010], C[10][10];
double ans, f[100010][105];
void work() {
  scanf("%d", &n), ans = 0;
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]), b[i] = a[i], f[i][a[i]] = 1, ans += (a[i] == 0);
  scanf("%d", &m);
  for (int i = 0; i <= 5; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
  }
  for (int i = 1, u, v, k; i <= m; i++) {
    scanf("%d %d %d", &u, &v, &k);
    ans -= f[u][0];
    for (int j = 0; j <= b[u]; j++) {
      double x = f[u][j];
      f[u][j] = 0;
      for (int l = 0; l <= k; l++) {
        double y = 1;
        for (int p = 1; p <= l; p++) y *= 1.0 * (j - p + 1) / (a[u] - p + 1);
        for (int p = 1; p <= k - l; p++)
          y *= 1.0 * (a[u] - j - p + 1) / (a[u] - l - p + 1);
        f[u][j - l] += x * y * C[k][l];
      }
    }
    a[u] -= k, a[v] += k;
    ans += f[u][0];
    printf("%.10lf\n", ans);
  }
}
int main() {
  work();
  return 0;
}
