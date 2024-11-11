#include <bits/stdc++.h>
int main() {
  char ch[200];
  int i, j, k;
  bool f;
  while (gets(ch)) {
    f = true;
    for (i = 0; ch[i] && ch[i] != '@'; i++)
      if (!isalnum(ch[i]) && ch[i] != '_') {
        f = false;
        break;
      }
    if (ch[i] != '@' || i > 16) f = false;
    if (f) {
      if (f) {
        i++;
        for (k = 0, j = 0; ch[i] && ch[i] != '/'; i++, k++, j++) {
          if (!isalnum(ch[i]) && ch[i] != '_' && ch[i] != '.') {
            f = false;
            break;
          }
          if (ch[i] == '.') {
            if (k > 16 || !k) {
              f = false;
              break;
            }
            k = -1;
          }
        }
        if (!j || j > 32) f = false;
        if (i && ch[i - 1] == '.') f = false;
        if (f && ch[i] == '/') {
          i++;
          for (j = 0; ch[i]; i++, j++)
            if (!isalnum(ch[i]) && ch[i] != '_') {
              f = false;
              break;
            }
          if (j > 16 || !j) f = false;
        }
      }
    }
    if (f)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
