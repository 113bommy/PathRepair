#include <bits/stdc++.h>
using namespace std;
char u[10][10], b[10][10];
int N, M, best;
bool ok(int x, int y) {
  return x >= 0 && y >= 0 && x < N && y < M && u[x][y] == '.';
}
int D[4][5][2] = {{{0, 0}, {1, 0}, {2, 0}, {0, 1}, {0, -1}},
                  {{0, 0}, {-1, 0}, {-2, 0}, {0, 1}, {0, -1}},
                  {{0, 0}, {0, 1}, {0, 2}, {1, 0}, {-1, 0}},
                  {{0, 0}, {0, -1}, {0, -2}, {1, 0}, {-1, 0}}};
void dfs(int depth) {
  if (depth > best) {
    best = depth;
    for (int i = 0; i < N; i++)
      for (int j = 0; j < M + 1; j++) b[i][j] = u[i][j];
  }
  bool found = false;
  int cntfound = 0;
  for (int x = 0; x < N; x++) {
    for (int y = 0; y < M; y++) {
      if (found) cntfound++;
      if (cntfound > 1) return;
      for (int S = 0; S < 4; S++) {
        bool uok = true;
        for (int d = 0; d < 5; d++)
          if (!ok(x + D[S][d][0], y + D[S][d][1])) uok = false;
        if (!uok) continue;
        found = true;
        for (int d = 0; d < 5; d++)
          u[x + D[S][d][0]][y + D[S][d][1]] = 'A' + depth;
        dfs(depth + 1);
        for (int d = 0; d < 5; d++) u[x + D[S][d][0]][y + D[S][d][1]] = '.';
      }
    }
  }
}
int main(int argc, char *argv[]) {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) u[i][j] = '.';
  for (int i = 0; i < N; i++) u[i][M] = '\0';
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M + 1; j++) b[i][j] = u[i][j];
  best = 0;
  dfs(0);
  printf("%d\n", best);
  for (int i = 0; i < N; i++) printf("%s\n", b[i]);
  return 0;
}
