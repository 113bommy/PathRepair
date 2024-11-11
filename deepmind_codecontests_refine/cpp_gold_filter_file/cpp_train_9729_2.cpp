#include <bits/stdc++.h>
int main() {
  int n, m, a = 0;
  scanf("%d %d", &n, &m);
  while (n > 0) {
    a = a + 1;
    if (a % m == 0) {
      n = n;
    } else {
      n = n - 1;
    }
  }
  printf("%d", a);
}
