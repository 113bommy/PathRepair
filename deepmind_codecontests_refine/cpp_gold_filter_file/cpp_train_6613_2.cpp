#include <bits/stdc++.h>
using namespace std;
int memo[1 << 19];
int lf[6] = {-1, 1, 1, 1, 2, 3};
int rt[6] = {-1, 3, 4, 5, 5, 5};
int dx[] = {1, 1, 0};
int dy[] = {0, 1, 1};
char G[7][7];
int dfs() {
  int state = 0;
  for (int i = 1; i <= 5; i++)
    for (int j = lf[i]; j <= rt[i]; j++) {
      state <<= 1;
      state |= (G[i][j] == 'O');
    }
  int &ret = memo[state];
  if (ret != -1) return ret;
  ret = 0;
  for (int i = 1; i <= 5; i++)
    for (int j = lf[i]; j <= rt[i]; j++)
      if (G[i][j] == 'O')
        for (int d = 0; d < 3; d++) {
          int x = i, y = j;
          while (G[x][y] == 'O') {
            G[x][y] = 'X';
            if (!dfs()) ret = 1;
            x += dx[d], y += dy[d];
          }
          while (x != i || y != j) {
            x -= dx[d];
            y -= dy[d];
            G[x][y] = 'O';
          }
        }
  return ret;
}
int main() {
  memset(memo, -1, sizeof(memo));
  for (int i = 1; i <= 5; i++)
    for (int j = lf[i]; j <= rt[i]; j++) cin >> G[i][j];
  if (dfs())
    cout << "Karlsson" << endl;
  else
    cout << "Lillebror" << endl;
  return 0;
}
