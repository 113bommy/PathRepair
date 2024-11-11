#include <bits/stdc++.h>
int main() {
  int b = 0, w = 0;
  int i, j;
  char ch;
  for (i = 1; i <= 8; i++) {
    for (j = 1; j <= 8; j++) {
      scanf(" %c", &ch);
      if (ch == 'q') {
        b += 9;
      } else if (ch == 'r') {
        b += 5;
      } else if (ch == 'b' || ch == 'n') {
        b += 3;
      } else if (ch == 'p') {
        b += 1;
      } else if (ch == 'Q') {
        w += 9;
      } else if (ch == 'R') {
        w += 5;
      } else if (ch == 'B' || ch == 'N') {
        w += 3;
      } else if (ch == 'P') {
        w += 1;
      }
    }
  }
  if (b > w)
    printf("Black");
  else if (b < w)
    printf("White");
  else
    printf("Draw");
  return 0;
}
