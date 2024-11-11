#include <bits/stdc++.h>
using namespace std;
const int N = 1507;
int n, m, a[N][N], xs, ys, f[N][N][2];
int g[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
void dfs(int x, int y) {
  int xx = x % n, yy = y % m;
  if (f[xx][yy][0] == -1 && f[xx][yy][1] == -1) {
    f[xx][yy][0] = xx;
    f[xx][yy][1] = yy;
  } else if (f[xx][yy][0] != xx || f[xx][yy][1] != yy) {
    puts("Yes");
    exit(0);
  } else
    return;
  for (int i = 0; i < 4; i++) {
    int xx = (x + g[i][0]) % n, yy = (y + g[i][1]) % m;
    if (a[xx][yy] != -1) dfs(x + g[i][0], y + g[i][1]);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  char ch = getchar();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ch = getchar();
      if (ch == '#')
        a[i][j] = -1;
      else if (ch == 'S') {
        xs = i + n * m, ys = j + n * m;
      }
    }
    ch = getchar();
  }
  memset(f, -1, sizeof(f));
  dfs(xs, ys);
  puts("No");
}
