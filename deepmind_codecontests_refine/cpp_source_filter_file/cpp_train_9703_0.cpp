#include <bits/stdc++.h>
int main() {
  int n;
  std::cin >> n;
  int left = 1;
  int right = n;
  while (right - left > 1) {
    int mid = (left + right) / 2;
    int hobbits = n;
    bool ok = true;
    for (int i = 1; i <= mid; ++i) {
      for (int j = i + 1; j <= mid; ++j) {
        --hobbits;
        if (hobbits < 0) {
          ok = false;
          goto fin;
        }
      }
    }
  fin:
    if (ok) {
      left = mid;
    } else {
      right = mid;
    }
  }
  std::vector<std::vector<int> > res(left);
  int h = 1;
  for (int i = 1; i <= left; ++i) {
    for (int j = i + 1; j <= left; ++j) {
      res[i - 1].push_back(h);
      res[j - 1].push_back(h);
      ++h;
    }
  }
  std::cout << left << std::endl;
  for (int i = 0; i < left; ++i) {
    std::copy(res[i].begin(), res[i].end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
  }
}
