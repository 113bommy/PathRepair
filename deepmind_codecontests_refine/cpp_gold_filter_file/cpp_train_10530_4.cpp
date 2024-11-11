#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
int n, k, m;
ll dp[maxn][13][1 << 4];
int main() {
  cin >> n >> k >> m;
  int N = (1 << m) - 1;
  dp[0][0][0] = 1;
  for (int i = 0; i <= n - 1; i++) {
    for (int j = 0; j <= k; j++) {
      for (int s = 0; s <= N; s++) {
        int ns = (s << 1) & N;
        (dp[i + 1][j][ns] += dp[i][j][s]) %= mod;
        int cnt = __builtin_popcount(s) + 1;
        if (j < k) (dp[i + 1][j + 1][ns | 1] += 1LL * dp[i][j][s] * cnt) %= mod;
      }
    }
  }
  ll ans = 0;
  for (int i = 0; i <= N; i++) (ans += dp[n][k][i]) %= mod;
  cout << ans << endl;
  return 0;
}
