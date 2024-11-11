#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
const int mod = 1e9 + 7;
const ll inf = ll(1e18);
const double PI = acos(-1), eps = 1e-9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int mxn = 5e2 + 5, mxa = 1e3, mxk = 5;
const int d4i[] = {-1, 0, 1, 0}, d4j[] = {0, 1, 0, -1};
int n, m;
ll mx;
ll get(int x, vector<ll> &ve) {
  ll cnt = mx - 1 - x;
  cnt -= ve.end() - upper_bound(ve.begin(), ve.end(), x);
  return cnt;
}
void solve() {
  cin >> n >> m;
  vector<ll> ve;
  mx = 1ll << m;
  ll left = mx - n;
  for (int i = 0; i < n; ++i) {
    string second;
    cin >> second;
    ll a = 0;
    for (int i = 0; i < m; ++i) {
      a = (a << 1) + (second[i] - '0');
    }
    ve.push_back(a);
  }
  sort(ve.begin(), ve.end());
  ll lo = 0, hi = mx - 1;
  while (lo < hi) {
    ll mid = lo + (hi - lo) / 2;
    ll cnt = get(mid, ve);
    if (cnt > left / 2)
      lo = mid + 1;
    else
      hi = mid;
  }
  ll ans = -1;
  for (ll i = lo; ans == -1; ++i) {
    auto it = lower_bound(ve.begin(), ve.end(), i);
    if (it == ve.end() || *it != i) ans = i;
  }
  bitset<64> bs(ans);
  for (int i = m - 1; i >= 0; --i) cout << bs[i];
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T = 1;
  cin >> T;
  for (int tt = 1; tt <= T; ++tt) {
    solve();
  }
}
