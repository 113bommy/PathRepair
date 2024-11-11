#include <bits/stdc++.h>
void solution() {
  long long n;
  std::cin >> n;
  std::cout << "0 1" << std::endl;
  std::string s, t;
  std::cin >> s;
  long long l = 1, r = 1e9 - 1;
  for (long long i = (2); i <= (n); ++i) {
    long long mid = (l + r) >> 1;
    std::cout << mid << " 1" << std::endl;
    std::cin >> t;
    if (s == t)
      l = mid + 1;
    else
      r = mid - 1;
  }
  std::cout << l - 1 << " 0 " << r + 1 << " 2" << std::endl;
}
signed main() {
  42;
  std::ios::sync_with_stdio(false);
  std::cout.tie(nullptr);
  std::cin.tie(nullptr);
  solution();
}
