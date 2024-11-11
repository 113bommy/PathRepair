#include <bits/stdc++.h>
using std::vector;
using Participant = vector<int>;
using Table = vector<Participant>;
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  size_t n;
  std::cin >> n;
  vector<size_t> solved(5, 0);
  vector<size_t> cost(5, 0);
  vector<size_t> score(2, 0);
  Table table(n);
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < 5; ++j) {
      int x;
      std::cin >> x;
      table[i].push_back(x);
      if (x != 1) {
        ++solved[j];
      }
    }
  }
  for (size_t new_accs = 0; new_accs < 31 * n + 1; ++new_accs) {
    for (size_t j = 0; j < 5; ++j) {
      size_t overall = n + new_accs;
      size_t cur = solved[j];
      if (table[0][j] != -1 && table[1][j] != -1 && table[0][j] > table[1][j]) {
        cur += new_accs;
      }
      cost[j] = 500;
      while (cost[j] < 3000 && 2 * cur <= overall) {
        cur *= 2;
        cost[j] += 500;
      }
    }
    for (size_t i = 0; i < 2; ++i) {
      score[i] = 0;
      for (size_t j = 0; j < 5; ++j) {
        if (table[i][j] != -1) {
          score[i] += cost[j] / 250 * (250 - table[i][j]);
        }
      }
    }
    if (score[0] > score[1]) {
      std::cout << new_accs;
      return 0;
    }
  }
  std::cout << -1;
  return 0;
}
