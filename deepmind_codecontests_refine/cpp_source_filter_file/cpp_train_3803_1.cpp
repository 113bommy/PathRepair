#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<pair<int, pair<int, int> > > > a(
      n, vector<pair<int, pair<int, int> > >(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      a[i][j].second.first = i;
      a[i][j].second.second = j;
    }
  }
  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int r;
      cin >> r;
      r--;
      auto temp = a[0][r];
      for (int j = 0; j < m - 1; j++) {
        a[r][j] = a[r][j + 1];
      }
      a[r][m - 1] = temp;
    }
    if (t == 2) {
      int c;
      cin >> c;
      c--;
      auto temp = a[0][c];
      for (int j = 0; j < n - 1; j++) {
        a[j][c] = a[j + 1][c];
      }
      a[n - 1][c] = temp;
    }
    if (t == 3) {
      int r, c, x;
      cin >> r >> c >> x;
      r--, c--;
      a[r][c].first = x;
    }
  }
  vector<vector<int> > ans(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ans[a[i][j].second.first][a[i][j].second.second] = a[i][j].first;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
