#include <bits/stdc++.h>
int main() {
  char str[2];
  scanf("%s", str);
  int km;
  if (str[0] == 'a' || str[0] == 'h' || str[1] == '1' || str[1] == '8')
    km = 5;
  else
    km = 8;
  if (strcmp(str, "a8") == 0 || strcmp(str, "h8") == 0 ||
      strcmp(str, "a1") == 0 || strcmp(str, "h1") == 0)
    km -= 2;
  printf("%d", km);
  return 0;
}
