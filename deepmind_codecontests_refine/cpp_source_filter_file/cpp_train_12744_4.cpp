#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(false);
  int n;
  int m;
  cin >> n;
  cin >> m;
  vector<vector<int>> v(m);
  for (int i = 0; i < m; ++i) v[i].resize(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char c = 0;
      cin >> c;
      if (c == '0') v[j][i] = 0;
      if (c == '1' && j == 0) v[j][i] = 1;
      if (c == '1' && j != 0) v[j][i] = v[j][i - 1] + 1;
    }
  }
  int maximum = 0;
  for (int i = 0; i < m; ++i) {
    sort(v[i].begin(), v[i].end());
    for (int j = 0; j < n; ++j) {
      maximum = max(maximum, v[i][j] * (n - j));
    }
  }
  cout << maximum << endl;
  return 0;
}
