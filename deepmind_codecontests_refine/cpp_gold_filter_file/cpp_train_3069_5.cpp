#include <bits/stdc++.h>
int main() {
  char s[10][10];
  int i, j, sumB = 0, sumW = 0;
  for (i = 0; i < 8; i++) {
    scanf("%s", s[i]);
  }
  for (i = 0; i < 8; i++) {
    for (j = 0; s[i][j] != '\0'; j++) {
      if (isupper(s[i][j]) > 0) {
        if (s[i][j] == 'Q') {
          sumW = sumW + 9;
        } else if (s[i][j] == 'R') {
          sumW = sumW + 5;
        } else if (s[i][j] == 'B') {
          sumW = sumW + 3;
        } else if (s[i][j] == 'N') {
          sumW = sumW + 3;
        } else if (s[i][j] == 'P') {
          sumW = sumW + 1;
        }
      } else if (islower(s[i][j]) > 0) {
        if (s[i][j] == 'q') {
          sumB = sumB + 9;
        } else if (s[i][j] == 'r') {
          sumB = sumB + 5;
        } else if (s[i][j] == 'b') {
          sumB = sumB + 3;
        } else if (s[i][j] == 'n') {
          sumB = sumB + 3;
        } else if (s[i][j] == 'p') {
          sumB = sumB + 1;
        }
      }
    }
  }
  if (sumB < sumW) {
    printf("White\n");
  } else if (sumB > sumW) {
    printf("Black\n");
  } else {
    printf("Draw\n");
  }
  return 0;
}
