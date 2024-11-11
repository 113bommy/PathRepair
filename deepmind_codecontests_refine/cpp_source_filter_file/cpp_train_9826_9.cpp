#include <bits/stdc++.h>
static const int INF = std::numeric_limits<int>::max();
int main() {
  int n;
  std::cin >> n;
  std::vector<int> v(n + 1);
  for (int i = 0; i <= n; ++i) {
    v[i] = 0;
  }
  std::vector<int> ans(n + 1, -1);
  int mask = 1;
  while (mask <= n) {
    mask <<= 1;
  }
  --mask;
  int sum = 0;
  for (int i = n; i >= 0; --i) {
    int k = (~i) & mask;
    if (k <= n && v[k] == 0) {
      v[k] = 1;
      ans[i] = k;
      sum += i ^ k;
    } else {
      for (int m = mask; m > 0; m >>= 1) {
        int k = (~i) & m;
        if (k <= n && v[k] == 0) {
          v[k] = 1;
          ans[i] = k;
          sum += i ^ k;
          break;
        }
      }
    }
  }
  for (int i = 0; i <= n; ++i) {
    if (ans[i] == -1) {
      for (int j = 0; j <= n; ++j) {
        if (v[j] == 0) {
          ans[i] = j;
          sum += i ^ j;
          break;
        }
      }
      break;
    }
  }
  std::cout << sum << std::endl;
  std::copy(ans.begin(), ans.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;
}
