#include <bits/stdc++.h>
using namespace std;
int c[105][105];
int n, m, lim;
int f[2][105][105][105];
int ans;
int main() {
  c[0][0] = 1;
  c[1][0] = c[1][1] = 1;
  for (int i = 2; i <= 100; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
      if (c[i][j] > 100) c[i][j] = 101;
    }
  }
  scanf("%d%d%d", &n, &m, &lim);
  ++n;
  int now = 0, last = 1;
  f[0][0][1][1] = 1;
  for (int i = 0; i <= min(n, m); i++) {
    swap(last, now);
    memset(f[now], 0, sizeof(f[now]));
    int sum = 0;
    for (int j = 2; j <= n; j++)
      for (int k = 1; k <= lim; k++) {
        sum += f[last][j][0][k];
        if (sum >= 1000000007) sum -= 1000000007;
      }
    ans = (ans + 1ll * sum * (m - i + 1)) % 1000000007;
    for (int j = 0; j <= n; j++)
      for (int k = 1; k <= j; k++)
        for (int l = 1; l <= lim; l++) {
          if (f[last][j][k][l] == 0) continue;
          for (int l1 = k; l1 <= n - j; l1++) {
            if (l * c[l1 - 1][k - 1] > lim) break;
            f[now][j + l1][l1 - k][l * c[l1 - 1][k - 1]] += f[last][j][k][l];
            if (f[now][j + l1][l1 - k][l * c[l1 - 1][k - 1]] >= 1000000007)
              f[now][j + l1][l1 - k][l * c[l1 - 1][k - 1]] -= 1000000007;
          }
        }
  }
  printf("%d", ans);
  return 0;
}
