#include <bits/stdc++.h>
using namespace std;
const double pi = 3.141592653589793;
const double epsilon = 1e-6;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> v(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> v[i][j];
    }
  }
  bool m;
  int MAX = -1;
  for (int i = 0, _i = n; i < _i; ++i) {
    MAX = -1;
    for (int j = 0, _j = n; j < _j; ++j) {
      if (v[j][i] > MAX) {
        MAX = v[j][i];
      }
    }
    if (MAX == n - 1) {
      if (!m) {
        m = true;
      } else {
        cout << n << " ";
        continue;
      }
    }
    cout << MAX << " ";
  }
}
