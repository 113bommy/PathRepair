#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:128000000")
using namespace std;
void solve();
int main() {
  string s = "";
  cin.tie(0);
  cout.sync_with_stdio(0);
  cout.precision(10);
  cout << fixed;
  int t = 1;
  for (int i = 1; i <= t; ++i) {
    solve();
  }
  return 0;
}
void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int> > a(n, vector<int>(m));
  vector<int> results(n * m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      a[i][j] = i * m + j;
    }
  }
  for (int i = 0; i < q; ++i) {
    int t;
    cin >> t;
    int r, c, x;
    if (t == 1) {
      cin >> r;
      --r;
      int start = a[r][0];
      for (int j = 1; j < m; ++j) {
        a[r][j - 1] = a[r][j];
      }
      a[r][m - 1] = start;
    }
    if (t == 2) {
      cin >> c;
      --c;
      int start = a[0][c];
      for (int j = 1; j < n; ++j) {
        a[j - 1][c] = a[j][c];
      }
      a[n - 1][c] = start;
    }
    if (t == 3) {
      cin >> r >> c >> x;
      --r;
      --c;
      results[a[r][c]] = x;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << results[i * m + j] << " ";
    }
    cout << "\n";
  }
}
