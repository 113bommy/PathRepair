#include <bits/stdc++.h>
using namespace std;
template <typename G1, typename G2 = G1, typename G3 = G1>
struct triple {
  G1 first;
  G2 second;
  G3 T;
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> v(n, vector<int>(n + 1));
  for (int i = 0; i < n; i++)
    for (int j = 1; j <= n; j++) cin >> v[i][j], v[i][j] += v[i][j - 1];
  const int oo = -1e9;
  vector<vector<int>> cur(n, vector<int>(n, oo));
  vector<vector<int>> next(n, vector<int>(n, oo));
  vector<vector<int>> temp1(n, vector<int>(n, oo));
  vector<vector<int>> temp2(n, vector<int>(n, oo));
  for (int i = 0; i < n; i++)
    for (int j = i; j < n; j++) cur[i][j] = v[0][j + 1];
  for (int k = 1; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cur[i][j] -= v[k][i];
        temp1[i][j] = cur[i][j];
        if (i > 0) temp1[i][j] = max(temp1[i][j], temp1[i - 1][j]);
        if (j > 0) temp1[i][j] = max(temp1[i][j], temp1[i][j - 1]);
      }
      for (int j = i; j < n; j++) next[i][j] = temp1[i][i] + v[k][j + 1];
      for (int j = 0; j < n; j++) {
        cur[i][j] -= v[k][j];
        temp2[i][j] = cur[i][j];
        if (i > 0) temp2[i][j] = max(temp2[i][j], temp2[i - 1][j]);
      }
      int mx = oo;
      for (int j = i + 1; j < n; j++)
        mx = max(mx, temp2[i][j]),
        next[i][j] = max(next[i][j], mx + v[k][i + 1] + v[k][j + 1]);
    }
    swap(cur, next);
  }
  cout << cur[n - 1][n - 1] << '\n';
  return 0;
}
