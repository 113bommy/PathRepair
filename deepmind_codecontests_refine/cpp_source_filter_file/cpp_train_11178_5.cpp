#include <bits/stdc++.h>
using namespace std;
const long long int MAXN = 5005;
long long int n, m, a[MAXN], dp[MAXN];
double x;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  long long int ans = 1;
  for (long long int i = 1; i <= n; i++) {
    cin >> a[i] >> x;
    dp[i] = 1;
    for (long long int j = 1; j < i; j++) {
      if (a[j] <= a[i]) {
        dp[i] = max(dp[j] + 1, dp[i]);
      }
    }
    ans = max(ans, dp[i]);
  }
  cout << n - ans << endl;
}
