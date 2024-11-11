#include <bits/stdc++.h>
int main() {
  int n, m, domino, c;
  scanf("%d%d", &n, &m);
  if ((m % 2) == 0 || (n % 2) == 0) {
    domino = m * n / 2;
  } else if ((n % 2) == 1 && (m % 2) == 1) {
    c = n * (m - 1) / 2;
    domino = c + (m - 1) / 2;
  }
  printf("%d", domino);
  return 0;
}
