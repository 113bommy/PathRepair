#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int> > a(n, vector<int>(m));
  for (auto &y : a) {
    for (auto &x : y) {
      char c;
      cin >> c;
      if (c == 'W') {
        x = 0;
      } else {
        x = 1;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    int s = -1, f = -1;
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == 1) {
        if (s == -1) {
          s = j;
          f = j;
        } else {
          f = j;
        }
      }
    }
    if (s != -1) {
      int y = (s + f) / 2, x = i + ((f - s) / 2);
      cout << x + 1 << " " << y + 1;
      return 0;
    }
  }
  return 0;
}
