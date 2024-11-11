#include <bits/stdc++.h>
int main() {
  int n, k;
  int a[1005][1005];
  scanf("%d%d", &n, &k);
  int ans = 0;
  for (int i = 1; i < n; i++) ans += i;
  if (n * k > ans) {
    printf("-1\n");
    return 0;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) a[i][j] = true;
  printf("%d\n", n * k);
  for (int i = 1; i <= n; i++) {
    int now = 0;
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      if (now == k) break;
      if (a[i][j] && a[j][i]) {
        printf("%d %d\n", i, j);
        a[j][i] = a[i][j] = false;
        now++;
      }
    }
  }
  return 0;
}
