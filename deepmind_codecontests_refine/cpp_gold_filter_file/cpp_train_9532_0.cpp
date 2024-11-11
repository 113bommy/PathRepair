#include <bits/stdc++.h>
using ll = int64_t;
constexpr static int kMaxLog = 18;
constexpr static ll kInf = 1e18;
class TaskE {
 public:
  int sum, n;
  std::vector<int> coins;
  void solve(std::istream& in, std::ostream& out) {
    in >> sum >> n;
    coins.resize(n);
    for (int i = 0; i < n; i++) in >> coins[i];
    std::sort(coins.begin(), coins.end());
    std::reverse(coins.begin(), coins.end());
    std::vector<int> skip_cursor(sum + 1, -1);
    std::vector<std::vector<ll>> sums(kMaxLog, std::vector<ll>(n, kInf));
    for (int i = n - 1; i >= 0; i--) {
      sums[0][i] = coins[i];
      for (int bit = 1; bit <= kMaxLog; bit++) {
        if (i + (1 << bit) <= n) {
          sums[bit][i] = sums[bit - 1][i] + sums[bit - 1][i + (1 << (bit - 1))];
        }
      }
    }
    int cursor = 0;
    for (int i = sum; i >= 0; i--) {
      while (cursor < n && coins[cursor] > i) {
        ++cursor;
      }
      skip_cursor[i] = cursor;
    }
    auto jump = [&](int remains, int cursor) {
      int target_sum = remains - coins[cursor];
      if (target_sum <= coins[cursor]) {
        return std::pair<int, int>{remains - coins[cursor], cursor + 1};
      }
      int addition = 0;
      int taken = 0;
      for (int bit = kMaxLog - 1; bit >= 0; bit--) {
        if (cursor + addition + (1 << bit) <= n &&
            taken + sums[bit][cursor + addition] <= target_sum) {
          taken += sums[bit][cursor + addition];
          addition += (1 << bit);
        }
      }
      assert(taken > 0 && addition > 0);
      return std::pair<int, int>{remains - taken, cursor + addition};
    };
    auto check = [&](int remains, int special_coin) {
      bool used = false;
      int cursor = 0;
      while (true) {
        if (cursor < n && coins[cursor] > remains) {
          cursor = skip_cursor[remains];
        }
        bool can_coin = cursor < n;
        bool can_special_coin = !used && special_coin <= remains;
        if (can_coin || can_special_coin) {
          if (can_special_coin && can_coin) {
            if (special_coin >= coins[cursor]) {
              used = true;
              remains -= special_coin;
            } else {
              auto new_state = jump(remains, cursor);
              remains = new_state.first;
              cursor = new_state.second;
            }
          } else if (can_special_coin) {
            used = true;
            remains -= special_coin;
          } else {
            auto new_state = jump(remains, cursor);
            remains = new_state.first;
            cursor = new_state.second;
          }
        } else {
          break;
        }
      }
      return remains != 0;
    };
    for (int coin = 1; coin < sum; coin++) {
      if (check(sum, coin)) {
        out << coin << "\n";
        return;
      }
    }
    out << "Greed is good"
        << "\n";
  }
};
int main() {
  TaskE solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
