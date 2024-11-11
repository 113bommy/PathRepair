#include <cstdio>

int main()
{
  int a, b;
  scanf("%d %d", &a, &b);
  puts(a % 3 == 0 || b % 3 == 0 || (a + b) % == 0 ? "Possible" : "Impossible");
  return 0;
}