#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using dd = long double;
namespace {
static bool constexpr dbg = 0;
ll constexpr N = -1;
string s, res;
void init() { cin >> s; }
void solve() {
  if (s[0] == 'h') {
    res = "http://";
    s = s.substr(4);
  } else {
    res = "ftp://";
    s = s.substr(3);
  }
  size_t i = 0;
  while (!(s[i] == 'r' && s[i + 1] == 'u')) ++i;
  res = res + s.substr(0, i) + ".ru";
  i += 2;
  if (i != s.size()) {
    res = res + "/" + s.substr(i);
  }
  cout << res;
}
}  // namespace
int main() {
  if (!dbg) {
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  }
  cout << fixed << setprecision(20);
  init();
  solve();
  return 0;
}
