#include <bits/stdc++.h>
int main() {
  int n, m, l;
  std::cin >> n >> m >> l;
  std::vector<int64_t> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  int ans = (a[0] > l) ? 1 : 0;
  for (int i = 1; i < n; ++i) {
    if (a[i] > l && a[i - 1] <= l) {
      ++ans;
    }
  }
  for (int i = 0; i < m; ++i) {
    int t;
    std::cin >> t;
    if (t == 1) {
      int64_t p, d;
      std::cin >> p >> d;
      --p;
      if (a[p] + d <= l || a[p] > l) {
        a[p] += d;
      } else if (n == 1) {
        a[p] += d;
        ans = 1;
      } else if (p > 0 && p + 1 < n && a[p - 1] <= l && a[p + 1] <= l ||
                 p == 0 && a[1] <= l || p + 1 == n && a[p - 1] <= l) {
        ++ans;
        a[p] += d;
      } else if (p > 0 && p + 1 < n && a[p - 1] > l && a[p + 1] > l) {
        --ans;
        a[p] += d;
      } else {
        a[p] += d;
      }
    } else {
      std::cout << ans << '\n';
    }
  }
  return 0;
}
