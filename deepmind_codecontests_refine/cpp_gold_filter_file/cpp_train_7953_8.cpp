#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
template <typename T>
T gcd(T a, T b) {
  return b == 0 ? a : gcd(b, a % b);
}
template <typename T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
static bool constexpr dbg = 0;
ll constexpr NM = 2e3 + 9;
ll p[NM], q[NM];
ll res, n;
void solve(ll i) {
  ll be = 0, af = 0;
  for (ll j = 1; j < i; ++j)
    if (p[j] < p[i]) ++be;
  for (ll j = i + 1; j <= n; ++j)
    if (p[j] < p[i]) ++af;
  q[i] = be > af ? p[i] : -p[i];
}
int main() {
  if (!dbg) {
    std::ios::sync_with_stdio(false);
  }
  cin >> n;
  for (ll i = 1; i <= (ll)(n); ++i) {
    cin >> p[i];
    p[i] = abs(p[i]);
  }
  for (ll i = 1; i <= (ll)(n); ++i) solve(i);
  for (ll i = 1; i <= (ll)(n); ++i)
    for (ll j = i + 1; j <= n; ++j)
      if (q[i] > q[j]) ++res;
  cout << res << endl;
  return 0;
}
