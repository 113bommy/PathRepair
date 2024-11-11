#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

int main() {
  const int X = 30;
  vector<ll> n(X, 1);
  FOR(i, 1, X) n[i] = n[i - 1] * 3;
  function<void()> solve = [&]() {
    ll a, b, c, d; cin >> a >> b >> c >> d; --a; --b; --c; --d;
    ll ans = abs(c - a) + abs(d - b);
    for (int level = X; level > 0; --level) {
      ll a_div = a / n[level - 1], b_div = b / n[level - 1], c_div = c / n[level - 1], d_div = d / n[level - 1];
      // cout << a_div << ' ' << b_div << ' ' << c_div << ' ' << d_div << '\n';
      if (a_div != c_div && b_div != d_div) break;
      if (a_div == c_div && b_div == d_div) continue;
      if (a_div == c_div && a_div % 3 == 1 && abs(b_div - d_div) >= 2) {
        ans += min({a % n[level - 1] + 1, c % n[level - 1] + 1, n[level - 1] - a % n[level - 1], n[level - 1] - c % n[level - 1]}) * 2;
        break;
      } else if (b_div == d_div && b_div % 3 == 1 && abs(a_div - c_div) >= 2) {
        ans += min({b % n[level - 1] + 1, d % n[level - 1] + 1, n[level - 1] - b % n[level - 1], n[level - 1] - d % n[level - 1]}) * 2;
        break;
      }
    }
    cout << ans << '\n';
  };
  int q; cin >> q;
  while (q--) solve();
  return 0;
}
