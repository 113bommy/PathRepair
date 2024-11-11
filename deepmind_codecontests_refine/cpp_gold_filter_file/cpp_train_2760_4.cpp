#include <bits/stdc++.h>
using namespace std;
int n, m, ans, f[1009][1009], s[1009][1009], dx[4] = {0, 0, 1, -1},
                                             dy[4] = {1, -1, 0, 0};
char a[1009][1009];
bool v[1009][1009];
queue<pair<int, int> > q;
void z(int x, int y) {
  int xx, yy, X, Y;
  f[x][y] = x * 10000 + y;
  s[x][y] = 1;
  v[x][y] = 1;
  q.push(make_pair(x, y));
  while (!q.empty()) {
    xx = q.front().first;
    yy = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      X = xx + dx[i];
      Y = yy + dy[i];
      if (X >= 0 && X < n && Y >= 0 && Y < m && a[X][Y] == '.' && !v[X][Y]) {
        v[X][Y] = 1;
        f[X][Y] = f[x][y];
        s[x][y]++;
        q.push(make_pair(X, Y));
      }
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", a[i]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!v[i][j] && a[i][j] == '.') z(i, j);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '*') {
        ans = 0;
        int X, Y, x, y;
        for (int k = 0; k < 4; k++) {
          X = i + dx[k];
          Y = j + dy[k];
          if (X >= 0 && X < n && Y >= 0 && Y < m && a[X][Y] == '.') {
            ans += s[f[X][Y] / 10000][f[X][Y] % 10000];
            for (int l = 0; l < k; l++) {
              x = i + dx[l];
              y = j + dy[l];
              if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == '.' &&
                  f[x][y] == f[X][Y]) {
                ans -= s[f[X][Y] / 10000][f[X][Y] % 10000];
                break;
              }
            }
          }
        }
        printf("%d", (ans + 1) % 10);
      } else
        printf(".");
    }
    printf("\n");
  }
  return 0;
}
