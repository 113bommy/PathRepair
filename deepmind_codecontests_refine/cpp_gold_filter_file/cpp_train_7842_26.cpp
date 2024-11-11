#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using dd = long double;
namespace {
static bool constexpr dbg = 0;
ll constexpr N = -1;
dd k, b, n, t;
ll res;
void init() { cin >> k >> b >> n >> t; }
void solve() {
  if (k == 1) {
    res = ceil((k + 1.L * n * b - 1.L * k * t) / b);
  } else {
    res = ceil(n - log((t * (k - 1.L) + b) / (k - 1 + b)) / log(k));
  }
  cout << max(0LL, res) << '\n';
}
void test() {
  if (dbg) {
  }
}
}  // namespace
int main() {
  if (!dbg) {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
  cout << fixed << setprecision(20);
  init();
  solve();
  test();
  return 0;
}
