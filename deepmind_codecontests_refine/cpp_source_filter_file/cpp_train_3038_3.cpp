#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e5 + 7;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int grid[n][n];
  int x = 0;
  for (int i = 0; i < n; i += 2) {
    for (int j = 0; j < n; j += 2) {
      if ((i / 2 + j / 2) % 2) {
        grid[i][j] = x;
        grid[i][j + 1] = x + 1;
        grid[i + 1][j] = x + 2;
        grid[i + 1][j + 1] = x + 3;
      } else {
        grid[i][j] = x;
        grid[i][j + 1] = x + 2;
        grid[i + 1][j] = x + 3;
        grid[i + 1][j + 1] = x + 1;
      }
      x += 4;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
