#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct P {
  ll x, y;
  P(ll xx = 0, ll yy = 0) { x = xx, y = yy; }
  P operator-(P r) { return P(x - r.x, y - r.y); }
} p[205];
ll Cross(P A, P B) { return A.x * B.y - A.y * B.x; }
pair<int, ll> dp[205][205];
int n, t;
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> t;
  for (int i = 1; i <= n; i += 1) {
    cin >> p[i].x >> p[i].y;
  }
  ll lo = -1e18, hi = 1e18, ans = -1e18;
  while (hi >= lo) {
    ll mid = lo + hi >> 1;
    for (int len = 2; len <= n; len += 1) {
      for (int l = 1; l + len - 1 <= n; l += 1) {
        int r = l + len - 1;
        if (len == 2)
          dp[l][r] = make_pair(0, 0);
        else {
          dp[l][r] = make_pair(-1000000000, 0);
          for (int k = l + 1; k < r; k += 1) {
            int nk = dp[l][k].first + dp[k][r].first;
            ll area = dp[l][k].second + dp[k][r].second +
                      abs(Cross(p[l] - p[r], p[k] - p[r]));
            if (area >= mid) {
              area = 0;
              nk += 1;
            }
            dp[l][r] = max(dp[l][r], make_pair(nk, area));
          }
        }
      }
    }
    if (dp[1][n].first >= t + 1) {
      lo = mid + 1;
      ans = mid;
    } else {
      hi = mid - 1;
    }
  }
  cout << ans << endl;
  return 0;
}
