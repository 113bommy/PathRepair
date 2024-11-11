#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,tune=native")
#pragma GCC target("avx,avx2")
using namespace std;
long long n, m, t;
vector<vector<bool>> u(1010, vector<bool>(1010));
vector<vector<long long>> f(1010, vector<long long>(1010, -1));
queue<pair<pair<long long, long long>, long long>> q;
void bfs() {
  vector<vector<bool>> u2(n, vector<bool>(m));
  while (!q.empty()) {
    auto to = q.front();
    q.pop();
    u2[to.first.first][to.first.second] = true;
    if (to.first.first > 0 && !u2[to.first.first - 1][to.first.second]) {
      f[to.first.first - 1][to.first.second] =
          min(to.second + 1, f[to.first.first - 1][to.first.second]);
      u2[to.first.first - 1][to.first.second] = true;
      q.push({{to.first.first - 1, to.first.second}, to.second + 1});
    }
    if (to.first.first < n - 1 && !u2[to.first.first + 1][to.first.second]) {
      f[to.first.first + 1][to.first.second] =
          min(to.second + 1, f[to.first.first + 1][to.first.second]);
      u2[to.first.first + 1][to.first.second] = true;
      q.push({{to.first.first + 1, to.first.second}, to.second + 1});
    }
    if (to.first.second > 0 && !u2[to.first.first][to.first.second - 1]) {
      f[to.first.first][to.first.second - 1] =
          min(to.second + 1, f[to.first.first][to.first.second - 1]);
      u2[to.first.first][to.first.second - 1] = true;
      q.push({{to.first.first, to.first.second - 1}, to.second + 1});
    }
    if (to.first.second < m - 1 && !u2[to.first.first][to.first.second + 1]) {
      f[to.first.first][to.first.second + 1] =
          min(to.second + 1, f[to.first.first][to.first.second + 1]);
      u2[to.first.first][to.first.second + 1] = true;
      q.push({{to.first.first, to.first.second + 1}, to.second + 1});
    }
  }
}
long long rev(char x) {
  if (x == '1')
    return 0;
  else
    return 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> t;
  vector<vector<char>> g(n, vector<char>(m));
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < m; j++) cin >> g[i][j];
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < m; j++) {
      if (i > 0 && g[i - 1][j] == g[i][j]) u[i][j] = true;
      if (j > 0 && g[i][j - 1] == g[i][j]) u[i][j] = true;
      if (i < n - 1 && g[i + 1][j] == g[i][j]) u[i][j] = true;
      if (j < m - 1 && g[i][j + 1] == g[i][j]) u[i][j] = true;
    }
  long long err = 0;
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < m; j++)
      if (u[i][j]) {
        f[i][j] = 0;
        q.push({{i, j}, 0});
      }
  bfs();
  while (t--) {
    long long x, y, p;
    cin >> x >> y >> p, x--, y--;
    if (f[x][y] > p || f[x][y] == -1)
      cout << g[x][y] << '\n';
    else {
      long long res = p - f[x][y];
      if (res % 2 != 0)
        cout << rev(g[x][y]);
      else
        cout << g[x][y];
      cout << '\n';
    }
  }
  return 0;
}
