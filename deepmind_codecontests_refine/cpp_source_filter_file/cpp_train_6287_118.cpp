#include <bits/stdc++.h>
using namespace std;
const int DIR_NUM = 8;
const int SIZEH = 1610, SIZEC = 100010;
int H, W;
int C;
int board[SIZEH][SIZEH];
int core[SIZEH][SIZEH];
int sun[SIZEH][SIZEH];
int raynum[SIZEC] = {0};
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1}, dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
void print(int s[SIZEH][SIZEH]) {
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (s[i][j] == -1)
        printf("-");
      else
        printf("%d", s[i][j]);
    }
    printf("\n");
  }
}
int nowtot = 0;
int DFS_ray(int x, int y) {
  sun[x][y] = -1;
  nowtot++;
  int ans = 0;
  for (int d = 0; d < DIR_NUM; d++) {
    int x1 = x + dx[d], y1 = y + dy[d];
    if (0 <= x1 && x1 < H && 0 <= y1 && y1 < W) {
      if (sun[x1][y1] > 0)
        ans = sun[x1][y1];
      else if (sun[x1][y1] == 0) {
        int tp = DFS_ray(x1, y1);
        if (tp) ans = tp;
      }
    }
  }
  return ans;
}
void Find_Ray(void) {
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (sun[i][j] == 0) {
        nowtot = 0;
        int t = DFS_ray(i, j);
        if (nowtot >= 5) raynum[t]++;
      }
    }
  }
}
void DFS_core(int x, int y, int col) {
  core[x][y] = col;
  for (int d = 0; d < DIR_NUM; d++) {
    int x1 = x + dx[d], y1 = y + dy[d];
    if (0 <= x1 && x1 < H && 0 <= y1 && y1 < W) {
      if (core[x1][y1] == 0) DFS_core(x1, y1, col);
    }
  }
}
void Find_Core(void) {
  int timer = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (core[i][j] == 0) {
        DFS_core(i, j, ++timer);
      }
    }
  }
  C = timer;
}
void Background_Spread(int f[SIZEH][SIZEH], int g[SIZEH][SIZEH]) {
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      g[i][j] = f[i][j];
      for (int d = 0; d < DIR_NUM; d++) {
        int i1 = i + dx[d], j1 = j + dy[d];
        if (0 <= i1 && i1 < H && 0 <= j1 && j1 < W) {
          if (f[i1][j1] == -1) g[i][j] = -1;
        }
      }
    }
  }
}
void Multiple_Background_Spread(int f[SIZEH][SIZEH], int tim) {
  static int g[SIZEH][SIZEH];
  for (int i = 1; i <= tim; i++) {
    Background_Spread(f, g);
    memcpy(f, g, sizeof(g));
  }
}
void Sun_Recover(int f[SIZEH][SIZEH], int g[SIZEH][SIZEH]) {
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      g[i][j] = max(f[i][j], board[i][j]);
      for (int d = 0; d < DIR_NUM; d++) {
        int i1 = i + dx[d], j1 = j + dy[d];
        if (0 <= i1 && i1 < H && 0 <= j1 && j1 < W) {
          if (board[i][j] >= 0 && f[i1][j1] > 0) g[i][j] = f[i1][j1];
        }
      }
    }
  }
}
void Multiple_Sun_Recover(int f[SIZEH][SIZEH], int tim) {
  static int g[SIZEH][SIZEH];
  for (int i = 1; i <= tim; i++) {
    Sun_Recover(f, g);
    memcpy(f, g, sizeof(g));
  }
}
void Work(void) {
  int width = 3;
  memcpy(core, board, sizeof(core));
  Multiple_Background_Spread(core, width);
  Find_Core();
  memcpy(sun, core, sizeof(sun));
  Multiple_Sun_Recover(sun, width);
  Find_Ray();
  sort(raynum + 1, raynum + 1 + C);
  printf("%d\n", C);
  for (int i = 1; i <= C; i++) printf("%d ", raynum[i]);
  printf("\n");
}
void Read(void) {
  scanf("%d%d", &H, &W);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      scanf("%d", &board[i][j]);
      board[i][j]--;
    }
  }
}
int main() {
  Read();
  Work();
  return 0;
}
