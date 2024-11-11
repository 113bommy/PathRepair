#include <bits/stdc++.h>
using namespace std;
char grid[100][100];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  bool Unique = true;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> grid[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      Unique = true;
      for (int col = 0; col < m; col++) {
        if (col == j)
          continue;
        else if (grid[i][j] == grid[i][col])
          Unique = false;
      }
      for (int row = 0; row < n; row++) {
        if (row == i)
          continue;
        else if (grid[i][j] == grid[row][j])
          Unique = false;
      }
      if (Unique) {
        cout << grid[i][j];
      }
    }
}
