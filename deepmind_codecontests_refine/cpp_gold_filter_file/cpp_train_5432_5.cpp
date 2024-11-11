#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int neg = 1, num = 0;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') neg = -1;
  for (; isdigit(c); c = getchar()) num = (num << 1) + (num << 3) + c - '0';
  return neg * num;
}
int n, a[110][110], vis[110][110];
int dx[] = {-2, -1, 0, 2, 1, 0}, dy[] = {0, -1, -2, 0, 1, 2};
inline void bfs(int sx, int sy) {
  queue<pair<int, int> > q;
  q.push(make_pair(sx, sy));
  while (!q.empty()) {
    pair<int, int> u = q.front();
    q.pop();
    for (int i = 0; i <= 5; i++) {
      int x = u.first + dx[i];
      int y = u.second + dy[i];
      if (x > n || y > n || x < 1 || y < 1) continue;
      if (!vis[x][y]) {
        vis[x][y] = 1;
        cout << "? " << min(x, u.first) << " " << min(y, u.second) << " "
             << max(x, u.first) << " " << max(y, u.second) << endl;
        int w = read();
        fflush(stdout);
        a[x][y] = a[u.first][u.second] ^ w ^ 1;
        q.push(make_pair(x, y));
      }
    }
  }
}
signed main() {
  n = read();
  vis[1][1] = 1;
  a[1][1] = 1;
  vis[n][n] = 1;
  a[n][n] = 0;
  bfs(1, 1);
  vis[1][2] = 1;
  a[1][2] = 1;
  bfs(1, 2);
  int w = 0;
  for (int i = 1; i <= n - 2; i += 2)
    if (a[i][i] != a[i + 2][i + 2]) {
      if ((a[i][i] ^ a[i + 1][i] ^ a[i + 1][i + 1] ^ a[i + 2][i + 1]) == 0) {
        cout << "? " << i << " " << i << " " << i + 2 << " " << i + 1 << endl;
        int x = read();
        fflush(stdout);
        if (x == 0 && a[i][i] == a[i + 2][i + 1])
          w = 1;
        else if (x == 1 && a[i][i] != a[i + 2][i + 1])
          w = 1;
        break;
      } else if ((a[i + 1][i] ^ a[i + 1][i + 1] ^ a[i + 2][i + 1] ^
                  a[i + 2][i + 2]) == 0) {
        cout << "? " << i + 1 << " " << i << " " << i + 2 << " " << i + 2
             << endl;
        int x = read();
        fflush(stdout);
        if (x == 0 && a[i + 1][i] == a[i + 2][i + 2])
          w = 1;
        else if (x == 1 && a[i + 1][i] != a[i + 2][i + 2])
          w = 1;
        break;
      }
    }
  printf("!\n");
  for (int i = 1; i <= n; i++, cout << endl)
    for (int j = 1; j <= n; j++)
      cout << ((i + j & 1) ? (a[i][j] ^ w) : a[i][j]), fflush(stdout);
  return 0;
}
