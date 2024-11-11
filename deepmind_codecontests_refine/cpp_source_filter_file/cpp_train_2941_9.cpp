#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  int t = 1;
  while (t--) {
    int n, m, tt;
    cin >> n >> m >> tt;
    char ch[n][m];
    int ans[n][m];
    bool vis[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> ch[i][j];
        ans[i][j] = 0;
        vis[i][j] = 0;
      }
    }
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if ((i != 0 && ch[i - 1][j] == ch[i][j]) ||
            (i != n - 1 && ch[i + 1][j] == ch[i][j]) ||
            (j != 0 && ch[i][j - 1] == ch[i][j]) ||
            (j != m - 1 && ch[i][j + 1] == ch[i][j])) {
          vis[i][j] = 1;
          q.push({i, j});
          ans[i][j] = 1;
        }
      }
    }
    while (!q.empty()) {
      pair<int, int> p = q.front();
      int x = p.first, y = p.second;
      q.pop();
      if (x != 0 && vis[x - 1][y] == 0 && ch[x - 1][y] != ch[x][y]) {
        vis[x - 1][y] = 1;
        ans[x - 1][y] = ans[x][y] + 1;
        q.push({x - 1, y});
      }
      if (x != n - 1 && vis[x + 1][y] == 0 && ch[x + 1][y] != ch[x][y]) {
        vis[x + 1][y] = 1;
        ans[x + 1][y] = ans[x][y] + 1;
        q.push({x + 1, y});
      }
      if (y != 0 && vis[x][y - 1] == 0 && ch[x][y - 1] != ch[x][y]) {
        vis[x][y - 1] = 1;
        ans[x][y - 1] = ans[x][y] + 1;
        q.push({x, y - 1});
      }
      if (y != m - 1 && vis[x][y + 1] == 0 && ch[x][y + 1] != ch[x][y]) {
        vis[x][y + 1] = 1;
        ans[x][y + 1] = ans[x][y] + 1;
        q.push({x, y + 1});
      }
    }
    while (tt--) {
      int x, y, p;
      cin >> x >> y >> p;
      x--, y--;
      if (ans[x][y] == 0 || p < ans[x][y])
        cout << ch[x][y] << "\n";
      else if ((p - ans[x][y]) % 2 == 0)
        cout << (ch[x][y] == '1' ? '0' : '1') << "\n";
      else
        cout << ch[x][y] << "\n";
    }
  }
  return 0;
}
