#include <bits/stdc++.h>
int main() {
  int n, p, q, i, count = 0;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d %d", &p, &q);
    if (q - p >= 2) {
      count++;
    }
  }
  printf("%d", count);
  return 0;
}
