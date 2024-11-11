#include <bits/stdc++.h>
int main() {
  int a, i, j, s = 0;
  scanf("%d", &a);
  for (i = 1; i < a; i++) {
    s = s + (2 * i) - 1;
  }
  printf("%d", (2 * s) + (2 * i) - 1);
  return 0;
}
