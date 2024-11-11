#include <bits/stdc++.h>
int main() {
  int32_t n;
  std::cin >> n;
  int64_t** field = new int64_t*[n];
  for (int32_t i = 0; i < n; i++) {
    field[i] = new int64_t[n];
  }
  field[0][0] = 0;
  std::pair<int32_t, int32_t> start = {1, 0};
  for (int32_t i = 1; i <= 2 * n - 2; i++) {
    bool boost = false;
    for (int32_t row = start.first; row >= 0; row--, boost = !boost) {
      int32_t col = i - row;
      if (col >= n) break;
      field[row][col] = 1ll << (i - 1 + (boost ? 1 : 0));
    }
    if (start.first < n - 1)
      start.first++;
    else
      start.second++;
  }
  for (int32_t i = 0; i < n; i++) {
    for (int32_t j = 0; j < n; j++) std::cout << field[i][j] << " ";
    std::cout << "\n";
  }
  std::cout << std::endl;
  int32_t num_queries;
  std::cin >> num_queries;
  for (int32_t q = 0; q < num_queries; q++) {
    int64_t sum;
    std::cin >> sum;
    int32_t row = 0, col = 0;
    std::vector<std::pair<int32_t, int32_t> > answer;
    int32_t low_power = 0;
    while (row < n - 1 || col < n - 1) {
      answer.emplace_back(row, col);
      if (col == n - 1)
        row++;
      else {
        if (field[row][col + 1] & (1 << low_power)) {
          if (sum & (1 << low_power)) {
            col++;
          } else {
            row++;
          }
        } else {
          if (sum & (1 << low_power)) {
            row++;
          } else {
            col++;
          }
        }
        sum -= field[row][col];
      }
      low_power++;
    }
    for (int32_t i = 0; i < answer.size(); i++)
      std::cout << answer[i].first + 1 << " " << answer[i].second + 1 << "\n";
    std::cout << n << " " << n << "\n";
    std::cout << std::endl;
  }
  return 0;
}
