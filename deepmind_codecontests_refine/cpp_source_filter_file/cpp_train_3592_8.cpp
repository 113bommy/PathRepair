#include <bits/stdc++.h>
using namespace std;
queue<pair<long long, long long> > q;
string c[1200];
long long n, m;
long long d1[3][3], dis[3][1200][1200];
long long xx[] = {1, 0, -1, 0};
long long yy[] = {0, 1, 0, -1};
void BFS(long long p) {
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (c[i][j] - '1' == p) {
        dis[p][i][j] = 0;
        q.push(make_pair(i, j));
      } else
        dis[p][i][j] = 1000000007;
    }
  }
  while (!q.empty()) {
    pair<long long, long long> pp = q.front();
    q.pop();
    long long x = pp.first;
    long long y = pp.second;
    for (long long i = 0; i <= 3; i++) {
      long long x1, y1;
      x1 = x + xx[i];
      y1 = y + yy[i];
      if (x1 < 0 || y1 < 0 || x1 >= n || y1 >= m) continue;
      if (c[x1][y1] == '#') continue;
      if (dis[p][x1][y1] != 1000000007) continue;
      dis[p][x1][y1] = dis[p][x][y] + 1;
      if (c[x1][y1] >= '1' && c[x1][y1] <= '3' &&
          d1[p][c[x1][y1] - '1'] == 1000000007)
        d1[p][c[x1][y1] - '1'] = dis[p][x1][y1];
      q.push(make_pair(x1, y1));
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (long long i = 0; i < n; i++) cin >> c[i];
  for (long long i = 0; i < 3; i++)
    for (long long j = 0; j < 3; j++) d1[i][j] = 1000000007;
  long long ans = 1000000007;
  BFS(0);
  BFS(1);
  BFS(2);
  ans = min(ans, d1[0][1] + d1[0][2] - 2);
  ans = min(ans, d1[1][0] + d1[1][2] - 2);
  ans = min(ans, d1[2][0] + d1[2][1] - 2);
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (c[i][j] == '.')
        ans = min(ans, dis[0][i][j] + dis[1][i][j] + dis[2][i][j] - 2);
    }
  }
  if (ans == 1000000007) ans = -1;
  cout << ans;
}
