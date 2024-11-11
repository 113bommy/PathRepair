#include <bits/stdc++.h>
using namespace std;
int n, m;
string s[55];
int vis[55][55];
void dfs(int i, int j) {
  if (j + 1 < m && s[i][j + 1] == '#' && vis[i][j + 1] == 0) {
    vis[i][j + 1] = 1;
    dfs(i, j + 1);
  }
  if (j - 1 >= 0 && s[i][j - 1] == '#' && vis[i][j - 1] == 0) {
    vis[i][j - 1] = 1;
    dfs(i, j - 1);
  }
  if (i - 1 >= 0 && s[i - 1][j] == '#' && vis[i - 1][j] == 0) {
    vis[i - 1][j] = 1;
    dfs(i - 1, j);
  }
  if (i + 1 < n && s[i + 1][j] == '#' && vis[i + 1][j] == 0) {
    vis[i + 1][j] = 1;
    dfs(i + 1, j);
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  cin >> n >> m;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '#') cnt++;
    }
  }
  if (cnt < 3) {
    cout << -1;
    return 0;
  }
  int flag = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '#') {
        for (int k = 0; k < n; k++) {
          memset(vis[k], 0, sizeof(vis[k]));
        }
        s[i][j] = '.';
        if (i - 1 >= 0 && s[i - 1][j] == '#') {
          vis[i - 1][j] = 1;
          dfs(i - 1, j);
        } else if (j - 1 >= 0 && s[i][j - 1] == '#') {
          vis[i][j - 1] = 1;
          dfs(i, j - 1);
        } else if (i + 1 < n && s[i + 1][j] == '#') {
          vis[i + 1][j] = 1;
          dfs(i + 1, j);
        } else if (j + 1 < m && s[i][j + 1] == '#') {
          vis[i][j + 1] = 1;
          dfs(i, j + 1);
        }
        for (int p = 0; p < n; p++) {
          for (int q = 0; q < m; q++) {
            if (s[p][q] == '#' && vis[p][q] == 0) {
              flag = 1;
              break;
            }
          }
          if (flag) break;
        }
        if (flag == 1) {
          cout << 1;
          return 0;
        } else
          s[i][j] = '#';
      }
    }
  }
  cout << 2;
  return 0;
}
