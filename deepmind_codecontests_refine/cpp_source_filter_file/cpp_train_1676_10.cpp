#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20000;
int n, m, p;
int xs[MAXN], ys[MAXN];
struct Cell {
  int r, c;
  long long int score;
};
vector<Cell> diagonal;
int inline prize(int c, int s) { return (xs[c] + ys[s]) % p; }
long long int score_memo[MAXN];
void DP_above() {
  memset(score_memo, 0, sizeof score_memo);
  int last_r = diagonal.back().r - 1;
  for (int r = 0; r <= last_r; ++r) {
    for (int c = 0; c <= m - 1; ++c) {
      score_memo[c] =
          prize(r, c) +
          (c > 0 ? max(score_memo[c - 1], score_memo[c]) : score_memo[c]);
    }
  }
  for (int i = diagonal.size() - 1; i >= 0; --i) {
    Cell& cell = diagonal[i];
    int r = cell.r;
    int last_c = cell.c;
    for (int c = 0; c <= last_c; ++c) {
      score_memo[c] =
          prize(r, c) +
          (c > 0 ? max(score_memo[c - 1], score_memo[c]) : score_memo[c]);
    }
    cell.score += score_memo[last_c];
  }
}
void DP_below() {
  memset(score_memo, 0, sizeof score_memo);
  int first_r = diagonal.front().r + 1;
  for (int r = n - 1; r >= first_r; --r) {
    for (int c = m - 1; c >= 0; --c) {
      score_memo[c] =
          prize(r, c) +
          (c < m - 1 ? max(score_memo[c + 1], score_memo[c]) : score_memo[c]);
    }
  }
  for (Cell& cell : diagonal) {
    int r = cell.r;
    int first_c = cell.c;
    for (int c = m - 1; c >= first_c; --c) {
      score_memo[c] =
          prize(r, c) +
          (c < m - 1 ? max(score_memo[c + 1], score_memo[c]) : score_memo[c]);
    }
    cell.score += score_memo[first_c];
  }
}
void find_optimal_path(int r_offset, int c_offset, int height, int width,
                       vector<char>& path) {
  static bitset<6300000> bits;
  bits.reset();
  memset(score_memo, 0, sizeof score_memo);
  for (int r = height - 1; r >= 0; --r) {
    for (int c = width - 1; c >= 0; --c) {
      int score = prize(r_offset + r, c_offset + c);
      bool right = false;
      if (c < width - 1) {
        if (score_memo[c + 1] >= score_memo[c]) {
          right = true;
          score += score_memo[c + 1];
        } else {
          score += score_memo[c];
        }
      } else {
        score += score_memo[c];
      }
      if (right) bits.set(r * width + c);
      score_memo[c] = score;
    }
  }
  int r = 0, c = 0;
  int tr = height - 1, tc = width - 1;
  while (r != tr || c != tc) {
    if (bits.test(r * width + c)) {
      path.push_back('S');
      c++;
    } else {
      path.push_back('C');
      r++;
    }
    assert(r <= tr && c <= tc);
  }
}
int main() {
  try {
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 0; i <= n - 1; ++i) scanf("%d", xs + i);
    for (int i = 0; i <= m - 1; ++i) scanf("%d", ys + i);
    int steps = n + m - 2;
    if (steps == 0) {
      printf("%d\n\n", prize(0, 0));
      return 0;
    }
    int k = steps / 2;
    if (m > k) {
      for (int r = n - 1, c = m - 1 - k; r >= 0 && c < m; r--, c++) {
        diagonal.push_back({r, c, 0});
      }
    } else {
      for (int r = n + m - 2 - k, c = 0; r >= 0 && c < m; r--, c++) {
        diagonal.push_back({r, c, 0});
      }
    }
    long long int max_score = -1;
    Cell best_cell;
    DP_above();
    DP_below();
    for (Cell& cell : diagonal) {
      long long int score = cell.score - prize(cell.r, cell.c);
      if (max_score < score) {
        max_score = score;
        best_cell = cell;
      }
    }
    vector<char> optimal_path;
    find_optimal_path(0, 0, best_cell.r + 1, best_cell.c + 1, optimal_path);
    find_optimal_path(best_cell.r, best_cell.c, n - best_cell.r,
                      m - best_cell.c, optimal_path);
    printf("%lld\n", max_score);
    for (char c : optimal_path) putchar(c);
    puts("");
  } catch (const std::exception& ex) {
    printf(ex.what());
  }
  return 0;
}
