#include <bits/stdc++.h>
using namespace std;
int n, m, k, t;
int a[1005][501];
int sum[20][20];
int ans = 0;
int main() {
  scanf("%d%d%d%d", &n, &m, &k, &t);
  while (t--) {
    int x, y;
    scanf("%d%d", &x, &y);
    a[x][y]++;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      for (int i1 = i; i1 <= n; i1++)
        for (int j1 = j; j1 <= m; j1++) {
          int ss =
              sum[i1][j1] - sum[i1][j - 1] - sum[i - 1][j1] + sum[i - 1][j - 1];
          if (ss == k) ans++;
        }
    }
  printf("%d", ans);
  return 0;
}
