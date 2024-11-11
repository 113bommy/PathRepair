#include <bits/stdc++.h>
using namespace std;
char grid[10][10][10];
bool visited[10][10][10];
const int dx[] = {0, 0, -1, +1, 0, 0};
const int dy[] = {-1, +1, 0, 0, 0, 0};
const int dz[] = {0, 0, 0, 0, -1, +1};
struct node {
  int x, y, z;
};
int main() {
  int k, n, m;
  cin >> k >> n >> m;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      string s;
      cin >> s;
      for (int len = 0; len < s.length(); len++) {
        grid[i][j][len] = s[len];
      }
    }
  }
  int x, y;
  cin >> x >> y;
  x--;
  y--;
  int ans = 0;
  queue<node> q;
  q.push({0, x, y});
  visited[0][x][y] = 1;
  while (!q.empty()) {
    node v = q.front();
    q.pop();
    ans++;
    for (int t = 0; t < 6; t++) {
      auto ni = v.x + dx[t];
      auto nj = v.y + dy[t];
      auto nl = v.z + dz[t];
      if (ni < 0 || ni >= k) continue;
      if (nj < 0 || nj >= n) continue;
      if (nl < 0 || nl >= m) continue;
      if (visited[ni][nj][nl]) continue;
      if (grid[ni][nj][nl] == '#') continue;
      visited[ni][nj][nl] = 1;
      q.push({ni, nj, nl});
    }
  }
  cout << ans << '\n';
  return 0;
}
