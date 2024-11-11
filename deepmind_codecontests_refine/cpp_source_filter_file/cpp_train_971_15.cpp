#include <bits/stdc++.h>
using namespace std;
int n, k, d[2][100100], di;
string s[2];
int main() {
  cin >> n >> k;
  const int dx[] = {0, 0, 1}, dy[] = {1, -1, k};
  cin >> s[0];
  cin >> s[1];
  queue<pair<bool, int> > q;
  q.push(make_pair(0, 0));
  memset(d, -1, sizeof(d));
  d[0][0] = 0;
  while (!q.empty()) {
    pair<bool, int> u = q.front();
    q.pop();
    int x = u.first, y = u.second;
    if (y >= n) {
      cout << "YES";
      return 0;
    }
    for (int i = 0; i < 3; i++) {
      int nx = x ^ dx[i], ny = y + dy[i];
      if (ny < 0) continue;
      if (s[nx][ny] == 'X') continue;
      if (d[nx][ny] != -1) continue;
      if (d[x][y] + 1 > ny) continue;
      d[nx][ny] = d[x][y] + 1;
      q.push(make_pair(nx, ny));
    }
  }
  cout << "NO";
  return 0;
}
