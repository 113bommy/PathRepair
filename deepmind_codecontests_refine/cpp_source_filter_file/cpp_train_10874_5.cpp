#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:64000000")
const int maxn = 18;
const int maxm = 110;
const int maxmask = (1 << maxn) - 1;
const int infi = 1e9 + 7;
const long long infl = 1e18;
const long double eps = 1e-10;
const long long mod = 1e9 + 7;
int ar[100500];
long long dp[2010][2010];
int main() {
  int n, h;
  cin >> n >> h;
  for (int i = 1; i <= n; ++i) {
    cin >> ar[i];
  }
  for (int i = 1; i <= n; ++i) {
    if (ar[i] > h) {
      cout << 0;
      return 0;
    }
  }
  dp[1][0] = 1;
  for (int i = 1; i <= n; ++i) {
    long long h1 = h - ar[i];
    dp[i + 1][h1] += dp[i][h1];
    if (h1) {
      dp[i + 1][h1] += dp[i][h1 - 1] * (h1 - 1);
      dp[i + 1][h1] += dp[i][h1 - 1];
      dp[i + 1][h1 - 1] += dp[i][h1 - 1];
      dp[i + 1][h1 - 1] += dp[i][h1] * h1;
      dp[i + 1][h1 - 1] %= mod;
    }
    dp[i + 1][h - ar[i]] %= mod;
  }
  cout << dp[n + 1][0];
  return 0;
}
