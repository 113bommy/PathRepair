#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int grid[150][150];
pair<int, int> ind[150][150];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  map<int, int> cntr, cntc;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      ind[i][j] = {i, j};
    }
  }
  for (int i = 0; i < (int)(q); ++i) {
    int t;
    cin >> t;
    if (t == 1) {
      int r;
      cin >> r;
      pair<int, int> first = ind[r][1];
      for (int j = 1; j < m; j++) {
        ind[r][j] = ind[r][j + 1];
      }
      ind[r][m] = first;
    } else if (t == 2) {
      int c;
      cin >> c;
      pair<int, int> first = ind[1][c];
      for (int j = 1; j < n; j++) {
        ind[j][c] = ind[j + 1][c];
      }
      ind[n][c] = first;
    } else {
      int r, c, el;
      cin >> r >> c >> el;
      grid[ind[r][c].first][ind[r][c].second] = el;
    }
  }
  for (int i = 1; i <= (int)(n); ++i) {
    for (int j = 1; j <= (int)(n); ++j) cout << grid[i][j] << ' ';
    cout << '\n';
  }
  return 0;
}
