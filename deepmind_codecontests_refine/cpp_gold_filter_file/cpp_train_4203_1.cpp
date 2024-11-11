#include <bits/stdc++.h>
using namespace std;
char Board[555][555];
int Status[10][555][555];
int main(void) {
  int n = 0;
  int m = 0;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", Board[i]);
    for (int j = 0; j < m; j++) {
      if (Board[i][j] == '.')
        Board[i][j] = 0;
      else
        Board[i][j] = 1;
    }
  }
  int limit = min(n, m);
  for (int ii = 2; ii <= limit; ii *= 2) {
    int i = 1;
    int x = ii;
    while (x > 1) {
      i++;
      x /= 2;
    }
    for (int x = 0; x + ii <= n; x++) {
      for (int y = 0; y + ii <= m; y++) {
        if (i == 2) {
          Status[i][x][y] = Board[x][y] + (Board[x][y + 1] << 1) +
                            (Board[x + 1][y] << 2) + (Board[x + 1][y + 1] << 3);
        } else {
          int p = ii / 2;
          Status[i][x][y] = -1;
          int shape[4] = {0};
          shape[0] = Status[i - 1][x][y];
          shape[2] = Status[i - 1][x + p][y];
          shape[1] = Status[i - 1][x][y + p];
          shape[3] = Status[i - 1][x + p][y + p];
          for (int c = 0; c < 4; c++) {
            if (shape[c] == -1) break;
            bool fail = false;
            for (int j = 0; j < 4; j++) {
              if (((shape[c] >> j) & 1) == 0) {
                if (shape[j] != shape[c]) {
                  fail = true;
                  break;
                }
              } else if (shape[j] != 0xF) {
                fail = true;
                break;
              }
            }
            if (!fail) {
              Status[i][x][y] = shape[c];
              break;
            }
          }
        }
      }
    }
  }
  int ans = 0;
  for (int ii = 4; ii <= limit; ii *= 2) {
    int i = 1;
    int x = ii;
    while (x > 1) {
      i++;
      x /= 2;
    }
    for (int x = 0; x + ii <= n; x++) {
      for (int y = 0; y + ii <= m; y++) {
        if (Status[i][x][y] != -1) ans++;
      }
    }
  }
  printf("%d\n", ans);
  while (getchar() != EOF)
    ;
  return 0;
}
