#include <bits/stdc++.h>
using namespace std;
const int N = 100;
char a[N][N];
bool used[N][N];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int n, m;
void dfs(int x, int y) {
  used[x][y] = 1;
  for (int i = 0; i < 4; i++) {
    int xx = dx[i] + x;
    int yy = dy[i] + y;
    if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && !used[xx][yy] &&
        a[xx][yy] == '#')
      dfs(xx, yy);
  }
}
int main() {
  int i, j;
  cin >> n >> m;
  int cnt = 0;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      cin >> a[i][j];
      if (a[i][j] == '#') cnt++;
    }
  }
  if (cnt <= 2) {
    puts("-1");
    return 0;
  }
  int x, y;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      if (a[i][j] == '#') {
        a[i][j] = '.';
        for (x = 1; x <= n; x++) {
          for (y = 1; y <= m; y++) {
            used[x][y] = 0;
          }
        }
        for (x = 1; x <= n; x++) {
          for (y = 1; y <= m; y++) {
            if (!used[x][y] && a[x][y] == '#') {
              dfs(x, y);
              i = n + 1;
              break;
            }
          }
        }
        for (x = 1; x <= n; x++) {
          for (y = 1; y <= m; y++) {
            if (!used[x][y] && a[x][y] == '#') {
              puts("1");
              return 0;
            }
          }
        }
        a[i][j] = '#';
      }
    }
  }
  puts("2");
}
