#include <bits/stdc++.h>
int main() {
  char str[150];
  int word = 0, seq = 0;
  bool ok = true;
  scanf("%[^\n]", str);
  int leng = strlen(str);
  for (int i = 0; i < leng; i++) {
    if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') ||
        (str[i] >= '0' && str[i] <= '9') || str[i] == '_') {
      word = 1;
      continue;
    }
    if (str[i] == '@') {
      if (word == 0) {
        ok = false;
      }
      if (seq > 0) {
        ok = false;
      } else {
        seq = 1;
      }
      word = 0;
      continue;
    }
    if (str[i] == '.') {
      if (word == 0) {
        ok = false;
      }
      if (seq > 2 || seq == 0) {
        ok = false;
      } else {
        seq = 2;
      }
      word = 0;
      continue;
    }
    if (str[i] == '/') {
      if (word == 0) {
        ok = false;
      }
      if (seq > 2 || seq == 0) {
        ok = false;
      } else {
        seq = 3;
      }
      word = 0;
      continue;
    } else {
      ok = false;
    }
  }
  (ok && word && seq >= 1) ? puts("YES") : puts("NO");
  return 0;
}
