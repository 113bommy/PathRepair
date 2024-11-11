#include <bits/stdc++.h>
using namespace std;
int a[105][105];
int n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
  int ans = 0;
  for (int i = 1; i <= n; i++) ans += a[i][n / 2 + 1];
  for (int j = 1; j <= n; j++) ans += a[j][n / 2 + 1];
  for (int i = 1, j = 1; i <= n; i++, j++) ans += a[i][j];
  for (int i = n, j = 1; i >= 1; i--, j++) ans += a[i][j];
  ans -= 3 * a[n / 2 + 1][n / 2 + 1];
  printf("%d\n", ans);
  return 0;
}
