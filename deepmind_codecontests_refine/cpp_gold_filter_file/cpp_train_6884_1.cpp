#include <bits/stdc++.h>
int main() {
  int flag1 = 0, flag2 = 0, i, j, len1, len2;
  char str[500010] = {0};
  scanf("%s", str);
  len1 = strlen(str);
  len2 = len1;
  int x1 = -1, x2 = -1, x3 = -1, x4 = -1;
  for (i = 0; i < len1; i++) {
    if (flag1 == 0 && flag2 == 0 && str[i] != '[')
      len2--;
    else if (flag1 == 0 && flag2 == 0 && str[i] == '[') {
      flag1 = 1;
      x1 = i;
    } else if (flag1 == 1 && flag2 == 0 && str[i] != ':')
      len2--;
    else if (flag1 == 1 && flag2 == 0 && str[i] == ':') {
      x2 = i;
      break;
    }
  }
  flag1 = 0, flag2 = 0;
  for (i = len1 - 1; i >= 0; i--) {
    if (flag1 == 0 && flag2 == 0 && str[i] != ']')
      len2--;
    else if (flag1 == 0 && flag2 == 0 && str[i] == ']') {
      flag1 = 1;
      x3 = i;
    } else if (flag1 == 1 && flag2 == 0 && str[i] != ':')
      len2--;
    else if (flag1 == 1 && flag2 == 0 && str[i] == ':') {
      x4 = i;
      break;
    }
  }
  if (x2 >= x4 || x1 > x3 || x1 == -1 || x2 == -1 || x3 == -1 || x4 == -1)
    printf("-1");
  else {
    for (i = x2 + 1; i < x4; i++)
      if (str[i] != '|') len2--;
    printf("%d", len2);
  }
  return 0;
}
