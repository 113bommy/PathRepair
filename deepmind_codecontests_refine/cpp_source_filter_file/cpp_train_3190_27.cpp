#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  vector<vector<char>> field(9, vector<char>(9));
  for (int64_t i = 0; i < 9; i++) {
    for (int64_t j = 0; j < 9; j++) cin >> field[i][j];
  }
  int64_t x, y;
  cin >> x >> y;
  x--;
  y--;
  x %= 3;
  y %= 3;
  bool free = false;
  for (int64_t i = y * 3; i < (y + 1) * 3; i++) {
    for (int64_t j = x * 3; j < (x + 1) * 3; j++) {
      if (field[i][j] == '.') {
        field[i][j] = '!';
        free = true;
      }
    }
  }
  if (!free) {
    for (auto &v : field) {
      for (auto &i : v) {
        if (i == '.') i = '!';
      }
    }
  }
  for (int64_t i = 0; i < 9; i++) {
    for (int64_t j = 0; j < 9; j++) {
      cout << field[i][j];
      if (j == 2 || j == 5) cout << " ";
    }
    if (i == 2 || i == 5) {
      cout << "\n";
    }
    cout << "\n";
  }
  cout << "\n";
}
