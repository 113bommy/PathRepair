#include <bits/stdc++.h>
char dizi[100][100];
int main() {
  int i, j, white = 0, black = 0;
  for (i = 1; i <= 8; i++) {
    for (j = 1; j <= 8; j++) {
      scanf(" %c", &dizi[i][j]);
    }
  }
  for (i = 1; i <= 8; i++) {
    for (j = 1; j <= 8; j++) {
      if (dizi[i][j] == 'N') {
        white += 3;
      } else if (dizi[i][j] == 'R') {
        white += 5;
      } else if (dizi[i][j] == 'Q') {
        white += 9;
      } else if (dizi[i][j] == 'B') {
        white += 3;
      } else if (dizi[i][j] == 'P') {
        white++;
      }
      if (dizi[i][j] == 'n') {
        black += 3;
      } else if (dizi[i][j] == 'r') {
        black += 5;
      } else if (dizi[i][j] == 'q') {
        black += 9;
      } else if (dizi[i][j] == 'b') {
        black += 3;
      } else if (dizi[i][j] == 'p') {
        black++;
      }
    }
  }
  if (white > black) {
    printf("White\n");
  } else if (black > white) {
    printf("Black");
  } else if (black == white) {
    printf("Draw");
  }
}
