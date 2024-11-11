#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
char ans[maxn][maxn], s[maxn][maxn];
int vis[maxn][maxn];
int belong[maxn][maxn], size[(int)1e6 + 10];
int n, m;
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
int sum, cur;
bool inside(int x, int y) {
  if (x >= 1 && x <= n && y >= 1 && y <= m) return 1;
  return 0;
}
void dfs(int x, int y) {
  vis[x][y] = 1;
  belong[x][y] = cur;
  size[cur]++;
  for (int i = 0; i < 4; i++) {
    int xx = x + dir[i][0];
    int yy = y + dir[i][1];
    if ((!inside(xx, yy)) || (vis[xx][yy]) || s[xx][yy] == '*') continue;
    dfs(xx, yy);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
  }
  cur = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == '.' && (!vis[i][j])) {
        dfs(i, j);
        cur++;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == '.')
        ans[i][j] = '.';
      else {
        set<int> f;
        f.insert(belong[i + 1][j]);
        f.insert(belong[i - 1][j]);
        f.insert(belong[i][j + 1]);
        f.insert(belong[i][j - 1]);
        int sum = 1;
        for (int x : f) {
          sum += (size[x]) % 10;
        }
        ans[i][j] = sum % 10 + '0';
      }
    }
    ans[i][m + 1] = '\0';
  }
  for (int i = 1; i <= n; i++) {
    printf("%s\n", ans[i] + 1);
  }
  return 0;
}
