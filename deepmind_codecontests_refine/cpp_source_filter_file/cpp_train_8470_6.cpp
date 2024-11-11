#include <bits/stdc++.h>
int beauty(int x) {
  int a, b, c, d;
  a = x % 10;
  x /= 10;
  b = x % 10;
  x /= 10;
  c = x % 10;
  x /= 10;
  d = x % 10;
  if (a != b && a != c && a != d && b != c && b != d && c != d)
    return 1;
  else
    return 0;
}
int main() {
  int n;
  scanf("%d", &n);
  n++;
  while (n <= 9000) {
    if (beauty(n) == 1)
      break;
    else
      n++;
  }
  printf("%d", n);
  return 0;
}
