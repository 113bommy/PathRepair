#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  long long qu, p;
  cin >> qu >> p;
  vector<string> fld(n + 2);
  for (int i = 0; i < m + 2; i++) fld[0] += "*";
  for (int i = 0; i < m + 2; i++) fld[n + 1] += "*";
  for (int i = 1; i < n + 1; i++) {
    cin >> fld[i];
    fld[i] = "*" + fld[i] + "*";
  }
  vector<vector<long long>> cnt(n + 2, vector<long long>(m + 2));
  vector<vector<int>> dist(n + 2, vector<int>(m + 2, 1e9));
  vector<pair<int, int>> q((n + 2) * (m + 2));
  vector<pair<int, int>> used((n + 2) * (m + 2));
  auto xx = vector<pair<int, int>>{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  auto bfs = [&](int si, int sj) {
    long long qe = qu * (fld[si][sj] - 'A' + 1);
    q[0] = {si, sj};
    used[0] = {si, sj};
    dist[si][sj] = qe;
    cnt[si][sj] += qe;
    int l = 0, r = 1;
    int ul = 1;
    while (r > l) {
      int i, j;
      tie(i, j) = q[l];
      l++;
      if (dist[i][j] < 2) continue;
      int di, dj;
      for (pair<int, int> first : xx) {
        tie(di, dj) = first;
        int ni = di + i, nj = dj + j;
        if (dist[ni][nj] == 1e9 && fld[ni][nj] != '*') {
          dist[ni][nj] = dist[i][j] / 2;
          cnt[ni][nj] += dist[ni][nj];
          used[ul] = {ni, nj};
          q[r] = {ni, nj};
          r++;
          ul++;
        }
      }
    }
    for (; ul > 0; ul--) {
      int di, dj;
      tie(di, dj) = used[ul - 1];
      dist[di][dj] = 1e9;
    }
  };
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < m + 1; j++) {
      if (fld[i][j] == '.' || fld[i][j] == '*') continue;
      bfs(i, j);
    }
  }
  int ans = 0;
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < m + 1; j++) {
      if (cnt[i][j] > p) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
