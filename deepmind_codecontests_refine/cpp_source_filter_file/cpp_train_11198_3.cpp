#include <bits/stdc++.h>
int main() {
  int n, m, a, b, min;
  scanf("%d%d%d%d", &n, &m, &a, &b);
  min = (b - a) + 1;
  int i;
  for (i = 1; i < m; i++) {
    scanf("%d%d", &a, &b);
    if (min > ((b - a) + 1)) {
      min = (b - a) + 1;
    }
  }
  printf("%d\n", min);
  for (i = 0; i < n; i++) {
    printf("%d ", i % m);
  }
  printf("\n");
  return 0;
}
