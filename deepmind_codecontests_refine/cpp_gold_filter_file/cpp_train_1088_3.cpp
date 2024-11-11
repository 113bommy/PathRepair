#include <bits/stdc++.h>
int main() {
  int n, k, p, i;
  scanf("%d%d", &n, &k);
  for (i = 1; i <= k; i++) {
    p = (i + 1) / 2;
    if (i % 2)
      printf("%d ", p);
    else
      printf("%d ", k + 2 - p);
  }
  printf("%d ", p + 1);
  for (i = k + 2; i <= n; i++) printf("%d ", i);
  return 0;
}
