#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 7;
const int mod = 1e9 + 7;
int n, m, x, y, px = -1, py = -1, ans[100005], cnt, u[N][N];
string second;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> x >> y;
  cin >> second;
  u[x][y] = 1;
  ans[0] = 1;
  for (int i = 0; i < second.size(); ++i) {
    if (second[i] == 'L' && y > 1) y--;
    if (second[i] == 'R' && y < m) y++;
    if (second[i] == 'U' && x > 1) x--;
    if (second[i] == 'D' && x < n) x++;
    if (u[x][y] == 0) ans[i + 1] = 1;
    u[x][y] = 1;
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (u[i][j]) cnt++;
  ans[second.size()] += n * m - cnt;
  for (int i = 0; i <= second.size(); ++i) cout << ans[i] << " ";
  return 0;
}
