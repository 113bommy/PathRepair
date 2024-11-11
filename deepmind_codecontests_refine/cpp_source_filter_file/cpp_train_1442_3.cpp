#include <stdio.h>

int main(void) {
  int a, b, c;
  scanf("%i %i %i", &a, &b, &c);
  puts((a*100+b*10+c) % 4 == 0 ? "YES" : "NO");
  return 0
}