#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng((long long)new char);
const double eps = 1e-8;
const int maxn = 200010;
const long double INF = 1e15;
const int mod = 1e9 + 7;
int dp[210][6010];
int c5[210], c2[210];
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, k;
  cin >> n >> k;
  for (int t = (1); t < (n + 1); ++t) {
    long long x;
    cin >> x;
    long long tx = x;
    c2[t] = 0;
    while (tx % 2 == 0) tx /= 2, ++c2[t];
    tx = x;
    c5[t] = 0;
    while (tx % 5 == 0) tx /= 5, ++c5[t];
  }
  memset(dp, 0xcf, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = k; j; --j) {
      for (int l = c5[i]; l < 6010; ++l) {
        dp[j][l] = max(dp[j][l], dp[j - 1][l - c5[i]] + c2[i]);
      }
    }
  }
  int ans = 0;
  for (int t = (0); t < (6010); ++t) ans = max(ans, min(t, dp[k][t]));
  cout << ans;
}
