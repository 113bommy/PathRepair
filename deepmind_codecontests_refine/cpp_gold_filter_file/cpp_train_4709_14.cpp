#include <bits/stdc++.h>
int main() {
  int i, len;
  char str[101];
  scanf("%s", str);
  len = strlen(str);
  if (len == 1) {
    if (islower(str[0]))
      putchar(toupper(str[0]));
    else
      putchar(tolower(str[0]));
    putchar('\n');
  } else {
    for (i = 1; i < len; i++)
      if (islower(str[i])) break;
    if (i == len) {
      if (islower(str[0]))
        putchar(toupper(str[0]));
      else
        putchar(tolower(str[0]));
      for (i = 1; i < len; i++) putchar(tolower(str[i]));
      putchar('\n');
    } else
      printf("%s\n", str);
  }
  return 0;
}
