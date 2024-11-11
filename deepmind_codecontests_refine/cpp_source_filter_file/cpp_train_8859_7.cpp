#include <bits/stdc++.h>
using namespace std;
long long n, m, row, col, l, r;
vector<vector<char> > g;
vector<vector<long long> > used, L, R;
long long dx[4] = {1, -1, 0, 0};
long long dy[4] = {0, 0, 1, -1};
char ok(long long x, long long y) {
  return (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == '.');
}
void bfs() {
  deque<pair<long long, long long> > q;
  q.push_back({row, col});
  used[row][col] = 1;
  L[row][col] = R[row][col] = 0;
  while (!q.empty()) {
    long long x = q.front().first;
    long long y = q.front().second;
    q.pop_front();
    for (long long i = 0; i < 4; ++i) {
      long long nx = x + dx[i], ny = y + dy[i];
      if (!ok(nx, ny)) continue;
      if (!used[nx][ny]) {
        if (i != 2 && i != 3) {
          q.push_front({nx, ny});
        } else
          q.push_back({nx, ny});
        used[nx][ny] = 1;
        L[nx][ny] = L[x][y] + (i == 3);
        R[nx][ny] = R[x][y] + (i == 2);
      }
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(20);
  cin >> n >> m >> row >> col >> l >> r;
  --row, --col;
  g.resize(n, vector<char>(m));
  L.resize(n, vector<long long>(m, 1e2));
  R.resize(n, vector<long long>(m, 1e2));
  used.resize(n, vector<long long>(m, 0));
  for (auto& i : g)
    for (auto& j : i) cin >> j;
  bfs();
  long long ans = 0;
  for (long long i = 0; i < n; ++i) {
    for (long long j = 0; j < m; ++j) {
      ans += (L[i][j] <= l && R[i][j] <= r);
    }
  }
  cout << ans;
}
