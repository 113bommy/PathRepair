#include <bits/stdc++.h>
int main() {
  int k, a;
  scanf("%d", &k);
  if (k <= 9) {
    printf("%d", k);
  } else if (k >= 10 && k <= 189) {
    a = k - 10;
    a = a / 2;
    a = a + 10;
    if (k % 2 == 0)
      printf("%d", (a / 10));
    else
      printf("%d", (a % 10));
  } else if (k >= 190 && k <= 2889) {
    a = k - 190;
    a = a / 3;
    a = a + 100;
    if (((k - 190) % 3) == 0)
      printf("%d", a / 100);
    else if ((k - 190) % 3 == 2)
      printf("%d", a % 10);
    else
      printf("%d", (a % 100) / 10);
  } else {
    a = k - 2890;
    a = a / 4;
    a = a + 1000;
    if ((k - 2890) % 4 == 0)
      printf("%d", a / 1000);
    else if ((k - 2890) % 4 == 1)
      printf("%d", (a % 1000) / 100);
    else if ((k - 2890) % 4 == 2)
      printf("%d", (a % 100) / 10);
    else
      printf("%d", a % 10);
  }
}
