#include <bits/stdc++.h>
int main() {
  char temp;
  bool flag = false;
  bool space = false;
  bool mark = false;
  while (scanf("%c", &temp) != EOF) {
    if (flag) {
      if (temp == ' ') {
        space = true;
        continue;
      }
      if (temp == ',' || temp == '.' || temp == '!' || temp == '?') {
        space = false;
        printf("%c ", temp);
        mark = true;
      } else {
        if (space && !mark)
          printf(" %c", temp);
        else
          printf("%c", temp);
        space = false;
        mark = false;
      }
    } else {
      printf("%c", temp);
      flag = true;
    }
  }
  return 0;
}
