#include <bits/stdc++.h>
using namespace std;
const int N = 5050;
int f[N][N], a[N], n, X[7], Y[100500], ans;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 0; i <= n; i++) {
    memset(X, 0, sizeof(X)), memset(Y, 0, sizeof(Y));
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      if (i < j)
        ans = max(ans, f[j][i] = f[i][j] =
                           max(max(Y[a[j] + 1], max(Y[a[j] - 1], X[a[j] % 7])),
                               f[i][0]) +
                           1);
      X[a[j] % 7] = max(X[a[j] % 7], f[i][j]), Y[a[j]] = max(Y[a[j]], f[i][j]);
    }
  }
  printf("%d\n", ans);
}
