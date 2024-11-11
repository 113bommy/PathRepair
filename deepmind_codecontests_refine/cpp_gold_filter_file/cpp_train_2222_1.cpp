#include <bits/stdc++.h>
using namespace std;
const int N = 59;
int ma[N][N], m, n, p, dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
string t[N];
int dfs(int x, int y) {
  if (ma[x][y] || x < 0 || y < 0 || x >= m || y >= n || t[x][y] == '.')
    return 0;
  ma[x][y] = 1;
  for (int i = 0; i < 4; i++) dfs(x + dx[i], y + dy[i]);
  return 1;
}
int main() {
  cin >> m >> n;
  for (int i = 0; i < m; i++) cin >> t[i];
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (t[i][j] == '#') {
        int s = 0;
        memset(ma, 0, sizeof ma), t[i][j] = '.', p++;
        for (int k = 0; k < 4; k++) s += dfs(i + dx[k], j + dy[k]);
        if (s > 1) return cout << "1" << endl, 0;
        t[i][j] = '#';
      }
  if (p < 3)
    cout << "-1";
  else
    cout << "2";
}
