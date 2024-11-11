#include <bits/stdc++.h>
int main() {
  int a;
  scanf("%d", &a);
  for (int i = a + 1; i <= 9000; i++) {
    int a = i % 10, b = i % 100 / 10, c = i % 1000 / 100, d = i / 1000;
    if ((a != b && a != c && a != d) && (b != c && b != d) && (c != d)) {
      printf("%d\n", i);
      break;
    }
  }
  return 0;
}
