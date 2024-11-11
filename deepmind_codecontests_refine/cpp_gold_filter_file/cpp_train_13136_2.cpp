#include <bits/stdc++.h>
using namespace std;
long long INF = 1e9 + 7;
long long MOD = 998244353;
long long dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
long long dy[8] = {1, -1, 0, 0, -1, 1, 1, -1};
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  char arr[n][m];
  bool v[n][m];
  long long d[n][m];
  queue<pair<long long, long long> > q;
  memset(v, 0, sizeof v);
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == '.') {
        v[i][j] = 1;
        d[i][j] = 0;
        q.push(pair<long long, long long>(i, j));
      }
    }
  }
  auto in = [&](long long x, long long y) {
    return min({x, y, n - x - 1, m - y - 1}) >= 0;
  };
  for (long long i = 0; i < n; i++) {
    q.push(pair<long long, long long>(i, -1));
    q.push(pair<long long, long long>(i, m));
  }
  for (long long j = 0; j < m; j++) {
    q.push(pair<long long, long long>(-1, j));
    q.push(pair<long long, long long>(n, j));
  }
  while (!q.empty()) {
    pair<long long, long long> pre = q.front();
    q.pop();
    long long X = pre.first, Y = pre.second;
    long long dist;
    if (in(X, Y)) {
      dist = d[X][Y];
    } else {
      dist = 0;
    }
    for (long long k = 0; k < 8; k++) {
      long long x = X + dx[k], y = Y + dy[k];
      if (in(x, y) && !v[x][y]) {
        v[x][y] = 1;
        d[x][y] = dist + 1;
        q.push(pair<long long, long long>(x, y));
      }
    }
  }
  long long ans = 0;
  vector<pair<long long, pair<long long, long long> > > ar;
  long long posa = 0;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (arr[i][j] == 'X') {
        ar.push_back(pair<long long, pair<long long, long long> >(
            d[i][j], pair<long long, long long>(i, j)));
        ans = max(ans, d[i][j]);
        posa++;
      }
    }
  }
  long long l = 0, r = ans;
  ans = 0;
  while (l <= r) {
    long long mid = (l + r) / 2;
    long long POSA = posa;
    queue<pair<long long, long long> > q;
    memset(v, 0, sizeof v);
    long long dis[n][m];
    memset(dis, 0, sizeof dis);
    for (auto x : ar) {
      if (x.first > mid) {
        v[x.second.first][x.second.second] = 1;
        q.push(pair<long long, long long>(x.second.first, x.second.second));
        POSA--;
      }
    }
    while (!q.empty()) {
      pair<long long, long long> pre = q.front();
      q.pop();
      long long X = pre.first, Y = pre.second;
      long long dist = dis[X][Y];
      if (dist == mid) {
        continue;
      }
      for (long long k = 0; k < 8; k++) {
        long long x = X + dx[k], y = Y + dy[k];
        if (in(x, y) && !v[x][y] && arr[x][y] == 'X') {
          v[x][y] = 1;
          POSA--;
          dis[x][y] = dist + 1;
          q.push(pair<long long, long long>(x, y));
        }
      }
    }
    if (POSA == 0) {
      l = mid + 1;
      ans = max(ans, mid);
    } else {
      r = mid - 1;
    }
  }
  cout << ans << "\n";
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (d[i][j] > ans) {
        cout << "X";
      } else {
        cout << ".";
      }
    }
    cout << "\n";
  }
}
