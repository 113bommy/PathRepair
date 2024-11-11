#include <bits/stdc++.h>
int main() {
  int n, m;
  while (scanf("%d %d", &n, &m) == 2) {
    if (m == 0) {
      printf("1\n");
    } else if (n == m) {
      printf("0\n");
    } else {
      if (n / 2 > m) {
        printf("%d\n", m);
      } else {
        printf("%d\n", n - m);
      }
    }
  }
}
