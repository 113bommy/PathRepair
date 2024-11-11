#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<char>> a(n, vector<char>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'P') {
        const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
        for (int k = 0; k < 4; k++) {
          int x = i + dx[k];
          int y = j + dy[k];
          if (x >= 0 && x < n && y >= 0 && y < m) {
            if (a[x][y] == 'W') {
              ++res;
              a[x][y] = 'O';
            }
          }
        }
      }
    }
  }
  cout << res << '\n';
  return 0;
}
