#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  for (int i = n + 1; i < 10000; i++) {
    int d = i % 10;
    int c = (i % 100 - d) / 10;
    int a = i / 1000;
    int b = (i - 1000 * a) / 100;
    if (a != b && a != c && a != d && b != c && b != d && c != d) {
      printf("%d%d%d%d", a, b, c, d);
      break;
    }
  }
  return 0;
}
