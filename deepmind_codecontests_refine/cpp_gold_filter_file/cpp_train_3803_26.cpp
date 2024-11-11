#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000009;
const long long INFL = 1759849216489136867ll;
const double eps = 1e-9;
void solve();
int main() {
  clock_t t_start, t_end;
  solve();
  return 0;
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > matrix(n, vector<int>(m));
  vector<vector<pair<int, int> > > coordinates(n, vector<pair<int, int> >(m));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) coordinates[i][j] = make_pair(i, j);
  int q;
  cin >> q;
  vector<pair<int, int> > buf(n);
  for (int i = 0; i < q; ++i) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int r;
      scanf("%d", &r);
      r--;
      rotate(coordinates[r].begin(), coordinates[r].begin() + 1,
             coordinates[r].end());
    }
    if (t == 2) {
      int c;
      scanf("%d", &c);
      c--;
      for (int j = 0; j < n; ++j) {
        buf[(j - 1 + n) % n] = coordinates[j][c];
      }
      for (int j = 0; j < n; ++j) {
        coordinates[j][c] = buf[j];
      }
    }
    if (t == 3) {
      int r, c, x;
      scanf("%d%d%d", &r, &c, &x);
      r--;
      c--;
      matrix[coordinates[r][c].first][coordinates[r][c].second] = x;
    }
  }
  for (auto &line : matrix) {
    for (auto d : line) cout << d << ' ';
    cout << '\n';
  }
}
