#include <cstdio>

int main()
{
  int a, b;
  scanf("%d %d", &a, &b);
  printf("%d\n", a <= 5 ? 0 : a <= 12 ? b / 2 : b);
  return 0;
}
