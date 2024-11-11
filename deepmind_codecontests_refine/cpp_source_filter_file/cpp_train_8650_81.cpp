#include <bits/stdc++.h>
using namespace std;
int n, m, sum, cnt, ans, a[101], f[10001][101], fa[101], f1[101][101];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    sum += a[i], fa[a[i]]++, cnt = cnt + (fa[a[i]] == 1) ? 1 : 0;
  }
  f[0][0] = 1, f1[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    f1[i][0] = f1[i][i] = 1;
    for (int j = 1; j < i; j++) f1[i][j] = f1[i - 1][j - 1] + f1[i - 1][j];
  }
  for (int i = 1; i <= n; i++)
    for (int j = sum - a[i]; j >= 0; j--)
      for (int k = 0; k < i; k++) f[j + a[i]][k + 1] += f[j][k];
  for (int i = 1; i <= 100; i++)
    for (int j = 1; j <= fa[i]; j++)
      if (f[i * j][j] == f1[fa[i]][j]) {
        ans = std ::max(ans, j);
        if (j == fa[i] && cnt == 2) ans = std ::max(ans, n);
      }
  printf("%d\n", ans);
  return 0;
}
