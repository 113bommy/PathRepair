#include <bits/stdc++.h>
int main(void) {
  int n, m;
  scanf("%d%d", &n, &m);
  if (m <= 1) {
    printf("1\n");
    return 0;
  }
  if (2 * m <= n) {
    printf("%d\n", m - 1);
  } else {
    printf("%d\n", n - m);
  }
  return 0;
}
