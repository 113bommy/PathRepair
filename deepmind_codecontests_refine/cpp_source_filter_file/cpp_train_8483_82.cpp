#include <bits/stdc++.h>
int main() {
  int a, b, c = 0, d = 0;
  scanf("%d%d", &a, &b);
  if (a < b)
    printf("%d ", a);
  else
    printf("%d ", b);
  c = a - b;
  if (c < 2)
    printf("%d", 0);
  else if (c == 2)
    printf("%d", 1);
  else {
    d = c / 2;
    printf("%d", d);
  }
  return 0;
}
