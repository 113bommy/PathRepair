#include <bits/stdc++.h>
long long n, m;
void init() { std::cin >> n >> m; }
long long calc(long long x, long long y) {
  if (y == 1) {
    return (x + 1) / 2;
  } else {
    y--;
    std::map<long long, long long> cnt[2];
    long long used[2] = {0, 0};
    if ((x - 1) / 2 != 0) {
      cnt[0][(x - 1) / 2] = 1;
    }
    if (x / 2 != 0) {
      cnt[1][x / 2] = 1;
    }
    while (true) {
      std::pair<long long, long long> cur[2];
      if (!cnt[0].empty()) {
        cur[0] = *cnt[0].rbegin();
      }
      if (!cnt[1].empty()) {
        cur[1] = *cnt[1].rbegin();
      }
      int t;
      if (cnt[0].empty()) {
        t = 1;
      } else if (cnt[1].empty()) {
        t = 0;
      } else {
        if ((cur[0].first - 1) / 2 < (cur[1].first - 1) / 2) {
          t = 1;
        } else {
          t = 0;
        }
      }
      if (cur[t].second >= y) {
        return ((x + 1) / 2) * t +
               calc(t == 0 ? (x + 1) / 2 : x / 2, y + used[t]);
      } else {
        used[t] += cur[t].second;
        y -= cur[t].second;
        cnt[t].erase(cur[t].first);
        if ((cur[t].first - 1) / 2 != 0) {
          cnt[t][(cur[t].first - 1) / 2] += cur[t].second;
        }
        if (cur[t].first / 2 != 0) {
          cnt[t][cur[t].first / 2] += cur[t].second;
        }
      }
    }
  }
}
void work() {
  if (m == 1) {
    std::cout << 1 << std::endl;
  } else if (m == 2) {
    std::cout << n << std::endl;
  } else {
    std::cout << 1 + calc(n - 2, m - 2) << std::endl;
  }
}
int main() {
  init();
  work();
  return 0;
}
