#include <bits/stdc++.h>
int main() {
  int i = 1, q = 0, a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  while (i) {
    if (a >= 1 && b >= 2 && c >= 4) {
      a = a - 1;
      b = b - 1;
      c = c - 1;
      q++;
    } else
      break;
    i++;
  }
  if (q > 0)
    printf("%d", q * 7);
  else
    printf("0");
  return 0;
}
