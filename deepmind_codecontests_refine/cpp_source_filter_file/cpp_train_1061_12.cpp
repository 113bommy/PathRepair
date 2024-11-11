#include <bits/stdc++.h>
int main() {
  int n, m, l;
  while (~scanf("%d", &n)) {
    m = n / 36;
    l = (n - 36 * m) / 3;
    if ((n - 36 * m) % 3 == 2) l = l + 1;
    if (l % 12 == 0 && l != 0) {
      m = l / 12;
      l = 0;
    }
    printf("%d %d\n", m, l);
  }
}
