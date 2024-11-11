#include <bits/stdc++.h>
int main() {
  int o, l, c = 0;
  char str[100];
  gets(str);
  l = strlen(str);
  for (o = 0; o <= l / 2; o++) {
    if (str[o] != str[l - o - 1]) {
      c = c + 1;
    }
  }
  if (l % 2 == 0 && c == 0) {
    printf("NO");
  } else {
    if (c < 2) {
      printf("YES");
    } else {
      printf("NO");
    }
  }
  return 0;
}
