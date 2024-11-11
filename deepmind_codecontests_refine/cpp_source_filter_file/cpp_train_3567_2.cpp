#include <bits/stdc++.h>
using namespace std;
using ld = double;
using ll = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
void dbg() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg(Head head, Tail... tail) {
  cerr << " " << head;
  dbg(tail...);
}
void solve() {
  ll n, r1, r2, r3, d;
  cin >> n >> r1 >> r2 >> r3 >> d;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<vector<ll>> dp(n, vector<ll>(2, (int)1e9));
  dp[0][0] = r1 * a[0] + r3;
  dp[0][1] = min(r2, r1 * (a[0] + 1));
  auto Min = [](ll& x, ll y) { x = min(x, y); };
  for (int i = 1; i < n; ++i) {
    Min(dp[i][0], dp[i - 1][0] + d + r1 * a[i] + r3);
    Min(dp[i][0], dp[i - 1][1] + 2 * d + r1 + d + r1 * a[i] + r3);
    Min(dp[i][0],
        dp[i - 1][1] + d + min(r2, r1 * (a[i] + 1)) + d + r1 + d + r1);
    Min(dp[i][1], dp[i - 1][0] + d + min(r2, r1 * (a[i] + 1)));
    Min(dp[i][1], dp[i - 1][1] + d + min(r2, r1 * (a[i] + 1)) + d + r1 + d);
  }
  cout << min(dp[n - 1][0], dp[n - 2][1] + d + r1 * a[n - 1] + r3 + d + r1);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
