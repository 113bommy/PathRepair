#include <bits/stdc++.h>
using namespace std;
template <typename T>
using Vec = std::vector<T>;
constexpr int MOD = 1e9 + 7;
void solve() {
  std::string s;
  cin >> s;
  int n = s.size();
  auto ans = 0LL, power = 1LL, sum = 0LL, cum = 0LL;
  for (auto i = n - 1; i >= 0; --i) {
    cum = (10LL * cum + sum) % MOD;
    auto cnt = ((1LL + i) * i / 2) % MOD * power % MOD;
    ans = (ans + (cnt + cum) % MOD * (s[i] - '0')) % MOD;
    sum = (sum + power) % MOD;
    power = (10LL * power) % MOD;
  }
  cout << ans << endl;
  return;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
