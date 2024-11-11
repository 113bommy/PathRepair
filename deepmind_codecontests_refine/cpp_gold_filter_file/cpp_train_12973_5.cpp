#include <bits/stdc++.h>
using namespace std;
namespace {
constexpr int g1 = 1000 * 1000 * 1000, si = 1001 * 1002, si_log = 8 + 10,
              mod = static_cast<int>(1e9) + 7;
constexpr long double eps = 1.0e-9;
int n, ar[si];
}  // namespace
int64_t ca(const int sid) {
  const auto di = n / sid, re = n % sid, z = 0 == re ? 0 : 2,
             ret = 2 * (sid + di) + z;
  return ret;
}
int64_t sol() {
  auto ret = 1 * numeric_limits<int64_t>::max();
  const auto q = static_cast<int>(sqrt(n));
  for (int i = 1; i <= q; i++) {
    auto c = ca(i);
    ret = min(ret, c);
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  while (cin >> n) {
    auto s = sol();
    cout << s << '\n';
    break;
  }
  return 0;
}
