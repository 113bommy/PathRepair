#include <stdio.h>

int main() {
  int H, A;
  scanf("%d %d", &H, &A);
  printf("%d", H / A + (H % A > 0));
  return 0;
}