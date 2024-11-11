#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using dd = long double;
namespace {
static bool constexpr dbg = 0;
ll constexpr N = -999;
ll n;
string s;
void init() { cin >> s; }
void solve() {
  string s1 = "aeiou02468";
  for (auto ch : s)
    if (s1.find(ch) != string::npos) ++n;
  cout << n;
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
