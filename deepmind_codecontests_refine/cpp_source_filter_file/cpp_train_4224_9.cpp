#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target( \
    "avx,avx2,fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
long long MOD = 1e9 + 7;
const int N = 200000;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0),
      cout << fixed << setprecision(20);
  long long n, c;
  cin >> n >> c;
  vector<long long> p(n);
  vector<long long> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  long long sm = 0;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    sm += s[i];
  }
  vector<long long> dp(n + 1);
  vector<long long> dp2(n + 1);
  dp[1] = c * (n - 1) + p[0] - s[0];
  for (int i = 0; i < n; i++) {
    dp[1] += s[i];
  }
  for (int i = 2; i <= n; i++) {
    dp[i] = MOD;
  }
  dp[0] = sm;
  for (int i = 2; i <= n; i++) {
    dp2 = dp;
    dp[0] = sm;
    for (int j = 1; j <= i; j++) {
      dp[j] = min(dp2[j],
                  dp2[j - 1] - s[i - 1] - c * (j - 1) + p[i - 1] + c * (n - i));
    }
  }
  long long ans = MOD;
  for (int i = 0; i <= n; i++) {
    ans = min(ans, dp[i]);
  }
  cout << ans;
}
