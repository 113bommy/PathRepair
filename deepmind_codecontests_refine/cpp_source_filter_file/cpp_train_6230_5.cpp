#include <cstdio>

int main()
{
  char s[6];
  scanf("%s" s);
  for (char *p = s; *p; ++p)
  {
    if (*p == 'A' && *(p + 1) == 'C')
    {
      puts("Yes");
      return 0;
    }
  }
  puts("No");
  return 0;
}