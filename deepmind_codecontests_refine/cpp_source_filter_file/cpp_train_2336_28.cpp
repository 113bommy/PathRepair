#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e16 + 10, MAX = 1e6 + 1e5, MOD = 1e9 + 7;
void OUT(long double o, int x) {
  cout << fixed << setprecision(x) << o;
  return;
}
long long dp[10][MAX];
pair<pair<long long, long long>, long long> a[120];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m, d;
  cin >> n >> m >> d;
  for (int i = 1; i <= n; i++) {
    long long x = 0, y;
    cin >> a[i].second >> a[i].first.first >> x;
    for (int j = 0; j < x; j++) {
      cin >> y;
      a[i].first.second |= 1LL << (y - 1);
    }
  }
  sort(a + 1, a + (n + 1));
  for (int i = 1; i < (1LL << m); i++) dp[0][i] = INF;
  long long ans = INF;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < (1LL << m); j++)
      dp[i % 2][j] =
          min(dp[(i - 1) % 2][j],
              dp[(i - 1) % 2][(j | a[i].first.second) ^ a[i].first.second] +
                  a[i].second);
    ans = min(ans, dp[i % 2][(1LL << m) - 1] + (d * a[i].first.first));
  }
  if (ans < INF)
    cout << ans;
  else
    cout << -1;
  return 0;
}
