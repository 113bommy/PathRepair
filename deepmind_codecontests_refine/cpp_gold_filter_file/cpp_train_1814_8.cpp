#include <bits/stdc++.h>
using namespace std;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int n, m, d, ans = -99999999;
int f[25][25][1 << 15 | 5];
int sum[1 << 15 | 5];
char a[25][25];
int val[25], X[25], Y[25];
struct node {
  int x, y, S;
};
int inq[25][25][1 << 15 | 5];
inline int get(int x, int y, int xx, int yy, int S) {
  for (int i = 0; i < d; i++)
    if (((x == X[i] && xx > X[i]) || (x > X[i] && xx <= X[i])) && yy > Y[i])
      S ^= 1 << i;
  return S;
}
inline void solve(int p, int q) {
  static queue<node> Q;
  while (!Q.empty()) Q.pop();
  Q.push((node){p, q, 0});
  memset(f, 0x3f, sizeof(f));
  f[p][q][0] = 0;
  inq[p][q][0] = 1;
  while (!Q.empty()) {
    node now = Q.front();
    Q.pop();
    int x = now.x, y = now.y, s = now.S;
    inq[x][y][s] = 0;
    for (int i = 0; i < 4; i++) {
      int X = x + dx[i], Y = y + dy[i];
      if (a[X][Y] != '.') continue;
      int S = i < 2 ? get(x, y, X, Y, s) : s;
      if (f[X][Y][S] > f[x][y][s] + 1) {
        f[X][Y][S] = f[x][y][s] + 1;
        if (!inq[X][Y][S]) {
          inq[X][Y][S] = 1;
          Q.push((node){X, Y, S});
        }
      }
    }
  }
  for (int i = 0; i < (1 << d); i++) ans = max(ans, sum[i] - f[p][q][i]);
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%s", a[i] + 1);
  for (int i = 0; i <= n + 1; i++) a[i][0] = a[i][m + 1] = '#';
  for (int i = 0; i <= m + 1; i++) a[0][i] = a[n + 1][i] = '#';
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if ('1' <= a[i][j] && a[i][j] <= '9') {
        X[a[i][j] - '1'] = i;
        Y[a[i][j] - '1'] = j;
        d = max(d, a[i][j] - '0');
      }
  for (int i = 0; i < d; i++) scanf("%d", val + i);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (a[i][j] == 'B') {
        val[d] = -99999999;
        X[d] = i;
        Y[d] = j;
        d++;
      }
  for (int i = 0; i < (1 << d); i++)
    for (int j = 0; j < d; j++)
      if (i & (1 << j)) sum[i] += val[j];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (a[i][j] == 'S') {
        a[i][j] = '.';
        solve(i, j);
        return not printf("%d", ans);
      }
  return 0;
}
