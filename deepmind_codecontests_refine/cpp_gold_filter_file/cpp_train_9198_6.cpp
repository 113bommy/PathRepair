#include <bits/stdc++.h>
static const int INF = std::numeric_limits<int>::max();
int main() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  std::sort(a.begin(), a.end());
  for (int i = 0; i <= n - 1; ++i) {
    for (int j = 0; j < n - i; ++j) {
      std::cout << i + 1 << " " << a[j] << " ";
      for (int l = n - i; l < n; ++l) {
        std::cout << a[l] << " ";
      }
      std::cout << "\n";
      --k;
      if (k == 0) {
        return 0;
      }
    }
  }
}
