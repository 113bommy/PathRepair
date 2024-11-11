#include <bits/stdc++.h>
int a[104], b[104][104];
int n;
int main() {
  int i, j;
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) scanf("%d", &b[i][j]);
  if (n == 1) {
    puts("-1");
    return 0;
  }
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
      if (i != j) a[i] |= b[i][j];
  for (i = 1; i <= n; i++) printf("%d ", a[i]);
  puts("");
  return 0;
}
