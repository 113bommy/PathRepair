#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long c[3][n];
  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < n; i++) {
      cin >> c[j][i];
    }
  }
  int v;
  vector<vector<int> > g(n + 1);
  int t1, t2;
  for (int i = 0; i < n - 1; i++) {
    cin >> t1 >> t2;
    g[t1].push_back(t2);
    g[t2].push_back(t1);
    if (g[t1].size() == 3 || g[t2].size() == 3) {
      cout << -1;
      return 0;
    }
  }
  for (int i = 0; i < n - 1; i++) {
    if (g[i].size() == 1) {
      v = 1;
      break;
    }
  }
  long long ans[6] = {0, 0, 0, 0, 0, 0};
  vector<vector<int> > col(6, vector<int>(n + 1));
  int cv = v;
  int p = -1;
  for (int i = 0; i < n; i++) {
    if (i % 3 == 0) {
      ans[0] += c[0][cv - 1];
      ans[1] += c[0][cv - 1];
      ans[2] += c[1][cv - 1];
      ans[3] += c[2][cv - 1];
      ans[4] += c[1][cv - 1];
      ans[5] += c[2][cv - 1];
      col[0][cv - 1] = 1;
      col[1][cv - 1] = 1;
      col[2][cv - 1] = 2;
      col[3][cv - 1] = 3;
      col[4][cv - 1] = 2;
      col[5][cv - 1] = 3;
    }
    if (i % 3 == 1) {
      ans[0] += c[1][cv - 1];
      ans[1] += c[2][cv - 1];
      ans[2] += c[0][cv - 1];
      ans[3] += c[0][cv - 1];
      ans[4] += c[2][cv - 1];
      ans[5] += c[1][cv - 1];
      col[0][cv - 1] = 2;
      col[1][cv - 1] = 3;
      col[2][cv - 1] = 1;
      col[3][cv - 1] = 1;
      col[4][cv - 1] = 3;
      col[5][cv - 1] = 2;
    }
    if (i % 3 == 2) {
      ans[0] += c[2][cv - 1];
      ans[1] += c[1][cv - 1];
      ans[2] += c[2][cv - 1];
      ans[3] += c[1][cv - 1];
      ans[4] += c[0][cv - 1];
      ans[5] += c[0][cv - 1];
      col[0][cv - 1] = 3;
      col[1][cv - 1] = 2;
      col[2][cv - 1] = 3;
      col[3][cv - 1] = 2;
      col[4][cv - 1] = 1;
      col[5][cv - 1] = 1;
    }
    for (int j = 0; j < g[cv].size(); j++) {
      if (g[cv][j] != p) {
        p = cv;
        cv = g[cv][j];
        break;
      }
    }
  }
  int ind = 0;
  long long mx = (long long)1000000000000000;
  for (int i = 0; i < 6; i++) {
    if (mx > ans[i]) {
      mx = ans[i];
      ind = i;
    }
  }
  cout << ans[ind] << "\n";
  for (int i = 0; i < n; i++) {
    cout << col[ind][i] << " ";
  }
  return 0;
}
