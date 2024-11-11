#include <bits/stdc++.h>
int main(void) {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  int toplam = 0;
  int j = 0;
  while (j < c) {
    toplam = toplam + 2 * a;
    toplam = toplam + ((b - 2) * 2);
    a = a - 4;
    b = b - 4;
    j++;
  }
  printf("%d", toplam);
  return 0;
}
