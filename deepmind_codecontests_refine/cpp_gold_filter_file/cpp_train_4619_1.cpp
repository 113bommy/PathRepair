#include <bits/stdc++.h>
int main() {
  int n, a[1001][4];
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= 3; j++) scanf("%d", &a[i][j]);
  int p = 0;
  for (int i = 1; i <= n; i++) {
    int s = 0;
    for (int j = 1; j <= 3; j++)
      if (a[i][j] == 1) s++;
    if (s >= 2) p++;
  }
  printf("%d", p);
}
