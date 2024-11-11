#include <bits/stdc++.h>
using namespace std;
const long long int maxn = (1e6) + 1;
const long long int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n;
  cin >> n;
  long long int a[n], i, j, k;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long int ans = 1;
  vector<long long int> dp(maxn, 0);
  for (i = 0; i < n; i++) {
    long long int x = a[i];
    vector<long long int> fact;
    for (j = 2; j * j <= x; j++) {
      if (x % j == 0) fact.push_back(j);
      while (x % j == 0) {
        x = x / j;
      }
    }
    if (x >= 2) fact.push_back(x);
    for (auto f : fact) {
      dp[f] += 1;
    }
    long long int mx = 0;
    for (auto f : fact) {
      mx = max(dp[f], mx);
    }
    for (auto f : fact) {
      dp[f] = max(mx, dp[f]);
    }
  }
  for (i = 0; i < dp.size(); i++) {
    ans = max(ans, dp[i]);
  }
  cout << ans << "\n";
  return 0;
}
