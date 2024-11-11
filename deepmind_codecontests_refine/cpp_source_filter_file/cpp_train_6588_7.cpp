#include <bits/stdc++.h>
void solve() {
  int s, k;
  std::cin >> s >> k;
  std::vector<int> v(s);
  std::vector<int> vv(s);
  for (auto& a : v) {
    std::cin >> a;
  }
  for (auto& a : vv) {
    std::cin >> a;
  }
  std::sort(v.begin(), v.end());
  std::sort(vv.begin(), vv.end());
  for (int i{0}; i < s; ++i) {
    if ((v[s - i - 1] + vv[i] > k) || (v[i] + vv[s - i - 1]) > k) {
      std::cout << "NO\n";
      return;
    }
    std::cout << "YES\n";
  }
}
int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  int t{};
  std::cin >> t;
  for (int i{0}; i < t; ++i) {
    solve();
  }
}
