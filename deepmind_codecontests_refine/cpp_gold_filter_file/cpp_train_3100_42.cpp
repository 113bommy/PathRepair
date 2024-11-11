#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  if (n%1000) printf("%d\n", 1000 - n%1000);
  else puts("0");
}