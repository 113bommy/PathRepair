#include <bits/stdc++.h>
bool get(int x, int m) {
  int count = 0;
  int t = 5;
  while (t <= x) {
    count += x / t;
    t *= 5;
  }
  return count == m;
}
int main() {
  int m;
  std::vector<int> ans;
  int count = 0;
  std::cin >> m;
  for (int i = 1; i <= 100000; ++i) {
    if (get(i, m)) {
      count++;
      ans.push_back(i);
    }
  }
  std::cout << count << std::endl;
  for (int x : ans) std::cout << x << ' ';
  return 0;
}
