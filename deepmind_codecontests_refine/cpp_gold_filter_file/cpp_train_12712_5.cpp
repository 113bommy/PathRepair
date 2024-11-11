#include <bits/stdc++.h>
long long var;
int main() {
  long long t;
  t = 1;
  for (int i = 0; i <= t - 1; i++) {
    long long n;
    std::cin >> n;
    std::vector<long long> a(n);
    for (int i = 0; i <= n - 1; i++) {
      std::cin >> a[i];
    }
    long long sum = 0, max = 0, x = 0, y = 0;
    for (x = 0; x <= n - 1; x++) {
      sum = 0;
      for (y = x; y <= n - 1; y++) {
        sum += a[y];
        if (sum > (y - x + 1) * 100) {
          max = std::max(max, y - x + 1);
        }
      }
    }
    std::cout << max << "\n";
  }
}
