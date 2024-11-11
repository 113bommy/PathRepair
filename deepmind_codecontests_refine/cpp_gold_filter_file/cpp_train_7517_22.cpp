#include <bits/stdc++.h>
char map[2][9][9];
int now[2][9][9], dx[] = {-1, -1, 0, 1, 1, 1, 0, -1, 0},
                  dy[] = {0, 1, 1, 1, 0, -1, -1, -1, 0};
int main() {
  for (int i = 0; i < 8; i++) scanf("%s", map[0][i]);
  bool a = 0;
  now[a][7][0] = 1;
  int sta = 0;
  while (sta == 0) {
    memset(now[!a], 0, sizeof(now[!a]));
    memset(map[!a], 0, sizeof(map[!a]));
    for (int i = 1; i < 8; i++)
      for (int j = 0; j < 8; j++)
        if (map[a][i - 1][j] == 'S') map[!a][i][j] = 'S';
    for (int i = 0; i < 8; i++)
      for (int j = 0; j < 8; j++)
        if (now[a][i][j])
          for (int k = 0; k < 9; k++) {
            int x = i + dx[k], y = j + dy[k];
            if (x < 0 || x > 7 || y < 0 || y > 7 || map[a][x][y] == 'S')
              continue;
            now[!a][x][y] = 1;
          }
    if (now[!a][0][7]) {
      sta = 1;
      continue;
    }
    bool alive = 0;
    for (int i = 0; i < 8; i++)
      for (int j = 0; j < 8; j++)
        if (map[!a][i][j] == 'S')
          now[!a][i][j] = 0;
        else if (now[!a][i][j] == 1)
          alive = 1;
    if (alive == 0) sta = 2;
    a = !a;
  }
  puts(sta == 1 ? "WIN" : "LOSE");
}
