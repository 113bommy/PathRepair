#include <bits/stdc++.h>
int map[3][3];
int press[3][3];
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int main() {
  int i, j;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) map[i][j] = 1;
  }
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      scanf("%d", &press[i][j]);
      press[i][j] %= 2;
    }
  }
  int k;
  int finalx, finaly;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      map[i][j] ^= press[i][j];
      for (k = 0; k < 4; k++) {
        finalx = i + dx[k];
        finaly = j + dy[k];
        if (finalx >= 0 && finalx < 3 && finaly >= 0 && finaly < 3)
          map[finalx][finaly] ^= press[i][j];
      }
    }
  }
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) printf("%d ", map[i][j]);
    printf("\n");
  }
  return 0;
}
