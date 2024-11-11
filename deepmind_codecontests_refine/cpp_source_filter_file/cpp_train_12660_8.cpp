#include <bits/stdc++.h>
using namespace std;
long long n, m, p, q, t = 0;
char c[250][250];
long long ans[250][250];
long long vis[250][250];
long long dx[] = {-1, 0, 1, 0};
long long dy[] = {0, -1, 0, 1};
void flood(long long x, long long y, long long f) {
  queue<tuple<long long, long long, long long>> q;
  q.push(make_tuple(x, y, f));
  vis[x][y] = t;
  while (q.size()) {
    auto [i, j, k] = q.front();
    q.pop();
    ans[i][j] += k;
    if (k == 1) continue;
    for (long long g = 0; g < 4; g++) {
      long long ii = i + dx[g], jj = j + dy[g];
      if (ii >= 0 && ii < n && j >= 0 && j < m && vis[ii][jj] != t &&
          c[ii][jj] != '*') {
        vis[ii][jj] = t;
        q.push(make_tuple(ii, jj, k / 2));
      }
    }
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> q >> p;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      cin >> c[i][j];
    }
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (c[i][j] >= 'A' && c[i][j] <= 'Z') {
        t++;
        flood(i, j, q * (c[i][j] - 'A' + 1));
      }
    }
  }
  long long res = 0;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      res += (ans[i][j] > p);
    }
  }
  cout << res << '\n';
  return 0;
}
