#include <bits/stdc++.h>
using namespace std;
const long long mk = 200055;
const long long logn = 29;
const long long mod = 1e9 + 7;
long long n, m, q, k, ans = 0;
vector<long long> g[mk];
long long dp[505][505], p[mk];
void init() {
  cin >> n >> k;
  p[0] = 1;
  for (long long i = 1; i <= 25011; i++) p[i] = (p[i - 1] * 2) % mod;
  for (long long i = 0; i <= 504; i++) dp[i][0] = 1;
  for (long long c = 1; c <= k; c++) {
    for (long long i = 0; i < n + 1; i++) {
      for (long long j = 0; j < i; j++) {
        dp[i][c] = (dp[i][c] + (1ll * dp[j][c - 1] * (p[i - j] - 1)) % mod *
                                   p[j * (i - j)]) %
                   mod;
      }
    }
  }
  cout << dp[n][k];
}
signed main() { init(); }
