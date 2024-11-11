#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
bool vis[2][2][N + 100];
int n, m;
long long cnt;
void dfs(int x, int y) {
  if (x == 1)
    vis[0][0][y] = 1;
  else if (x == n)
    vis[0][1][y] = 1;
  else if (y == 1)
    vis[1][0][x] = 1;
  else
    vis[1][1][x] = 1;
  if (y + 1 <= m && x - 1 >= 1) {
    if (y + x - 1 <= m && !vis[0][0][y + x - 1]) {
      dfs(1, y + x - 1);
    } else if (y + x - 1 > m && !vis[1][1][x - (m - y)]) {
      dfs(x - (m - y), m);
    }
  }
  if (y + 1 <= m && x + 1 <= n) {
    if (y + n - x <= m && !vis[0][1][y + n - x]) {
      dfs(n, y + n - x);
    } else if (y + n - x > m && !vis[1][1][x + m - y]) {
      dfs(x + m - y, m);
    }
  }
  if (y - 1 >= 1 && x - 1 >= 1) {
    if (y - (x - 1) >= 1 && !vis[0][0][y - (x - 1)]) {
      dfs(1, y - (x - 1));
    } else if (y - (x - 1) < 1 && !vis[1][0][x - (y - 1)]) {
      dfs(x - (y - 1), 1);
    }
  }
  if (y - 1 >= 1 && x + 1 <= n) {
    if (y - (n - x) >= 1 && !vis[0][1][y - (n - x)]) {
      dfs(n, y - (n - x));
    } else if (y - (n - x) < 1 && !vis[1][0][x + (y - 1)]) {
      dfs(x + (y - 1), 1);
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    if (!vis[0][0][i]) {
      dfs(1, i);
      cnt++;
    }
    if (!vis[0][1][i]) {
      dfs(n, i);
      cnt++;
    }
  }
  for (int i = 2; i < n; i++) {
    if (!vis[1][0][i]) {
      dfs(i, 1);
      cnt++;
    }
    if (!vis[0][1][i]) {
      dfs(i, m);
      cnt++;
    }
  }
  printf("%I64d\n", cnt);
  return 0;
}
