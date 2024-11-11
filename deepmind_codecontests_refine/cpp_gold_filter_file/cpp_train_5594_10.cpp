#include <bits/stdc++.h>
int main() {
  char str[1000];
  int i, j;
  gets(str);
  for (i = 0; str[i] != '.'; i++) {
    if (str[i + 1] == '.') {
      j = i;
      if (str[j] != '9') {
        if (str[j + 2] < '5') {
          str[j + 1] = '\0';
          printf("%s", str);
          break;
        } else {
          str[j] += 1;
          str[j + 1] = '\0';
          printf("%s", str);
          break;
        }
      } else {
        printf("GOTO Vasilisa.");
        break;
      }
    }
  }
  return 0;
}
