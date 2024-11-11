#include <bits/stdc++.h>
int tot;
int main(void) {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int e = 0; e < k; e++) {
    tot += (2 * n) + (2 * (m - 2));
    n -= 2;
    m -= 2;
  }
  printf("%d", tot);
}
