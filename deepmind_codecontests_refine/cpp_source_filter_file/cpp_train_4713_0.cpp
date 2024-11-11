#include <bits/stdc++.h>
using namespace std;
template <typename P, typename Q>
P CeilDiv(P _dividend, Q _divider) {
  return static_cast<P>((_dividend - 1LL + _divider) / _divider);
}
template <typename Tp>
inline void outarr(Tp _begin, Tp _end, const char* _delim = " ") {
  for (Tp current = _begin; current != _end; ++current) {
    std::cout << *current << _delim;
  }
  std::cout << '\n';
}
using ll = long long;
using pii = std::pair<int, int>;
constexpr int INF = 0x3f3f3f3f;
constexpr int MOD = static_cast<const int>(1e9 + 7);
string Gen(const string& s, int x) {
  string res(static_cast<int>((s).size()), '0');
  for (int i = 0; i < (static_cast<int>((s).size())); ++i) {
    if (i - x >= 0 && s[i - x] == '1') {
      res[i] = '1';
    }
    if (i + x < static_cast<int>((s).size()) && s[i + x] == '1') {
      res[i] = '1';
    }
  }
  return res;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int test_cases;
  cin >> test_cases;
  while (test_cases--) {
    string s;
    int x;
    cin >> s >> x;
    string ans(static_cast<int>((s).size()), '1');
    for (int i = 0; i < (static_cast<int>((s).size())); ++i) {
      if (s[i] == '1') {
        continue;
      }
      if (i - x >= 0) {
        ans[i] = '0';
      }
      if (i + x < static_cast<int>((s).size())) {
        ans[i + x] = '0';
      }
    }
    if (s != Gen(ans, x)) {
      cout << -1 << "\n";
    } else {
      cout << ans << "\n";
    }
  }
  return 0;
}
