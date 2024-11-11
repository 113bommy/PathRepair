#include <bits/stdc++.h>
using namespace std;
const int N = 2222;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
char s[N][N];
int n, m, qx[N * N], qy[N * N], head, tail;
void input() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> s[i] + 1;
}
void check(int x, int y) {
  for (int h = 0; h < 4; ++h) {
    int u = x + dx[h], v = y + dy[h];
    if (s[u][v] != '.') continue;
    int d = 0;
    for (int t = 0; t < 4; ++t) {
      int uu = u + dx[t], vv = v + dy[t];
      if (s[uu][vv] == '.') ++d;
    }
    if (d == 1) {
      ++tail;
      qx[tail] = u;
      qy[tail] = v;
    }
  }
}
void solve() {
  for (int i = 1; i <= m; ++i) {
    s[0][i] = '*';
    s[n + 1][i] = '*';
  }
  for (int i = 1; i <= n; ++i) {
    s[i][0] = '*';
    s[i][m + 1] = '*';
  }
  head = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      if (s[i][j] != '.') continue;
      int k = 0;
      for (int h = 0; h < 4; ++h) {
        int x = i + dx[h], y = j + dy[h];
        if (s[x][y] == '.') ++k;
      }
      if (k == 1) {
        ++tail;
        qx[tail] = i;
        qy[tail] = j;
      }
    }
  while (head <= tail) {
    int x = qx[head], y = qy[head];
    ++head;
    for (int h = 0; h < 4; ++h) {
      int u = x + dx[h], v = y + dy[h];
      if (s[u][v] == '.') {
        switch (h) {
          case 0:
            s[x][y] = '^';
            s[u][v] = 'V';
            break;
          case 1:
            s[x][y] = 'V';
            s[u][v] = '^';
            break;
          case 2:
            s[x][y] = '<';
            s[u][v] = '>';
            break;
          case 3:
            s[x][y] = '>';
            s[u][v] = '<';
            break;
        }
        check(u, v);
        check(x, y);
        break;
      }
    }
  }
  bool ok = true;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (s[i][j] == '.') ok = false;
  if (!ok) {
    cout << "Not unique";
    return;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) printf("%c", s[i][j]);
    printf("\n");
  }
}
int main() {
  int nTest = 1;
  while (nTest--) {
    input();
    solve();
  }
  return 0;
}
