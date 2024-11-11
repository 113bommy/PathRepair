#include <bits/stdc++.h>
int main() {
  char s[100010], c;
  char as[100010];
  int i, n, top;
  while (~scanf("%s", s)) {
    n = strlen(s);
    top = 1;
    c = s[n - 1];
    as[top++] = c;
    for (i = n - 2; i >= 0; i--) {
      if (s[i] == c) as[top++] = c;
      if (s[i] > c) {
        c = s[i];
        as[top++] = c;
      }
    }
    while (top--) putchar(as[top]);
    putchar('\n');
  }
  return 0;
}
