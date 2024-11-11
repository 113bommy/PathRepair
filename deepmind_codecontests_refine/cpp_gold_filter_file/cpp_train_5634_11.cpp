#include <bits/stdc++.h>
using namespace std;
int a[1000 + 4][1000 + 4];
bool check(int x, int y) {
  return (a[x][y] & a[x][y + 1] & a[x][y + 2] & a[x + 1][y] & a[x + 1][y + 2] &
          a[x + 2][y] & a[x + 2][y + 1] & a[x + 2][y + 2]) != 0;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char now;
      cin >> now;
      if (now == '#') a[i + 2][j + 2] = 1;
    }
  }
  bool found = false;
  for (int i = 2; i < n + 2; ++i) {
    for (int j = 2; j < m + 2; ++j) {
      if (a[i][j] &&
          !(check(i, j) || check(i, j - 1) || check(i, j - 2) ||
            check(i - 1, j) || check(i - 2, j) || check(i - 2, j - 1) ||
            check(i - 1, j - 2) || check(i - 2, j - 2))) {
        found = true;
      }
    }
  }
  if (found)
    cout << "NO\n";
  else
    cout << "YES\n";
  return 0;
}
