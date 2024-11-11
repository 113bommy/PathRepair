#include <bits/stdc++.h>
using namespace std;
void solve(int test_case) {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> mat(n, vector<int>(m, 0));
  vector<pair<int, int>> rows(n, {-1, -1}), cols(m, {-1, -1});
  for (int i = 0; i < k; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    --b;
    if (a == 1) {
      rows[b] = {i, c};
    } else {
      cols[b] = {i, c};
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (rows[i].first == -1 && cols[j].first != -1) {
        mat[i][j] = cols[j].second;
      } else if (rows[i].first != -1 && cols[j].first == -1) {
        mat[i][j] = rows[i].second;
      } else if (rows[i].first == -1 && cols[j].first == -1) {
        continue;
      } else {
        mat[i][j] =
            (rows[i].first > cols[j].first ? rows[i].second : cols[j].second);
      }
    }
  }
  for (auto row : mat) {
    for (auto x : row) cout << x << " ";
    cout << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  for (int tc = 1; tc <= t; ++tc) solve(tc);
}
