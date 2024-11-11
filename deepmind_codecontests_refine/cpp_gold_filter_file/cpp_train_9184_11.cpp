#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 2e3 + 7;
const int inf = INT_MAX / 2;
const long long INF = LLONG_MAX / 3;
const int MOD = 1e9 + 7;
const double eps = 1e-6;
const string cars[] = {"🚗", "🚕", "🚙"};
int dp[N][N], h;
int f(int x, int y) { return (x + h * 5000 - y) % h; }
signed main() {
  cout << fixed << setprecision(4);
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n, l, r;
  cin >> n >> h >> l >> r;
  vector<int> a(n);
  cin >> a[0];
  for (int i = 1; i < n; i++) {
    int t;
    cin >> t;
    a[i] = (a[i - 1] + t) % h;
  };
  dp[0][0] = (a[0] >= l && a[0] <= r);
  dp[0][1] = (f(a[0], 1) >= l && f(a[0], 1) <= r);
  for (int i = 1; i < n; i++) {
    dp[i][0] = dp[i - 1][0] + (a[i] >= l && a[i] <= r);
    for (int j = 1; j <= i + 1; j++) {
      dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i - 1][j - 1]) +
                                   (f(a[i], j) >= l && f(a[i], j) <= r));
    }
  }
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    ans = max(ans, dp[n - 1][i]);
  }
  cout << ans << endl;
  return 0;
}
