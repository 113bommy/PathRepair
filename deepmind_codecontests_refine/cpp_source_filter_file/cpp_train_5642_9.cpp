#include <bits/stdc++.h>
using namespace std;
const long double PI = acos(-1);
const int mod = 100000007;
int dp[1000006];
int a[200005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    memset(dp, 0, sizeof(dp));
    int mn = 10000;
    int sum = 0;
    int n, k, d;
    cin >> n >> k >> d;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int j = 1; j <= d; ++j) {
      if (!dp[a[j]]) ++sum;
      ++dp[a[j]];
    }
    mn = min(sum, mn);
    for (int i = d + 1; i <= n; ++i) {
      dp[a[i - d]]--;
      if (!dp[a[i - d]]) sum--;
      if (!dp[a[i]]) ++sum;
      ++dp[a[i]];
      mn = min(mn, sum);
    }
    cout << mn << '\n';
  }
  return 0;
}
