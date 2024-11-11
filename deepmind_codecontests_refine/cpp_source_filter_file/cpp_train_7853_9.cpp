#include <bits/stdc++.h>
long long n, x;
std::vector<long long> v;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin >> n;
  for (long long i = 0; i < n; ++i) {
    std::cin >> x;
    v.push_back(x);
  }
  std::sort(v.begin(), v.end());
  auto mn = v[0];
  auto mx = v[v.size() - 1];
  return mn == mx ? std::cout << 0 << (1LL * n * (n - 1) / 2)
                  : std::cout << mx - mn << " "
                              << 1LL * std::count(v.begin(), v.end(), mx) *
                                     std::count(v.begin(), v.end(), mn),
         0;
}
