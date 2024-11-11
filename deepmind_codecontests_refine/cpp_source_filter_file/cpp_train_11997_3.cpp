#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int n, m, q;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
bool vis[N][N];
pair<pair<int, int>, pair<int, int> > rect[N][N];
string s[N];
int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  cin >> n >> q;
  for (int i = (0); i < (n); ++i) cin >> s[i];
  m = (int)s[0].size();
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (m); ++j)
      if (s[i][j] != '0' && !vis[i][j]) {
        int x = i, y = j;
        while (x < n && s[x][j] == s[i][j]) ++x;
        while (y < m && s[i][y] == s[i][j]) ++y;
        --x, --y;
        for (int a = (i); a < (x + 1); ++a)
          for (int b = (j); b < (y + 1); ++b) {
            vis[i][j] = 1;
            rect[i][j] = make_pair(make_pair(i, x), make_pair(j, y));
          }
      }
  int x = 0, y = 0, dp = 0, cp = 0;
  for (int i = (0); i < (q); ++i) {
    int a1 = rect[x][y].first.first, a2 = rect[x][y].first.second;
    int b1 = rect[x][y].second.first, b2 = rect[x][y].second.second;
    if (dp == 0) {
      y = b2;
      x = ((cp == 0) ? a1 : a2);
    } else if (dp == 1) {
      x = a2;
      y = ((cp == 0) ? b2 : b1);
    } else if (dp == 2) {
      y = b1;
      x = ((cp == 0) ? a2 : a1);
    } else {
      x = a1;
      y = ((cp == 0) ? b1 : b2);
    }
    int nx = x + dx[dp], ny = y + dy[dp];
    if (nx < 0 || nx >= n || ny < 0 || ny >= m || s[nx][ny] == '0') {
      if (cp) dp = (dp + 1) % 4;
      cp ^= 1;
    } else {
      x = nx, y = ny;
    }
  }
  cout << s[x][y] << "\n";
  return 0;
}
