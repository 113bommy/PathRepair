#include <bits/stdc++.h>
using namespace std;
using LL = long long;
void print(vector<vector<int>> mat) {
  for (int i = 0; i < 4; ++i) {
    for (int x : mat[i]) cout << " " << x;
    cout << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> mat(4, vector<int>(n, 0));
  for (int i = 0; i < 4; ++i)
    for (int j = 0; j < n; ++j) cin >> mat[i][j];
  vector<tuple<int, int, int>> ans;
  for (int tst = 0; tst < 2000000 / n; ++tst) {
    for (int i = 0; i < n; ++i)
      if (mat[1][i] == mat[0][i] && mat[1][i] != 0) {
        mat[1][i] = 0;
        ans.push_back(make_tuple(mat[0][i], 1, i + 1));
      }
    for (int i = 0; i < n; ++i)
      if (mat[2][i] == mat[3][i] && mat[2][i] != 0) {
        mat[2][i] = 0;
        ans.push_back(make_tuple(mat[3][i], 4, i + 1));
      }
    for (int i = 0; i < n - 1; ++i) {
      if (mat[1][i] == 0 && mat[1][i + 1] > 0) {
        mat[1][i] = mat[1][i + 1];
        mat[1][i + 1] = 0;
        ans.push_back(make_tuple(mat[1][i], 2, i + 1));
      }
    }
    if (mat[1][n - 1] == 0 && mat[2][n - 1] > 0) {
      mat[1][n - 1] = mat[2][n - 1];
      mat[2][n - 1] = 0;
      ans.push_back(make_tuple(mat[1][n - 1], 2, n));
    }
    for (int i = n - 1; i > 0; --i) {
      if (mat[2][i] == 0 && mat[2][i - 1] > 0) {
        mat[2][i] = mat[2][i - 1];
        mat[2][i - 1] = 0;
        ans.push_back(make_tuple(mat[2][i], 3, i + 1));
      }
    }
    if (mat[2][0] == 0 && mat[1][0] > 0 && (tst / n) % 2 == 0) {
      mat[2][0] = mat[1][0];
      mat[1][0] = 0;
      ans.push_back(make_tuple(mat[2][0], 3, n));
    }
  }
  if (ans.size() > 0) {
    cout << ans.size() << '\n';
    for (auto p : ans)
      cout << get<0>(p) << ' ' << get<1>(p) << ' ' << get<2>(p) << '\n';
  } else
    cout << -1;
}
