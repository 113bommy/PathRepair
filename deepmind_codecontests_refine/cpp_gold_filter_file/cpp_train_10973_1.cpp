#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2005;
const ll mod = 1e9 + 7;
ll add(ll a, ll b) { return (a + b) % mod; }
ll sub(ll a, ll b) { return (a - b + mod * mod) % mod; }
ll mul(ll a, ll b) { return (a * b) % mod; }
int n, k;
string s;
ll dp[N][N], sum[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k >> s;
  s = " " + s;
  dp[0][0] = sum[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      dp[i][j] = add(dp[i][j], mul(sum[j], s[i] - 'a'));
      ll res = 0;
      for (int l = i - 1; l >= 0; l--) {
        if ((i - l) * (n - i + 1) > j) break;
        res = add(res, dp[l][j - (i - l) * (n - i + 1)]);
      }
      dp[i][j] = add(dp[i][j], mul(res, 'z' - s[i]));
      sum[j] = add(sum[j], dp[i][j]);
    }
  }
  ll ans = 0;
  for (int i = 0; i <= n; i++) ans = add(ans, dp[i][k]);
  cout << ans;
}
