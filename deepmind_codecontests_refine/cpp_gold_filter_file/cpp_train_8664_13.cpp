#include <bits/stdc++.h>
int main() {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;
  std::vector<int> vi;
  std::vector<int> op(m + 1, 0);
  long long sum = 0;
  for (int i = 0; i < m; ++i) {
    int x = 0;
    std::cin >> x;
    vi.push_back(x);
    sum += x;
  }
  if (sum < n) {
    std::cout << -1 << std::endl;
    return 0;
  }
  int start = 1;
  int left = n;
  for (int i = 0; i < m; ++i) {
    if (vi[i] + i > n) {
      std::cout << -1 << std::endl;
      return 0;
    }
    if (sum == left) {
      op[i] = start;
      start += vi[i];
      sum -= vi[i];
      left -= vi[i];
    } else {
      int move_n = std::max(1LL, left - (sum - vi[i]));
      op[i] = start;
      start += move_n;
      sum -= vi[i];
      left -= move_n;
    }
  }
  std::cout << op[0];
  for (int i = 1; i < m; ++i) {
    std::cout << " " << op[i];
  }
  std::cout << std::endl;
}
