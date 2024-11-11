#include <bits/stdc++.h>
int main() {
  int n, m, a = 0;
  scanf("%d %d", &n, &m);
  while (n > 0) {
    a = a + 1;
    if (a % m == 0) {
      n = n - m + 1;
    } else {
      n = n - m;
    }
  }
  printf("%d", a);
}
