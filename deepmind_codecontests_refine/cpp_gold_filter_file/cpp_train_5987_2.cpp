#include <bits/stdc++.h>
using namespace std;
const int N = 120;
int t, n, k;
bool f[5][N], flag, wall[5][N];
void dfs(int x, int y) {
  if (flag) return;
  if (x < 1 || x > 3) return;
  f[x][y] = true;
  if (y > n) {
    flag = true;
    return;
  }
  if (!wall[x][y + 1]) {
    if (!(f[x][y + 3] || wall[x][y + 2] || wall[x][y + 3])) dfs(x, y + 3);
    if (!(f[x + 1][y + 3] || wall[x + 1][y + 1] || wall[x + 1][y + 2] ||
          wall[x + 1][y + 2]))
      dfs(x + 1, y + 3);
    if (!(f[x - 1][y + 3] || wall[x - 1][y + 1] || wall[x - 1][y + 2] ||
          wall[x - 1][y + 2]))
      dfs(x - 1, y + 3);
  }
  return;
}
int main() {
  cin >> t;
  while (t--) {
    char a;
    int sx, sy;
    cin >> n >> k;
    for (int i = 1; i <= 3; i++) {
      for (int j = 1; j <= n; j++) {
        cin >> a;
        if (a == 's')
          sx = i, sy = j, wall[i][j] = false;
        else if (a == '.')
          wall[i][j] = false;
        else
          wall[i][j] = true;
        f[i][j] = false;
      }
      for (int j = n + 1; j <= n + 5; j++) {
        wall[i][j] = false;
        f[i][j] = false;
      }
    }
    flag = false;
    dfs(sx, sy);
    if (flag)
      cout << "YES";
    else
      cout << "NO";
    if (t != 0) cout << endl;
  }
  return 0;
}
