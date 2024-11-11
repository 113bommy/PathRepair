#include <bits/stdc++.h>
int grid[100][100];
int main() {
  int rows, cols;
  scanf("%d %d", &rows, &cols);
  int rows_min[100];
  int cols_min[100];
  std::fill(rows_min, rows_min + rows, 500);
  std::fill(cols_min, cols_min + cols, 500);
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      scanf("%d", &grid[i][j]);
      rows_min[i] = std::min(grid[i][j], rows_min[i]);
      cols_min[j] = std::min(grid[i][j], cols_min[j]);
    }
  }
  std::vector<std::string> v;
  if (cols > rows) {
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < rows_min[i]; ++j)
        v.emplace_back("row " + std::to_string(i + 1));
      for (int j = 0; j < cols; ++j) {
        grid[i][j] -= rows_min[i];
        cols_min[j] = std::min(grid[i][j], cols_min[j]);
      }
      rows_min[i] = 0;
    }
    for (int j = 0; j < cols; ++j) {
      for (int i = 0; i < cols_min[j]; ++i)
        v.emplace_back("col " + std::to_string(j + 1));
      for (int i = 0; i < rows; ++i) {
        grid[i][j] -= cols_min[j];
        rows_min[i] = std::min(grid[i][j], rows_min[i]);
      }
      cols_min[j] = 0;
    }
  } else {
    for (int j = 0; j < cols; ++j) {
      for (int i = 0; i < cols_min[j]; ++i)
        v.emplace_back("col " + std::to_string(j + 1));
      for (int i = 0; i < rows; ++i) {
        grid[i][j] -= cols_min[j];
        rows_min[i] = std::min(grid[i][j], rows_min[i]);
      }
      cols_min[j] = 0;
    }
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < rows_min[i]; ++j)
        v.emplace_back("row " + std::to_string(i + 1));
      for (int j = 0; j < cols; ++j) {
        grid[i][j] -= rows_min[i];
        cols_min[j] = std::min(grid[i][j], cols_min[j]);
      }
      rows_min[i] = 0;
    }
  }
  bool ok = true;
  for (int i = 0; i < rows * cols; ++i) {
    if (grid[i / cols][i % rows]) {
      ok = false;
      break;
    }
  }
  if (!ok) {
    printf("-1\n");
  } else {
    printf("%zu\n", v.size());
    std::for_each(v.begin(), v.end(),
                  [](const std::string &s) { printf("%s\n", s.c_str()); });
  }
  return 0;
}
