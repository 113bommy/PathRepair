#include <bits/stdc++.h>
using namespace std;
int rows, cols;
bool mat[1000][1000];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> rows >> cols;
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      cin >> mat[r][c];
    }
  }
  int ans = 0;
  for (int r = 0; r < rows; r++) {
    bool one = false;
    for (int c = 0; c < cols; c++) {
      if (mat[r][c]) one = true;
      if (!mat[r][c] && one) ans++;
    }
    one = false;
    for (int c = cols - 1; c > -1; c--) {
      if (mat[r][c]) one = true;
      if (!mat[r][c] && one) ans++;
    }
  }
  for (int c = 0; c < cols; c++) {
    bool one = false;
    for (int r = 0; r < rows; r++) {
      if (mat[r][c]) one = true;
      if (!mat[r][c] && one) ans++;
    }
    one = false;
    for (int r = rows; r > -1; r--) {
      if (mat[r][c]) one = true;
      if (!mat[r][c] && one) ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}
