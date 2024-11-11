#include <bits/stdc++.h>
using namespace std;
long long const mod = 1e9 + 7, MAXN = 1e6 + 5, oo = 3e18;
long long tc, n, pre;
long long a[MAXN], dp[MAXN];
void aurelion_sol() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  pre = 1;
  for (int i = 2; i <= n; i++) {
    dp[i] = abs(a[i] - a[pre]) + dp[pre - 1];
    dp[i] = max(dp[i], abs(a[i] - a[pre + 1]) + dp[pre]);
    if (a[i] <= a[i - 1] && a[i] <= a[i + 1]) {
      pre = i;
    } else if (a[i] >= a[i - 1] && a[i] >= a[i + 1]) {
      pre = i;
    }
  }
  cout << dp[n] << endl;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  tc = 1;
  while (tc--) aurelion_sol();
}
