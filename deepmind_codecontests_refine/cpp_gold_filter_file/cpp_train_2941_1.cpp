#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
  cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args) {
  const char *comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
long long n, m, k, t;
long long dx[] = {-1, 0, 0, 1};
long long dy[] = {0, -1, 1, 0};
long long f[1005][1005];
bool vis[1005][1005];
long long dis[1005][1005];
bool check(long long i, long long j) {
  for (long long d = 0; d <= 3; d++) {
    long long x = i + dx[d], y = j + dy[d];
    if (f[i][j] == f[x][y]) return 1;
  }
  return 0;
}
void multisource_bfs() {
  queue<pair<long long, long long>> q;
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= m; j++) {
      if (check(i, j)) {
        q.push({i, j});
        vis[i][j] = 1;
      }
    }
  while (!q.empty()) {
    pair<long long, long long> fr = q.front();
    q.pop();
    for (long long i = 0; i <= 3; i++) {
      long long x = fr.first + dx[i], y = fr.second + dy[i];
      if (x >= 1 && x <= n && y >= 1 && y <= m && !vis[x][y]) {
        dis[x][y] = 1 + dis[fr.first][fr.second];
        vis[x][y] = 1;
        q.push({x, y});
      }
    }
  }
}
int32_t main() {
  std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  ;
  cin >> n >> m >> t;
  memset(f, -1, sizeof(f));
  for (long long i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (long long j = 0; j < m; j++) f[i][j + 1] = (s[j] == '0') ? 0 : 1;
  }
  multisource_bfs();
  while (t--) {
    long long i, j, p;
    cin >> i >> j >> p;
    long long itr = dis[i][j];
    if (vis[i][j])
      cout << (f[i][j] ^ (max(0ll, p - itr) & 1)) << endl;
    else
      cout << f[i][j] << endl;
  }
}
