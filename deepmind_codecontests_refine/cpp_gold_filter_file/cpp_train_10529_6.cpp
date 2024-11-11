#include <bits/stdc++.h>
int main() {
  int n, q;
  std::cin >> n >> q;
  std::vector<std::pair<int, int>> a(q);
  std::vector<int> cnt(n), k1(q), pr(n, -1);
  std::vector<std::vector<int>> k2(q, std::vector<int>(q));
  for (auto &i : a) {
    std::cin >> i.first >> i.second;
    --i.first;
    --i.second;
  }
  for (auto i : a) {
    for (int j = i.first; j <= i.second; ++j) {
      ++cnt[j];
    }
  }
  for (int i = 0; i < q; ++i) {
    for (int j = a[i].first; j <= a[i].second; ++j) {
      if (cnt[j] == 1) {
        ++k1[i];
      }
    }
  }
  for (int i = 0; i < q; ++i) {
    for (int j = a[i].first; j <= a[i].second; ++j) {
      if (cnt[j] == 2) {
        if (pr[j] == -1) {
          pr[j] = i;
        } else {
          ++k2[pr[j]][i];
        }
      }
    }
  }
  int max = 0, sum = 0;
  for (int i = 0; i < n; ++i) {
    if (cnt[i] > 0) ++sum;
  }
  for (int i = 0; i < q; ++i) {
    for (int j = i + 1; j < q; ++j) {
      max = std::max(max, sum - k1[i] - k1[j] - k2[i][j]);
    }
  }
  std::cout << max;
  return 0;
}
