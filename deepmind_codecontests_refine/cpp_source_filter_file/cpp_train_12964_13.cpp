#include <bits/stdc++.h>
inline bool isOk(const std::vector<int> &t, const std::vector<int> &wrongs,
                 int j = 0) {
  if (j) {
    if (j % 2 == 0) {
      if (t.at(j) <= t.at(j + 1) || t.at(j) <= t.at(j - 1)) {
        return false;
      }
    } else {
      if (t.at(j) >= t.at(j + 1) || t.at(j) >= t.at(j - 1)) {
        return false;
      }
    }
  }
  for (int i = 0; i < wrongs.size(); ++i) {
    if (wrongs.at(i) % 2 == 0) {
      if (t.at(wrongs.at(i)) <= t.at(wrongs.at(i) + 1) ||
          t.at(wrongs.at(i)) <= t.at(wrongs.at(i) - 1)) {
        return false;
      }
    } else {
      if (t.at(wrongs.at(i)) >= t.at(wrongs.at(i) + 1) ||
          t.at(wrongs.at(i)) >= t.at(wrongs.at(i) - 1)) {
        return false;
      }
    }
  }
  return true;
}
int solve() {
  int n;
  std::cin >> n;
  std::vector<int> t;
  t.resize(n + 1);
  bool greater = true;
  std::vector<int> wrongs;
  int count_wrong = 0;
  t.at(0) = 150001;
  std::cin >> t.at(1);
  for (int i = 2; i <= n; ++i) {
    std::cin >> t.at(i);
    if (((t.at(i) >= t.at(i - 1)) && !greater) ||
        ((t.at(i) <= t.at(i - 1)) && greater)) {
      wrongs.push_back(i - 1);
      wrongs.push_back(i);
      count_wrong++;
      if (count_wrong > 3) {
        return 0;
      }
    }
    greater = !greater;
  }
  if (n % 2 == 0) {
    t.push_back(0);
  } else {
    t.push_back(150001);
  }
  for (int i = 1; i < wrongs.size(); ++i) {
    if (wrongs.at(i) == wrongs.at(i - 1)) {
      wrongs.erase(wrongs.begin() + i);
    }
  }
  int count = 0;
  for (int i = 0; i < wrongs.size(); ++i) {
    for (int j = 1; j <= n; ++j) {
      std::swap(t.at(wrongs.at(i)), t.at(j));
      if (isOk(t, wrongs, j)) {
        bool is_has = false;
        for (int k = 0; k < wrongs.size(); ++k) {
          if (j == wrongs.at(k)) {
            is_has = true;
            break;
          }
        }
        if (!is_has || wrongs.at(i) < j) {
          count++;
        }
      }
      std::swap(t.at(wrongs.at(i)), t.at(j));
    }
  }
  return count;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cout << solve();
  return 0;
}
