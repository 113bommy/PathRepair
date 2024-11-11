#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
int N, M, K, x, y, res;
char data[MAX][MAX][MAX];
bool seen[MAX][MAX][MAX];
void dfs(int x, int y, int z) {
  res++;
  seen[x][y][z] = true;
  for (int dx = (int)-1; dx <= (int)1; dx++)
    for (int dy = (int)-1; dy <= (int)1; dy++)
      for (int dz = (int)-1; dz <= (int)1; dz++)
        if (abs(dx) + abs(dy) + abs(dz) == 1) {
          int nx = x + dx, ny = y + dy, nz = z + dz;
          if (nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= K)
            continue;
          if (!seen[nx][ny][nz] && data[nx][ny][nz] == '.') dfs(nx, ny, nz);
        }
}
int main() {
  scanf("%d%d%d", &N, &M, &K);
  for (int i = 0; i < (int)N; i++)
    for (int j = 0; j < (int)M; j++) scanf("%s", data[i][j]);
  scanf("%d%d", &x, &y);
  dfs(0, x - 1, y - 1);
  printf("%d\n", res);
}
