#include <bits/stdc++.h>
using namespace std;
template <typename T>
using Matrix = vector<vector<T>>;
template <typename T>
Matrix<T> matrix(int R, int C, T x = T()) {
  return Matrix<T>(R, vector<T>(C, x));
}
struct Rectangle {
  int r1, c1, r2, c2;
};
struct SparseTable {
  vector<int> log;
  Matrix<Matrix<int>> data;
  SparseTable(const int R, const int C, Matrix<int> values) {
    log = vector<int>(max(R, C) + 1);
    for (auto i = 2; i <= max(R, C); i++) log[i] = log[i / 2] + 1;
    data =
        matrix<Matrix<int>>(log[R] + 1, log[C] + 1, matrix<int>(R + 1, C + 1));
    for (auto kr = 0; kr <= log[R]; kr++)
      for (auto kc = 0; kc <= log[C]; kc++)
        for (auto r = 1; r + (1 << kr) <= R + 1; r++)
          for (auto c = 1; c + (1 << kc) <= C + 1; c++) {
            auto& x = data[kr][kc][r][c];
            if (kr == 0 && kc == 0)
              x = values[r][c];
            else if (kr == 0)
              x = max(data[0][kc - 1][r][c],
                      data[0][kc - 1][r][c + (1 << (kc - 1))]);
            else if (kc == 0)
              x = max(data[kr - 1][0][r][c],
                      data[kr - 1][0][r + (1 << (kr - 1))][c]);
            else
              x = max({data[kr - 1][kc - 1][r][c],
                       data[kr - 1][kc - 1][r][c + (1 << (kc - 1))],
                       data[kr - 1][kc - 1][r + (1 << (kr - 1))][c],
                       data[kr - 1][kc - 1][r + (1 << (kr - 1))]
                           [c + (1 << (kc - 1))]});
          }
  }
  int query(const Rectangle r) const {
    const auto kr = log[r.r2 - r.r1 + 1];
    const auto kc = log[r.c2 - r.c1 + 1];
    return max({data[kr][kc][r.r1][r.c1],
                data[kr][kc][r.r1][r.c2 - (1 << kc) + 1],
                data[kr][kc][r.r1 - (1 << kr) + 1][r.c2],
                data[kr][kc][r.r1 - (1 << kr) + 1][r.c2 - (1 << kc) + 1]});
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int R, C;
  cin >> R >> C;
  auto grid = matrix<int>(R + 1, C + 1);
  for (auto row = 1; row <= R; row++)
    for (auto column = 1; column <= C; column++) cin >> grid[row][column];
  auto max_square = matrix<int>(R + 1, C + 1);
  for (auto row = 1; row <= R; row++)
    for (auto column = 1; column <= C; column++) {
      if (grid[row][column]) {
        const auto constraints = {max_square[row - 1][column],
                                  max_square[row][column - 1],
                                  max_square[row - 1][column - 1]};
        max_square[row][column] = min(constraints) + 1;
      } else
        max_square[row][column] = 0;
    }
  const auto table = SparseTable(R, C, move(max_square));
  int t;
  cin >> t;
  for (auto i = 0; i < t; i++) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    auto lower_bound = 0, upper_bound = min(r2 - r1 + 1, c2 - c1 + 1);
    while (lower_bound < upper_bound) {
      const auto guess = (lower_bound + upper_bound + 1) / 2;
      if (table.query({r1 + guess - 1, c1 + guess - 1, r2, c2}) >= guess)
        lower_bound = guess;
      else
        upper_bound = guess - 1;
    }
    cout << lower_bound << "\n";
  }
}
