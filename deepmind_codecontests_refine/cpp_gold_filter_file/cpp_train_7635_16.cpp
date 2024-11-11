#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> bridges(n);
  for (int i = 0; i < n; ++i) {
    int k;
    std::cin >> k;
    bridges[i].resize(k);
    for (int j = 0; j < k; ++j) {
      std::cin >> bridges[i][j];
    }
  }
  int numberOfUnstableCells = 0;
  for (int i = 0; i < n; ++i) {
    std::vector<std::pair<int, int>> events;
    events.reserve(1000000);
    for (int j = 0; j < bridges[i].size(); ++j) {
      events.push_back(std::make_pair(bridges[i][j], 0));
    }
    for (int j = 0; j < bridges[(i + 1) % n].size(); ++j) {
      events.push_back(std::make_pair(bridges[(i + 1) % n][j], 1));
    }
    for (int j = 0; j < bridges[(i - 1 + n) % n].size(); ++j) {
      events.push_back(std::make_pair(bridges[(i - 1 + n) % n][j], -1));
    }
    std::sort(events.begin(), events.end());
    int firstCellOpeningEvent = 0;
    while (events[firstCellOpeningEvent].second != 0) {
      ++firstCellOpeningEvent;
    }
    int balance = 0;
    for (int j = firstCellOpeningEvent + 1; j < events.size(); ++j) {
      balance += events[j].second;
      if (events[j].second == 0) {
        if (balance != 0) {
          ++numberOfUnstableCells;
        }
        balance = 0;
      }
    }
  }
  std::cout << numberOfUnstableCells;
  return 0;
}
