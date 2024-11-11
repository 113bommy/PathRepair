#include <bits/stdc++.h>
int main() {
  int i, t;
  printf("301\n");
  printf("0 100000\n");
  t = 100000;
  for (i = 300; i > 1; --i) {
    printf("%d %d\n", i + t, i);
    t += i * 2;
  }
  printf("200000 100000\n");
  return 0;
}
