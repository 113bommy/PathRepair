#include <bits/stdc++.h>
int main() {
  int n, c, i;
  scanf("%d", &n);
  for (i = (n / 2); i >= 1; i--) {
    c = n / i;
    if (c * i == n) {
      break;
    }
  }
  n = (c + i - abs(c - i)) / 2;
  i = (c + i + abs(c - i)) / 2;
  printf("%d %d", n, i);
  return 0;
}
