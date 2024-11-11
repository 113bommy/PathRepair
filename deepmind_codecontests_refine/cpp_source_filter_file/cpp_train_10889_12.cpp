#include <bits/stdc++.h>
using namespace std;
int main() {
  int row, col;
  scanf("%d %d", &row, &col);
  vector<vector<int> > grid(row);
  for (vector<vector<int> >::iterator it = grid.begin(); it != grid.end();
       it++) {
    *it = vector<int>(col);
    for (vector<int>::iterator it2 = it->begin(); it2 != it->end(); it2++) {
      scanf("%d", &(*it2));
    }
  }
  int res = 0;
  vector<pair<string, int> > how;
  if (row >= col) {
    for (int r = 0; r < row; r++) {
      int minv = 987654321;
      for (int c = 0; c < col; c++) {
        minv = min(minv, grid[r][c]);
      }
      if (minv > 0) {
        for (int i = 0; i < minv; i++) {
          how.push_back(make_pair("row", r));
        }
        for (int c = 0; c < col; c++) {
          grid[r][c] -= minv;
        }
        res += minv;
      }
    }
    for (int c = 0; c < col; c++) {
      int minv = 987654321;
      for (int r = 0; r < row; r++) {
        minv = min(minv, grid[r][c]);
      }
      if (minv > 0) {
        for (int i = 0; i < minv; i++) {
          how.push_back(make_pair("col", c));
        }
        for (int r = 0; r < row; r++) {
          grid[r][c] -= minv;
        }
        res += minv;
      }
    }
  } else {
    for (int c = 0; c < col; c++) {
      int minv = 987654321;
      for (int r = 0; r < row; r++) {
        minv = min(minv, grid[r][c]);
      }
      if (minv > 0) {
        for (int i = 0; i < minv; i++) {
          how.push_back(make_pair("col", c));
        }
        for (int r = 0; r < row; r++) {
          grid[r][c] -= minv;
        }
        res += minv;
      }
    }
    for (int r = 0; r < row; r++) {
      int minv = 987654321;
      for (int c = 0; c < col; c++) {
        minv = min(minv, grid[r][c]);
      }
      if (minv > 0) {
        for (int i = 0; i < minv; i++) {
          how.push_back(make_pair("row", r));
        }
        for (int c = 0; c < col; c++) {
          grid[r][c] -= minv;
        }
        res += minv;
      }
    }
  }
  bool is_complete = true;
  for (int r = 0; r < row; r++) {
    for (int c = 0; c < col; c++) {
      if (grid[r][c] != 0) {
        is_complete = false;
        break;
      }
    }
  }
  if (is_complete) {
    printf("%d\n", res);
    for (vector<pair<string, int> >::iterator it = how.begin(); it != how.end();
         it++) {
      printf("%s %d\n", it->first.c_str(), it->second + 1);
    }
  } else {
    printf("-1\n");
  }
  return 0;
}
