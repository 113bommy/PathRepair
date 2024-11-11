#include <bits/stdc++.h>
using namespace std;
long long const MAXN = 50 + 10;
long long n, m, T;
char mp[MAXN][MAXN];
vector<pair<long long, long long> > all;
long long st[MAXN][MAXN];
long long get(long long x, long long y) { return x * m + y; }
long long dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
void dfs(long long x, long long y) {
  for (long long i = 0; i < 4; ++i) {
    long long next_x = x + dx[i], next_y = y + dy[i];
    if (next_x < 0 || next_x > n - 1 || next_y < 0 || next_y > m - 1 ||
        mp[next_x][next_y] == '.')
      continue;
    if (st[next_x][next_y]) continue;
    st[next_x][next_y] = 1;
    dfs(next_x, next_y);
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  long long sx = 0, sy = 0;
  for (long long i = 0; i < n; ++i) {
    cin >> mp[i];
    for (long long j = 0; j < m; ++j) {
      if (mp[i][j] == '#') {
        sx = i, sy = j;
        all.push_back({i, j});
      }
    }
  }
  if (all.size() == 0) {
    cout << 0 << endl;
    return 0;
  }
  st[sx][sy] = 1;
  dfs(sx, sy);
  for (auto a : all) {
    if (st[a.first][a.second] == 0) {
      cout << 0 << endl;
      return 0;
    }
  }
  for (auto this_p : all) {
    long long x = this_p.first, y = this_p.second;
    mp[x][y] = '.';
    long long sx = (*all.begin()).first, sy = (*all.begin()).second;
    for (auto tmp : all) {
      if (mp[tmp.first][tmp.second] == '#') {
        sx = tmp.first, sy = tmp.second;
        break;
      }
    }
    memset(st, 0, sizeof st);
    st[sx][sy] = 1;
    dfs(sx, sy);
    for (auto a : all) {
      if (a.first == x && a.second == y) continue;
      if (st[a.first][a.second] == 0) {
        cout << 1 << endl;
        return 0;
      }
    }
    mp[x][y] = '#';
  }
  cout << 2;
  return 0;
}
