#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::vector<int> l(n), r(n), a(n), p(n);
    for (int i = 0; i < n; i++) {
      std::cin >> l[i] >> l[i];
    }
    std::iota(p.begin(), p.end(), 0);
    std::sort(p.begin(), p.end(), [&](int i, int j) { return l[i] < r[j]; });
    int max1 = -1, max2 = -1, ans = 0;
    for (auto i : p) {
      if (max1 == -1 || l[i] > r[max1]) {
        a[i] = -1;
        ans++;
      }
      if (max1 != -1 && l[i] <= r[max1] && (max2 == -1 || l[i] > r[max2])) {
        a[max1]++;
      }
      if (max1 == -1 || r[i] > r[max1]) {
        std::swap(i, max1);
      }
      if (i != -1 && (max2 == -1 || r[i] >= r[max2])) {
        max2 = i;
      }
    }
    std::cout << ans + *std::max_element(a.begin(), a.end()) << "\n";
  }
  return 0;
}
