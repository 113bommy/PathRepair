#include <bits/stdc++.h>
int main() {
  int a, b, i = 0, x;
  scanf("%d %d", &a, &b);
  x = (a * b);
  while (x >= 0) {
    x -= 2;
    i++;
  }
  printf("\n%d", i - 1);
  return 0;
}
