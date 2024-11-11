#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
const int MOD = 1e9 + 7;
const int MB = 20;
void solve() {
  int n, m, k, s;
  cin >> n >> m >> k >> s;
  vector<vector<pair<int, int>>> a(k, vector<pair<int, int>>(n, {INF, -INF}));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      a[x - 1][i].first = min(a[x - 1][i].first, j);
      a[x - 1][i].second = max(a[x - 1][i].second, j);
    }
  }
  vector<vector<int>> d(k, vector<int>(k));
  for (int i = 0; i < k; i++) {
    for (int j = i; j < k; j++) {
      for (int c = 0; c < n; c++) {
        if (a[i][c].first == INF) continue;
        for (int q = 0; q < n; q++) {
          if (a[j][q].first == INF) continue;
          d[i][j] = d[j][i] = max(
              d[i][j], abs(c - q) + max(abs(a[i][c].first - a[j][q].second),
                                        abs(a[i][c].second - a[j][q].first)));
        }
      }
    }
  }
  int ans = 0;
  vector<int> b(s);
  for (int i = 0; i < s; i++) {
    cin >> b[i];
    b[i]--;
  }
  for (int i = 1; i < s - 1; i++) {
    ans = max(ans, d[b[i]][b[i - 1]]);
  }
  cout << ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed;
  cout.precision(12);
  solve();
}
