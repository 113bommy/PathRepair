#include <bits/stdc++.h>
int main() {
  std::vector<std::vector<char>> board(9, std::vector<char>(9));
  for (int i = 1; i <= 8; ++i) {
    for (int j = 1; j <= 8; ++j) {
      std::cin >> board[i][j];
    }
  }
  int b_best = 99, w_best = 99;
  for (int i = 1; i <= 8; ++i) {
    int has_b = 0, has_w = 0;
    for (int j = 1; j <= 8 && !has_w; ++j) {
      if (board[j][i] == 'B') break;
      if (board[j][i] == 'W') has_w = j - 1;
    }
    for (int j = 8; j >= 1 && !has_b; --j) {
      if (board[j][i] == 'W') break;
      if (board[j][i] == 'B') has_b = 8 - j;
    }
    if (has_b) b_best = std::min(b_best, has_b);
    if (has_w) w_best = std::min(w_best, has_w);
  }
  std::cout << (w_best <= b_best ? 'A' : 'B') << std::endl;
}
