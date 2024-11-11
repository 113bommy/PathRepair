#include <bits/stdc++.h>
int a, b, c;
int main() {
  while (scanf("%d", &a) == 1) {
    c = a % 3 + 1;
    if (a == 3) c = 0;
    printf("%d\n", c);
  }
  return 0;
}
