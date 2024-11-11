#include <bits/stdc++.h>
int main(void) {
  int m, n, p;
  scanf("%d%d", &n, &m);
  for (p = 1; m - p >= 0; p++) {
    m = m - p;
    if (p == n) {
      p = 0;
    }
  }
  printf("%d\n", m);
  return 0;
}
