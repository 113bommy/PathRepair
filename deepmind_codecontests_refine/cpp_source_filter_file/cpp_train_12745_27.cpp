#include <bits/stdc++.h>
int main() {
  int n, p, k;
  scanf("%d %d %d", &n, &p, &k);
  if (p - 2 > 1) printf("<< ");
  for (int i = 0; i < 2 * k + 1 && p - 2 + i <= n; i++) {
    if (p - 2 + i < 1) continue;
    if (i == 2)
      printf("(%d) ", p - 2 + i);
    else
      printf("%d ", p - 2 + i);
  }
  if (p + 2 < n) printf(" >>");
  return 0;
}
