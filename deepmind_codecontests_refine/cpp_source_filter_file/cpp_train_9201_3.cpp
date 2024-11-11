#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int cnt[2][N][N];
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
int main() {
  memset(cnt, 0, sizeof(cnt));
  int n, t;
  scanf("%d%d", &n, &t);
  int now = 0, flag;
  cnt[1][N / 2][N / 2] = n;
  do {
    flag = 0;
    for (int i = 1; i < N; i++)
      for (int j = 1; j < N; j++) {
        if (cnt[1 - now][i][j] >= 4) {
          flag = 1;
          int nx, ny;
          for (int k = 0; k < 4; k++) {
            nx = i + dir[k][0];
            ny = j + dir[k][1];
            cnt[now][nx][ny] += cnt[1 - now][i][j] / 4;
          }
          cnt[now][i][j] += cnt[1 - now][i][j] % 4;
        } else
          cnt[now][i][j] += cnt[1 - now][i][j];
      }
    now = 1 - now;
    memset(cnt[now], 0, sizeof(cnt[now]));
  } while (flag);
  int x, y;
  for (int i = 1; i <= t; i++) {
    scanf("%d%d", &x, &y);
    if (x <= -N / 2 || x >= N / 2 || y <= -N / 2 || y >= N / 2)
      printf("0\n");
    else
      printf("%d\n", cnt[1 - now][x + N / 2][y + N / 2]);
  }
  return 0;
}
