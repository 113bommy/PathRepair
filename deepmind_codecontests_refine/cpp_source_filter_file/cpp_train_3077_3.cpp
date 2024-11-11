#include <bits/stdc++.h>
char str[10009];
unsigned int n, i, j, jp, k;
int main() {
  scanf("%u", &n);
  gets(str);
  gets(str);
  for (i = 0; str[i]; i += j) {
    jp = 0;
    j = 1;
    while (true) {
      while (str[i + j - 1] != '.' && str[i + j - 1] != '!' &&
             str[i + j - 1] != '?') {
        ++j;
      }
      if (n < j) {
        if (jp) {
          j = jp;
          break;
        } else {
          puts("Impossible");
          return 0;
        }
      }
      if (!str[i + j]) {
        break;
      }
      j += 2;
      jp = j;
    }
    ++k;
  }
  printf("%u", k);
}
