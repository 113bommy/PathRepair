#include <cstdio>

int main()
{
  char s[4];
  scanf("%s", s);
  if (s[2])
  {
    printf("%c%c%c\n", s[2], s[1], s[0]);
  }
  else
  {
    puts(s);
  }
  return 0;
}
