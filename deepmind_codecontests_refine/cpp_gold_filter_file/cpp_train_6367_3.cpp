#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;
const int MAXN = 1000001;
const int MAXK1 = 20;
const int MAXK2 = 2;
int dp[MAXN][MAXK1][MAXK2];
ll bigmod(ll a, ll x, ll mod) {
  ll ans = 1;
  ll p = 0;
  ll temp = a;
  while (x) {
    if (x & 1) ans = (ans * temp) % mod;
    x /= 2;
    temp = (temp * temp) % mod;
  }
  return ans;
}
ll invmod(ll x, ll mod) { return bigmod(x, mod - 2, mod); }
void solve() {
  int n;
  cin >> n;
  int x = -1;
  for (int temp = n; temp; temp /= 2, x++)
    ;
  ll pow2[21];
  pow2[0] = 1;
  for (int i = 1; i < 21; i++) pow2[i] = (pow2[i - 1] * 2);
  ll pow3[21];
  pow3[0] = 1;
  for (int i = 1; i < 21; i++) pow3[i] = (pow2[i - 1] * 3);
  int y = 0;
  if (x && n / (pow2[x - 1] * 3) >= 1) {
    y = 1;
  }
  memset(dp, 0, sizeof(dp));
  dp[1][x][0] = 1;
  if (y && x) dp[1][x - 1][1] = 1;
  auto f = [n, &pow2, &pow3](ll x, ll y) -> ll {
    return n / (pow2[x] * pow3[y]);
  };
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j <= x; j++) {
      for (int k = 0; k <= y; k++) {
        ll temp = f(j, k) - (i - 1);
        if (temp > 0)
          dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k] * temp) % mod;
        if (j < x) {
          ll temp = f(j, k) - f(j + 1, k);
          dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j + 1][k] * temp) % mod;
        }
        if (k < y) {
          ll temp = f(j, k) - f(j, k + 1);
          dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k + 1] * temp) % mod;
        }
      }
    }
  }
  cout << dp[n][0][0] << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
