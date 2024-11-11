#include <bits/stdc++.h>
using namespace std;
string s[8];
int mark[8][8];
bool in(int x, int y) {
  if (x < 0 || x > 7) return 0;
  if (y < 0 || y > 7) return 0;
  return 1;
}
int dx[] = {-2, +2, -2, +2};
int dy[] = {+2, -2, -2, +2};
int t;
int main() {
  cin >> t;
  while (t--) {
    memset(mark, 0, sizeof(mark));
    for (int i = 0; i < 8; ++i) s[i].clear(), cin >> s[i];
    int x1, x2, y1, y2, x = -1, y = -1, ok;
    ok = 1;
    for (int i = 0; i < 8; ++i)
      for (int j = 0; j < 8; ++j)
        if (s[i][j] == 'K' && ok) {
          x1 = i;
          y1 = j;
          s[i][j] = '#';
          ok = 0;
        };
    ok = 1;
    for (int i = 0; i < 8; ++i)
      for (int j = 0; j < 8; ++j)
        if (s[i][j] == 'K' && ok) {
          x2 = i;
          y2 = j;
          s[i][j] = '#';
          ok = 0;
        };
    for (int d1 = 0; d1 < 4; ++d1)
      for (int d2 = 0; d2 < 4; ++d2)
        if (x1 + dx[d1] == x2 + dx[d2] && y1 + dy[d1] == y2 + dy[d2])
          if (in(x1 + dx[d1], y1 + dy[d1])) {
            x = x1 + dx[d1];
            y = y1 + dy[d1];
          }
    if (x < 0) {
      cout << "NO\n";
      continue;
    }
    mark[x][y] = 1;
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    while (q.size()) {
      pair<int, int> n = q.front();
      q.pop();
      for (int d1 = 0; d1 < 4; ++d1) {
        x = n.first + dx[d1];
        y = n.first + dy[d1];
        if (in(x, y) && mark[x][y] == 0) {
          mark[x][y] = 1;
          q.push(make_pair(x, y));
        }
      }
    }
    ok = 0;
    for (int i = 0; i < 8; ++i)
      for (int j = 0; j < 8; ++j)
        if (mark[i][j] && s[i][j] == '.' && !ok) {
          cout << "YES\n";
          ok = 1;
        }
    if (!ok) cout << "NO\n";
  }
}
