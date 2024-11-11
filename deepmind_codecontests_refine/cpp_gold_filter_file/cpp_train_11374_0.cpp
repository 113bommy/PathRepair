#include <bits/stdc++.h>
using namespace std;
const int N = 40;
int t, n, m, g[N][N];
int d[N][N];
queue<pair<int, int> > q;
unordered_map<int, pair<int, int> > mp;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int bfs() {
  memset(d, -1, sizeof d);
  mp.clear();
  int res = 0;
  q.push({1, 1});
  q.push({n, m});
  if (g[1][1] != g[n][m]) res++;
  d[1][1] = d[n][m] = 0;
  while (q.size()) {
    auto t = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int tx = t.first + dx[i], ty = t.second + dy[i];
      if (tx < 1 || ty < 1 || tx > n || ty > m) continue;
      if (d[tx][ty] != -1) continue;
      int &di = d[tx][ty];
      di = d[t.first][t.second] + 1;
      if (mp.count(di) == 0)
        mp[di] = {1, g[tx][ty]};
      else
        mp[di] = {mp[di].first + 1, mp[di].second + g[tx][ty]};
      q.push({tx, ty});
    }
  }
  for (int i = 1; i <= (n + m - 3) / 2; i++)
    res += min(mp[i].second, mp[i].first - mp[i].second);
  return res;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) cin >> g[i][j];
    cout << bfs() << endl;
  }
  return 0;
}
