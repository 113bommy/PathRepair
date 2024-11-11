#include <bits/stdc++.h>
using namespace std;
bool edge[4][100005];
int x, y;
int main() {
  int n, m;
  cin >> n >> m;
  string dir;
  cin >> x >> y >> dir;
  int dx = (dir[0] == 'D' ? 1 : -1);
  int dy = (dir[1] == 'R' ? 1 : -1);
  int tot = 0;
  int ans = 1;
  for (int i = 1; i <= 2 * (n + m - 2); i++) {
    int a, b;
    if (x == 1)
      a = 0, b = y;
    else if (x == n)
      a = 1, b = y;
    else if (y == 1)
      a = 2, b = x;
    else
      a = 3, b = x;
    if (!edge[a][b]) edge[a][b] = 1, tot++;
    if (x == 1) dx = 1;
    if (x == n) dx = -1;
    if (y == 1) dy = 1;
    if (y == m) dy = -1;
    if (tot >= (n + m - 2)) {
      cout << ans << endl;
      return 0;
    }
    int w = min(dx > 0 ? n - x : x - 1, dy > 0 ? m - y : y - 1);
    ans += w;
    x += dx * w;
    y += dy * w;
  }
  cout << -1 << endl;
  return 0;
}
