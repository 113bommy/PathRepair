#include <bits/stdc++.h>
int main(void) {
  int i, w;
  char s[3][10];
  char res[4] = {'F', 'M', 'S', '?'};
  while (scanf(" %s %s %s", s[0], s[1], s[2]) != EOF) {
    w = 3;
    for (i = 0; i < 2; i++) {
      if (s[i][0] == 'r' && s[(i + 1) % 3][0] == 's' &&
          s[(i + 2) % 3][0] == 's')
        w = i;
      if (s[i][0] == 's' && s[(i + 1) % 3][0] == 'p' &&
          s[(i + 2) % 3][0] == 'p')
        w = i;
      if (s[i][0] == 'p' && s[(i + 1) % 3][0] == 'r' &&
          s[(i + 2) % 3][0] == 'r')
        w = i;
    }
    printf("%c\n", res[w]);
  }
  return 0;
}
