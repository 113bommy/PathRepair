#include <bits/stdc++.h>
using namespace std;
int n;
bool G[55][55], f = false, flag = true;
int nxt[2][2] = {{0, 1}, {1, 0}}, p[4][2];
bool qry(int x1, int y1, int x2, int y2) {
  printf("? %d %d %d %d\n", x1, y1, x2, y2), cout.flush();
  bool ret;
  cin >> ret;
  return ret;
}
void chk() {
  if (G[p[0][0]][p[0][1]] != G[p[2][0]][p[2][1]])
    if (G[p[1][0]][p[1][1]] != G[p[3][0]][p[3][1]]) {
      f = true;
      bool res = qry(p[0][0], p[0][1], p[3][0], p[3][1]);
      if (res && G[p[0][0]][p[0][1]] != G[p[3][0]][p[3][1]]) flag = false;
      if (!res && G[p[0][0]][p[0][1]] == G[p[3][0]][p[3][1]]) flag = false;
    }
  if (G[p[0][0]][p[0][1]] == G[p[2][0]][p[2][1]])
    if (G[p[1][0]][p[1][1]] == G[p[3][0]][p[3][1]]) {
      f = true;
      bool res = qry(p[0][0], p[0][1], p[3][0], p[3][1]);
      if (res && G[p[0][0]][p[0][1]] != G[p[3][0]][p[3][1]]) flag = false;
      if (!res && G[p[0][0]][p[0][1]] == G[p[3][0]][p[3][1]]) flag = false;
    }
}
void DFS(int x, int y, int stp) {
  p[stp][0] = x, p[stp][1] = y;
  if (stp == 3) {
    chk();
    return;
  }
  for (int i = 0; !f && i < 2; i++) {
    int xx = x + nxt[i][0];
    if (xx > n) continue;
    int yy = y + nxt[i][1];
    if (yy > n) continue;
    DFS(xx, yy, stp + 1);
  }
}
int main() {
  cin >> n, G[1][1] = G[1][2] = 1, G[n][n] = 0;
  for (int i = 3; i <= n; i++) G[1][i] = G[1][i - 2] ^ (!qry(1, i - 2, 1, i));
  for (int i = 2; i <= n; i++) G[2][i] = G[1][i - 1] ^ (!qry(1, i - 1, 2, i));
  G[2][1] = G[2][3] ^ (!qry(2, 1, 2, 3));
  for (int i = 3; i < n; i++)
    for (int j = 1; j <= n; j++) G[i][j] = G[i - 2][j] ^ (!qry(i - 2, j, i, j));
  for (int i = 1; i < n; i++) G[n][i] = G[n - 2][i] ^ (!qry(n - 2, i, n, i));
  for (int i = 1; !f && i <= n; i++)
    for (int j = 1; !f && j <= n; j++) DFS(i, j, 0);
  if (!flag)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        if ((i + j) & 1) G[i][j] ^= 1;
  puts("!");
  for (int i = 1; i <= n; i++, puts(""))
    for (int j = 1; j <= n; j++) cout << G[i][j] << ' ';
  return 0;
}
