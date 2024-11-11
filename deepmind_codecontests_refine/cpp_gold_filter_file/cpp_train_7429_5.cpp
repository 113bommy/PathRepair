#include <bits/stdc++.h>
const int MAXN = 100005;
int n, q, A[MAXN], B[MAXN];
double ans, f[MAXN][105];
int main() {
  scanf("%d", &n);
  for (register int i = 1; i <= n; ++i)
    scanf("%d", A + i), f[i][B[i] = A[i]] = 1, ans += f[i][0];
  scanf("%d", &q);
  register int u, v, k;
  while (q--) {
    scanf("%d%d%d", &u, &v, &k);
    ans -= f[u][0];
    for (register int i = 1; i <= k; ++i)
      for (register int j = 0; j <= A[u]; ++j)
        f[u][j] = f[u][j] * (B[u] - i + 1 - j) / (B[u] - i + 1) +
                  f[u][j + 1] * (j + 1) / (B[u] - i + 1);
    ans += f[u][0];
    B[u] -= k;
    B[v] += k;
    printf("%.12lf\n", ans);
  }
  return 0;
}
