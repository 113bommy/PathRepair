#include <bits/stdc++.h>
const long long T00B1G = 9223372036854775807LL;
const int maskl = 5;
bool mask[64][5];
template <class TEl>
using TTable = std::vector<std::vector<TEl>>;
template <class TEl>
void spacecreator(long long first, long long second, TTable<TEl>& vec) {
  vec.resize(first);
  for (auto& sub : vec) {
    sub.resize(second);
  }
}
template <class T>
void makemask(long long nn, T& mask) {
  long long ulim = 1 << nn;
  for (long long st = 0; st < ulim; st++) {
    for (auto pos = 0; pos < nn; pos++) {
      mask[st][pos] = (st >> pos) & 1;
    }
  }
}
int main() {
  long long nn, mm;
  TTable<long long> dp;
  TTable<long long> left, down;
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cin >> nn >> mm;
  spacecreator(mm + 5, 64, dp);
  spacecreator(maskl, mm + 5, left);
  spacecreator(maskl, mm + 5, down);
  for (auto col = 1; col < mm; col++) {
    for (auto row = 0; row < nn; row++) {
      std::cin >> left[row][col];
    }
  }
  for (auto col = 0; col < mm; col++) {
    for (auto row = 0; row < nn; row++) {
      std::cin >> down[row][col];
    }
  }
  makemask(nn, mask);
  long long ulim = 1 << nn, fix, t1, nx = nn - 1;
  for (auto col = 1; col < mm; col++) {
    for (long long st = 0; st < ulim; st++) {
      fix = 0;
      dp[col][st] = T00B1G;
      for (auto row = 0; row < nn; row++) {
        auto next = row + 1;
        if (row == nx) {
          next = 0;
        }
        if (mask[st][row] ^ mask[st][next]) {
          fix += down[row][col];
        }
      }
      for (long long prev = 0; prev < ulim; prev++) {
        if (col == 1 && prev != 0) {
          break;
        }
        t1 = 0;
        for (auto row = 0; row < nn; row++) {
          if ((mask[st][row] ^ mask[prev][row]) == 1) {
            t1 += left[row][col];
          }
        }
        dp[col][st] = std::min(dp[col][st], dp[col - 1][prev] + t1 + fix);
      }
    }
  }
  std::cout << dp[mm - 1][ulim - 1];
  return 0;
}
