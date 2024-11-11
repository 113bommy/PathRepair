#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int i, j, a[n][n];
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) scanf("%d", &a[i][j]);
  int ans;
  for (i = 0; i < n; i++) ans += a[i][i] * a[i][i];
  ans %= 2;
  int q;
  scanf("%d", &q);
  while (q--) {
    int x, y;
    scanf("%d", &x);
    if (x == 1 || x == 2) {
      scanf("%d", &y);
      ans = 1 - ans;
    } else
      printf("%d", ans);
  }
}
