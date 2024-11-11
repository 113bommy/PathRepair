#include <bits/stdc++.h>
using namespace std;
char str[100009];
int main(void) {
  int i;
  while (scanf("%s", str) == 1) {
    int len = strlen(str);
    for (i = 0; i < len; i++) {
      if (str[i] == '1') break;
    }
    if (i == len) {
      puts(str + 1);
      continue;
    }
    int index = i;
    for (i++; i < len; i++) {
      if (str[i] == '0') break;
    }
    if (i == len) {
      puts(str + 1);
      continue;
    }
    int index2 = i;
    for (i++; i < len; i++) {
      if (str[i] == '1') break;
    }
    if (i == len) {
      if (index == 0) {
        for (i = 0; i < len - 1; i++) printf("%c", str[i]);
        printf("\n");
      } else {
        puts(str + 1);
      }
      continue;
    }
    for (i = 0; i <= index2 - 1; i++) printf("%c", str[i]);
    for (i = index2 + 1; i < len; i++) printf("%c", str[i]);
    printf("\n");
  }
  return 0;
}
