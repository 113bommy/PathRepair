#include <bits/stdc++.h>
int main() {
  int n, p, k;
  scanf("%d %d %d", &n, &p, &k);
  if (p - k > 1) printf("<< ");
  for (int i = 0; i < 2 * k + 1 && p - k + i <= n; i++) {
    if (p - k + i < 1) continue;
    if (i == k)
      printf("(%d) ", p - k + i);
    else
      printf("%d ", p - k + i);
  }
  if (p + k < n) printf(" >>");
  return 0;
}
