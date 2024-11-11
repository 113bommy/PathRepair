#include <stdio.h>

int main(void) {
  int x, p;
  scanf("%d%d", &x, &p);
  printf("%.12f", (double)((x + 1) / 2) * 100.0 / (double)p);
  return 0;
}
