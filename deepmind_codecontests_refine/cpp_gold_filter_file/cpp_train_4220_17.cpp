#include <bits/stdc++.h>
struct Edge {
  int from, to, cost;
  Edge() {}
  Edge(int from, int to, int cost) : from(from), to(to), cost(cost) {}
};
const long long INF = 1000000000000000;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  int nn, mm;
  std::cin >> nn >> mm;
  std::vector<long long> dp(1 << nn, INF);
  dp[0] = 0;
  std::vector<std::vector<long long>> horiz(mm - 1, std::vector<long long>(nn));
  std::vector<std::vector<long long>> vert(mm, std::vector<long long>(nn));
  for (int i = 0; i < mm - 1; ++i) {
    for (int j = 0; j < nn; ++j) {
      std::cin >> horiz[i][j];
    }
  }
  for (int i = 0; i < mm; ++i) {
    for (int j = 0; j < nn; ++j) {
      std::cin >> vert[i][j];
    }
  }
  for (int ii = 0; ii < mm - 1; ++ii) {
    for (int mask = 0; mask < (1 << nn); ++mask) {
      for (int jj = 0; jj < nn; ++jj) {
        if (dp[mask] == INF) {
          continue;
        }
        auto with = (mask & (1 << jj));
        if (with == 0) {
          dp[mask | (1 << jj)] =
              std::min(dp[mask | (1 << jj)], dp[mask] + horiz[ii][jj]);
        }
        auto new_mask = (mask >> jj) ^ (mask >> (jj + 1) % nn);
        if ((new_mask & 1) == 1) {
          dp[mask] += vert[ii + 1][jj];
        }
      }
    }
  }
  std::cout << dp.back();
}
