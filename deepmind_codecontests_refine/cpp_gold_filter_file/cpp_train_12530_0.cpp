#include <bits/stdc++.h>
int main() {
  int i, t;
  printf("302\n");
  printf("0 500000\n");
  t = 500000;
  for (i = 300; i > 0; --i) {
    printf("%d %d\n", i + t, i);
    t += i * 2;
  }
  printf("600000 500000\n");
  return 0;
}
