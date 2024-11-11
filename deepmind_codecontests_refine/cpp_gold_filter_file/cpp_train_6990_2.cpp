#include <bits/stdc++.h>
using Matrix = std::vector<std::vector<int>>;
void PrintMatrix(const Matrix& m) {
  for (auto& row : m) {
    for (auto& element : row) {
      std::cout << element << ' ';
    }
    std::cout << std::endl;
  }
}
int main() {
  int n;
  int m;
  std::cin >> n >> m;
  Matrix matrix(n);
  for (auto& row : matrix) {
    row.resize(m);
  }
  for (auto& row : matrix) {
    for (auto& element : row) {
      std::cin >> element;
    }
  }
  std::vector<int> indices_in_rows(n, 0);
  int row = 0;
  long xor_ = 0;
  for (int index_in_row : indices_in_rows) {
    xor_ ^= matrix[row][index_in_row];
    ++row;
  }
  if (xor_ > 0) {
    std::cout << "TAK" << std::endl;
    for (auto index : indices_in_rows) {
      std::cout << index + 1 << ' ';
    }
    return 0;
  }
  for (int i = 0; i < matrix.size(); ++i) {
    std::set<int> different_element_in_row;
    for (int j = 0; j < matrix[i].size(); ++j) {
      different_element_in_row.insert(matrix[i][j]);
      if (different_element_in_row.size() > 1) {
        indices_in_rows[i] = j;
        std::cout << "TAK" << std::endl;
        for (auto index : indices_in_rows) {
          std::cout << index + 1 << ' ';
        }
        return 0;
      }
    }
  }
  std::cout << "NIE";
  return 0;
}
