#include <bits/stdc++.h>
using namespace std;
const int MOD1 = 1e9 + 7;
const int MOD2 = 998244353;
const long long INF = 2 * 1e18;
const long double PI = 3.14159265358979323846;
long long dp[505][5005] = {0}, h[15] = {0};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ;
  long long n, k, mxc = 0, mxf = 0, ans = 0, c, f;
  map<long long, long long> mc, mf;
  cin >> n >> k;
  for (int i = 0; i < k * n; i++) {
    cin >> c;
    mc[c]++;
  }
  for (int i = 0; i < n; i++) {
    cin >> f;
    mf[f]++;
  }
  for (int i = 1; i <= k; i++) cin >> h[i];
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < k * n + 1; j++) {
      for (int a = 0; a < k + 1; a++)
        dp[i][j + a] = max(dp[i][j + a], dp[i - 1][j] + h[a]);
    }
  }
  for (int i = 1; i <= 100005; i++)
    if (mf[i] != 0) ans += dp[mf[i]][mc[i]];
  cout << ans;
}
