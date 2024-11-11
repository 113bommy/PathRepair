#include <bits/stdc++.h>
using namespace std;
const int maxn = 50 + 10;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
int n, m, X, Y, key;
int a[maxn][maxn], check[maxn][maxn];
int dfs(int x, int y, int tot) {
  check[x][y] = 1;
  int ret = 0;
  for (int i = 0; i < 4; i++) {
    int xx = x + dx[i], yy = y + dy[i];
    if (xx < 1 || xx > n || yy < 1 || yy > m || a[xx][yy] != key) continue;
    if (check[xx][yy] && x == X && yy == Y && tot >= 4) return 1;
    if (!check[xx][yy]) ret |= dfs(xx, yy, tot + 1);
  }
  return ret;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    char tt[maxn];
    scanf("%s", tt + 1);
    for (int j = 1; j <= m; j++) a[i][j] = tt[j] - 'A';
  }
  queue<pair<int, int> > Q;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      X = i;
      Y = j;
      key = a[i][j];
      memset(check, 0, sizeof(check));
      if (dfs(i, j, 1)) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  cout << "No" << endl;
  return 0;
}
