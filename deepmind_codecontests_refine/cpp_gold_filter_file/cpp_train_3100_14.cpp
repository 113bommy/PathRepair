#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  (n%1000)? printf("%d\n", 1000 - n%1000) : puts("0");
}