#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
const int mod = 1e9 + 7;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
char ti[N][N];
int s[N][N];
int vis[N][N], f[N][N];
int main() {
  int n, m, Q;
  cin >> n >> m >> Q;
  for (int i = 1; i <= n; i++) scanf("%s", ti[i] + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) s[i][j] = ti[i][j] - '0';
  queue<pair<int, int> > q;
  memset(f, -1, sizeof(f));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      int ok = 0;
      for (int t = 0; t < 4; t++) {
        int x = dx[t] + i;
        int y = dy[t] + j;
        if (x >= 1 && x <= n && y >= 1 && y <= m && s[i][j] == s[x][y]) ok = 1;
      }
      if (ok) vis[i][j] = 1, q.push({i, j}), f[i][j] = 0;
    }
  while (!q.empty()) {
    int i = q.front().first;
    int j = q.front().second;
    q.pop();
    for (int t = 0; t < 4; t++) {
      int x = dx[t] + i;
      int y = dy[t] + j;
      if (x >= 1 && x <= n && y >= 1 && y <= m && !vis[x][y])
        f[x][y] = f[i][j] + 1, vis[x][y] = 1, q.push({x, y});
    }
  }
  while (Q--) {
    int i, j, p;
    cin >> i >> j >> p;
    if (f[i][j] == 0)
      printf("%d\n", s[i][j] ^ (p & 1));
    else if (f[i][j] == -1) {
      printf("%d\n", s[i][j]);
    } else {
      if (f[i][j] >= p)
        printf("%d\n", s[i][j]);
      else
        printf("%d\n", s[i][j] ^ ((p - f[i][j]) & 1));
    }
  }
}
