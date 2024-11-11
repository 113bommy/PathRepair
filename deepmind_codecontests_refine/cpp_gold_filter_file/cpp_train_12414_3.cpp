#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
constexpr int MX = 1e5 + 5;
int N, A, R, M, h[MX];
inline ll solve(ll H) {
  ll ret = 0, ad = 0, rd = 0;
  for (int i = 0; i < N; ++i) {
    if (h[i] < H) {
      ll x = H - h[i];
      if (M < A + R) {
        ll y = min(rd, x);
        ret += y * (M - R), x -= y, rd -= y;
      }
      ret += x * A, ad += x;
    } else if (h[i] > H) {
      ll x = h[i] - H;
      if (M < A + R) {
        ll y = min(ad, x);
        ret += y * (M - A), x -= y, ad -= y;
      }
      ret += x * R, rd += x;
    }
  }
  return ret;
}
int main() {
  if (fopen("in", "r")) freopen("in", "r", stdin), freopen("out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> N >> A >> R >> M;
  for (int i = 0; i < N; ++i) cin >> h[i];
  ll l = 0, h = 2e9;
  for (int it = 0; it < 100; ++it) {
    ll ml = (2 * l + h) / 3, mh = (l + 2 * h) / 3;
    solve(ml) < solve(mh) ? h = mh : l = ml;
  }
  cout << solve((l + h) / 2);
}
