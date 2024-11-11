#include <bits/stdc++.h>
int main() {
  int n, m, i, j, a;
  scanf("%d%d", &n, &m);
  for (i = n + 1; i <= m; i++) {
    for (j = 2; j <= i / 2; j++)
      if (i % j == 0) goto x;
    printf(i == m ? "YES" : "NO");
    break;
  x:
    if (i == m) printf("NO");
  }
  return 0;
}
