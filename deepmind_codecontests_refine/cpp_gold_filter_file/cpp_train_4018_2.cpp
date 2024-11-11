#include <bits/stdc++.h>
#pragma GCC optimize("Ofast, unroll-loops", "omit-frame-pointer", "inline")
#pragma GCC option("arch=native", "tune=native", "no-zero-upper")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native,avx2")
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll getrnd(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }
template <typename T1, typename T2>
inline bool relax(T1& a, const T2& b) {
  return a > b ? a = b, true : false;
}
template <typename T1, typename T2>
inline bool strain(T1& a, const T2& b) {
  return a < b ? a = b, true : false;
}
void solve() {
  int n, k;
  cin >> n >> k;
  int bg = 0, sm = 0;
  set<int> trans;
  for (int i = 0; i < k; ++i) {
    int x;
    cin >> x;
    if (x >= n) bg = 1;
    if (x <= n) sm = 1;
    trans.insert(x - n);
  }
  if (!(bg && sm)) {
    cout << "-1\n";
    return;
  }
  const int off = 1500;
  vector<int> d(2 * off, -1);
  queue<int> scope;
  scope.emplace(off);
  d[off] = 0;
  while (!scope.empty()) {
    int v = scope.front();
    scope.pop();
    for (int e : trans) {
      int to = v + e;
      if (to < 0 || to >= 2 * off) continue;
      if (d[to] == -1) {
        d[to] = d[v] + 1;
        scope.emplace(to);
      }
      if (to == off) {
        cout << d[v] + 1 << '\n';
        return;
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  srand(time(0));
  int t = 1;
  while (t--) solve();
  return 0;
}
