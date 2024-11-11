#include <bits/stdc++.h>
int main() {
  int n, m, i;
  scanf("%d%d", &n, &m);
  if (n / m == 0) {
    for (i = 0; i < m; i++) printf("%d", n / m);
  } else {
    for (i = 0; i < m; i++) {
      if (i < m - (n % m))
        printf("%d", n / m);
      else
        printf("%d", (n / m) + 1);
    }
  }
}
