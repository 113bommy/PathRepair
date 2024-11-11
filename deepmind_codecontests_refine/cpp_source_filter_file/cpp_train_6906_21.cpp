#include <bits/stdc++.h>
using namespace std;
char str[200];
int main() {
  bool end = false, amp = false, nl = true;
  char ch;
  int cnt = 0;
  while (!end) {
    cnt = 0;
    while (true) {
      if (EOF == scanf("%c", &ch)) {
        end = true;
        break;
      } else {
        str[cnt++] = ch;
      }
      if ('\n' == ch) {
        break;
      }
    }
    if (0 == cnt) break;
    for (int i = 0; i < cnt; i++) {
      if ('#' == str[i]) {
        amp = true;
        break;
      } else if (' ' != str[i]) {
        amp = false;
        break;
      }
    }
    if (amp) {
      if (!nl) {
        printf("\n");
      }
      str[cnt] = '\0';
      printf("%s", str);
      nl = ('\n' == str[cnt - 1]);
    } else {
      for (int i = 0; i < cnt; i++) {
        if (' ' != str[i] && '\n' != str[i]) {
          printf("%c", str[i]);
        }
      }
      nl = false;
    }
  }
  if (!nl) {
    printf("\n");
  }
  return 0;
}
