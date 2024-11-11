#include <bits/stdc++.h>
int main() {
  int T, n, i, p;
  scanf("%d", &T);
  for (T; T > 0; T--) {
    scanf("%d", &n);
    p = 4 * n;
    for (i = 1; i <= n; i++) {
      p = p - 2;
      printf("%d ", p);
    }
  }
}
