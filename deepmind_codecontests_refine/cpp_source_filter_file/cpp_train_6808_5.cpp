#include <bits/stdc++.h>
int main() {
  char code[100], num[100];
  gets(code);
  int i, j;
  for (i = 0, j = 0; i < strlen(code); i++) {
    if (code[i] == '.') {
      num[j] = '0';
      j++;
    } else if (code[i] == '-') {
      if (code[i + 1] == '-') {
        num[j] = '2';
        j++;
        i++;
      } else if (code[i + 1] == '.') {
        num[j] = '1';
        j++;
        i++;
      }
    }
  }
  num[j] = '\0';
  printf("%s", num);
  return 0;
}
