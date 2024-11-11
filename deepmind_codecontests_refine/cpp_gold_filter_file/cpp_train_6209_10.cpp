#include <bits/stdc++.h>
int main() {
  char s[11], t[11];
  int p = 0, i = 0;
  scanf("%s %s", &s, &t);
  while (s[i] != 0) {
    if (i == 0) {
      printf("%c", s[i]);
    } else if (s[i] < t[0]) {
      printf("%c", s[i]);
    } else {
      break;
    }
    i = i + 1;
  }
  printf("%c", t[0]);
}
