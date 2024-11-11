#include <bits/stdc++.h>
using namespace std;
int main() {
  int rows, cols, r, c, t, ans1 = 0, ans2 = 0;
  vector<int> tmp, rows_vec, cols_vec, rows_vec2, cols_vec2;
  vector<vector<int>> grid;
  scanf("%d %d", &r, &c);
  for (int i = 0; i < r; i++) {
    tmp.clear();
    for (int j = 0; j < c; j++) {
      scanf("%d", &t);
      tmp.push_back(t);
    }
    grid.push_back(tmp);
  }
  for (int i = 0; i < r; i++) {
    int mini = 1000;
    for (int j = 0; j < c; j++) {
      mini = min(mini, grid[i][j]);
    }
    rows_vec.push_back(mini);
    ans1 += mini;
  }
  for (int i = 0; i < c; i++) {
    cols_vec.push_back(grid[0][i] - rows_vec[0]);
    ans1 += (grid[0][i] - rows_vec[0]);
  }
  for (int i = 0; i < c; i++) {
    int mini = 1000;
    for (int j = 0; j < r; j++) {
      mini = min(mini, grid[j][i]);
    }
    cols_vec2.push_back(mini);
    ans2 += mini;
  }
  for (int i = 0; i < r; i++) {
    rows_vec2.push_back(grid[i][0] - cols_vec2[0]);
    ans2 += (grid[i][0] - cols_vec2[0]);
  }
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (grid[i][j] != (rows_vec[i] + cols_vec[j])) {
        cout << -1 << endl;
        return 0;
      }
    }
  }
  if (ans1 <= ans2) {
    cout << ans1 << endl;
    for (int i = 0; i < r; i++) {
      for (int ii = 0; ii < rows_vec[i]; ii++) cout << "row " << i + 1 << endl;
    }
    for (int i = 0; i < c; i++) {
      for (int ii = 0; ii < cols_vec[i]; ii++) cout << "col " << i + 1 << endl;
    }
  } else {
    cout << ans2 << endl;
    for (int i = 0; i < r; i++) {
      for (int ii = 0; ii < rows_vec2[i]; ii++) cout << "row " << i + 1 << endl;
    }
    for (int i = 0; i < c; i++) {
      for (int ii = 0; ii < cols_vec2[i]; ii++) cout << "col " << i + 1 << endl;
    }
  }
  return 0;
}
