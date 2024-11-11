#include <bits/stdc++.h>
using namespace std;
int x[105][105];
vector<pair<int, int>> ans;
void solve(int i, int j) {
  if (x[i][j] + x[i + 1][j] + x[i][j + 1] + x[i + 1][j + 1] == 0) return;
  if (x[i][j] + x[i + 1][j] + x[i][j + 1] + x[i + 1][j + 1] == 4) {
    ans.push_back({i, j}), ans.push_back({i + 1, j}), ans.push_back({i, j + 1});
    x[i][j] = 0, x[i + 1][j] = 0, x[i][j + 1] = 0;
  }
  if (x[i][j] + x[i + 1][j] + x[i][j + 1] + x[i + 1][j + 1] == 1) {
    int cnt = 0;
    for (int ii = 0; ii < 2; ii++) {
      for (int jj = 0; jj < 2; jj++) {
        if (x[i + ii][j + jj] == 1) {
          x[i + ii][j + jj] = 0;
          ans.push_back({i + ii, j + jj});
        } else if (cnt < 2) {
          cnt++;
          x[i + ii][j + jj] = 1;
          ans.push_back({i + ii, j + jj});
        }
      }
    }
  }
  if (x[i][j] + x[i + 1][j] + x[i][j + 1] + x[i + 1][j + 1] == 2) {
    int cnt = 0;
    for (int ii = 0; ii < 2; ii++) {
      for (int jj = 0; jj < 2; jj++) {
        if (x[i + ii][j + jj] == 0) {
          x[i + ii][j + jj] = 1;
          ans.push_back({i + ii, j + jj});
        } else if (!cnt) {
          cnt++;
          x[i + ii][j + jj] = 0;
          ans.push_back({i + ii, j + jj});
        }
      }
    }
  }
  if (x[i][j] + x[i + 1][j] + x[i][j + 1] + x[i + 1][j + 1] == 3) {
    if (x[i][j] == 1) ans.push_back({i, j});
    if (x[i + 1][j] == 1) ans.push_back({i + 1, j});
    if (x[i][j + 1] == 1) ans.push_back({i, j + 1});
    if (x[i + 1][j + 1] == 1) ans.push_back({i + 1, j + 1});
    x[i][j] = 0, x[i + 1][j] = 0, x[i][j + 1] = 0, x[i + 1][j + 1] = 0;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ans.clear();
    int n, m;
    cin >> n >> m;
    string s[n];
    for (int i = 0; i < n; i++) {
      cin >> s[i];
      for (int j = 0; j < m; j++) x[i][j] = s[i][j] - '0';
    }
    for (int i = 0; i < n - 2; i++) {
      for (int j = 0; j < m; j++) {
        if (x[i][j] == 1) {
          x[i][j] = 0;
          if (j == m - 1) {
            ans.push_back({i, j});
            ans.push_back({i + 1, j});
            ans.push_back({i + 1, j - 1});
            x[i][j] ^= 1;
            x[i + 1][j] ^= 1;
            x[i + 1][j - 1] ^= 1;
          } else {
            ans.push_back({i, j});
            ans.push_back({i + 1, j});
            ans.push_back({i + 1, j + 1});
            x[i][j] ^= 1;
            x[i + 1][j] ^= 1;
            x[i + 1][j + 1] ^= 1;
          }
        }
      }
    }
    for (int i = 0; i < m - 2; i++) {
      vector<pair<int, int>> tp;
      if (x[n - 2][i] + x[n - 1][i] == 0) continue;
      if (x[n - 2][i]) tp.push_back({n - 2, i});
      if (x[n - 1][i]) tp.push_back({n - 1, i});
      tp.push_back({n - 2, i + 1});
      x[n - 2][i + 1] ^= 1;
      if (tp.size() < 3) tp.push_back({n - 2, i + 1}), x[n - 2][i + 1] ^= 1;
      for (auto i : tp) ans.push_back(i);
    }
    solve(n - 2, m - 2);
    cout << ans.size() / 3 << '\n';
    int cnt = 0;
    for (auto j : ans) {
      cnt++;
      cout << j.first + 1 << ' ' << j.second + 1 << ' ';
      if (cnt % 3 == 0) cout << '\n';
    }
  }
}
