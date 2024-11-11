#include <bits/stdc++.h>
double f[100100][110], C[1010][1010], ans;
int n, a[100100], b[100100], Q, u, v, k;
int main() {
  C[0][0] = 1;
  for (int i = 1; i <= 1000; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
  }
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]), b[i] = a[i], f[i][a[i]] = 1, ans += f[i][0];
  scanf("%d", &Q);
  while (Q--) {
    scanf("%d%d%d", &u, &v, &k);
    ans -= f[u][0];
    for (int i = 0; i <= a[u]; i++) {
      double tot = 0;
      for (int j = 0; j <= k; j++)
        tot += f[u][i + j] * C[i + j][j] * C[b[u] - i - j][k - j] / C[b[u]][k];
      f[u][i] = tot;
    }
    ans += f[u][0];
    b[u] -= k, b[v] += k;
    printf("%.12lf\n", ans);
  }
}
