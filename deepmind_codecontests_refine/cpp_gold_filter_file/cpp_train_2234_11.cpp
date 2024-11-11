#include <bits/stdc++.h>
int main() {
  int n, m, x;
  scanf("%d %d", &n, &m);
  for (int i = 0; i <= n; i++) {
    if ((n - i) % 2 == 0) {
      x = (n - i) / 2;
      if ((x + i) % m == 0) {
        printf("%d", x + i);
        return 0;
      }
    }
  }
  printf("-1");
}
