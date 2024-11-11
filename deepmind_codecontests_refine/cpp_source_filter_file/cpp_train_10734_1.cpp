#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long long mod = 1e9 + 7;
const int phash = 3;
const long long modhash = 1000000000000000003;
const long long INF = 1e12;
vector<vector<long long> > dp;
vector<vector<long long> > dp2;
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  dp.resize(2);
  dp[0].resize(201);
  dp[1].resize(201);
  if (a[0] == -1) {
    for (int i = 1; i <= 200; i++) dp[0][i] = 1;
  } else
    dp[0][a[0]] = 1;
  for (int i = 1; i < n; i++) {
    dp2.resize(2);
    dp2[0].resize(201);
    dp2[1].resize(201);
    long long sum = 0;
    for (int j = 1; j <= 200; j++) {
      dp2[0][j] = sum;
      dp2[1][j] = (dp[0][j] + dp[1][j]) % mod;
      sum = (sum + dp2[1][j]) % mod;
    }
    sum = 0;
    for (int j = 200; j >= 1; j--) {
      dp2[1][j] = (dp2[1][j] + sum) % mod;
      sum = (sum + dp[1][j]) % mod;
    }
    if (a[i] != -1) {
      for (int j = 1; j <= 200; j++)
        if (j != a[i]) dp2[0][j] = dp2[1][j] = 0;
    }
    dp = dp2;
  }
  long long ans = 0;
  for (int i = 1; i <= 200; i++) ans = (ans + dp[1][i]) % mod;
  cout << ans;
}
