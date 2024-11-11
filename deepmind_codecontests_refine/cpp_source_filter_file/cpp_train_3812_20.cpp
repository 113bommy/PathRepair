#include <bits/stdc++.h>
int main() {
  int n;
  std::cin >> n;
  if (n >= 11) {
    std::cout << 0;
    return 0;
  }
  int a[15][10];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 5; ++j) {
      std::cin >> a[i][j];
    }
  }
  std::vector<int> vec;
  for (int i = 0; i < n; ++i) {
    bool flag = true;
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      for (int k = 0; k < n; ++k) {
        if (k == i || j == k) continue;
        int ans = 0;
        for (int l = 0; l < 5; ++l) {
          ans += (a[j][l] - a[i][l]) * (a[k][l] - a[i][l]);
        }
        if (ans > 0) {
          flag = false;
        }
      }
    }
    if (flag) vec.push_back(i);
  }
  std::cout << vec.size() << "\n";
  for (auto it : vec) {
    std::cout << it + 1 << "\n";
  }
}
