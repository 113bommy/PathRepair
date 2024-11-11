#include <cstdio>

int main()
{
  char a[4], b[4];
  scanf("%s %s", a, b);
  puts(a[0] == b[2] && a[1] == b[1] && a[2] == b[0] ? "YES" : "NO");
  return 0;
}
