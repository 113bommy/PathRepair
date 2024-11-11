#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int t;
  t = 1;
  while (t--) {
    long long int n, m;
    cin >> n >> m;
    long long int a[n], i;
    for (long int index = 0; index < n; index++) cin >> a[index];
    ;
    long long int dp[n], x = 0;
    for (i = 0; i < n; i++) {
      x += a[i];
      dp[i] = x;
    }
    long long int mn = dp[2], ans = 1;
    for (i = 0; i < n - m; i++) {
      if (mn > dp[i + m] - dp[i]) {
        mn = dp[i + m] - dp[i];
        ans = i + 2;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
