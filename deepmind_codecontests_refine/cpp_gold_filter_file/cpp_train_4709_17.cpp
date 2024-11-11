#include <bits/stdc++.h>
int main() {
  char i, str[101], str2[101];
  int count = 0;
  scanf("%s", str);
  int len = strlen(str);
  for (i = 0; i < len; i++) {
    str2[i] = str[i];
  }
  str2[i] = '\0';
  if (str[0] >= 97 && str[0] <= 122) {
    str[0] = str[0] - 32;
    for (i = 1; i < len; i++) {
      if ((str[i] >= 65 && str[i] <= 90)) {
        str[i] = str[i] + 32;
        count++;
      }
    }
    if (count == (len - 1)) {
      printf("%s\n", str);
      return 0;
    }
  } else if (str[0] >= 65 && str[0] <= 90) {
    for (i = 0; i < len; i++) {
      if ((str[i] >= 65 && str[i] <= 90)) {
        str[i] = str[i] + 32;
        count++;
      }
    }
    if (count == len) {
      printf("%s\n", str);
      return 0;
    }
  }
  printf("%s\n", str2);
  return 0;
}
