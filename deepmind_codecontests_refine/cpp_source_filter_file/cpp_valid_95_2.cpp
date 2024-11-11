#include <bits/stdc++.h>
int T, n, m;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i < m; i++) {
      int j = pow(10, (int)log10(n - m));
      printf("%d ", j), n -= j;
    }
    printf("%d\n", n);
  }
  return 0;
}
