#include <bits/stdc++.h>
using namespace std;
int gcd(int x, int y) { return (!y ? x : gcd(y, x % y)); }
const int maxn = 1500 + 10;
int a[maxn], pre[maxn], best[maxn], dp[maxn][maxn];
vector<int> adj[maxn];
int n, m, s, k;
bool isval(int x) {
  for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + (a[i] <= x);
  memset(dp, 0, sizeof dp);
  for (int i = 1; i <= n; ++i) {
    dp[i][0] = 0;
    for (int j = 1; j <= m; ++j) {
      dp[i][j] = dp[i - 1][j];
      dp[i][j] =
          max(dp[i][j], dp[best[i] - 1][j - 1] + pre[i] - pre[best[i] - 1]);
    }
  }
  for (int i = 1; i <= m; ++i)
    if (dp[n][i] >= k) return true;
  return false;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> s >> m >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= s; ++i) {
    int x, y;
    cin >> x >> y;
    adj[y].push_back(x);
  }
  best[n + 1] = n + 1;
  for (int i = n; i >= 1; --i) {
    best[i] = min(best[i + 1], i + 1);
    for (int v : adj[i]) best[i] = min(best[i], v);
  }
  int lo = 0, hi = 1e9 + 10;
  while (hi - lo > 1) {
    int mid = hi + lo >> 1;
    if (isval(mid))
      hi = mid;
    else
      lo = mid;
  }
  if (hi >= int(1e9))
    cout << -1 << '\n';
  else
    cout << hi << '\n';
}
