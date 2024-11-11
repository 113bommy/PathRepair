#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
int n, m, p, cnt, a[510][510];
char s[510][510];
void dfs(int i, int j) {
  cnt++;
  a[i][j] = cnt;
  int x, y;
  for (int k = 0; k < 4; k++) {
    x = i + dx[k];
    y = i + dy[k];
    if (x >= 0 && y >= 0 && x < n && y < m && s[x][y] == '.' && !a[x][y]) {
      dfs(x, y);
    }
  }
}
int main() {
  cin >> n >> m >> p;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '.' && !a[i][j]) {
        dfs(i, j);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '.' && a[i][j] > cnt - p) {
        cout << "X";
      } else {
        cout << s[i][j];
      }
    }
    cout << endl;
  }
  return 0;
}
