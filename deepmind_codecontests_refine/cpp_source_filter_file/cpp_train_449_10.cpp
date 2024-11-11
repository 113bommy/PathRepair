#include <bits/stdc++.h>
using namespace std;
long long int min(long long int a, long long int b) {
  if (a > b) return b;
  return a;
}
long long int max(long long int a, long long int b) {
  if (a < b) return b;
  return a;
}
int main() {
  long long int n, m, i, j, k, p, q, ti = 0, ans = 0, dl = 0, dp[2005], t[2005],
                                     a[2005];
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> t[i] >> a[i];
    t[i]++;
  }
  dp[0] = 0;
  for (i = 1; i <= n; i++) {
    dp[i] = 100000000000;
  }
  for (i = 1; i <= n; i++) {
    for (j = n; j >= 1; j--) {
      dp[j] = min(dp[j], dp[max(0, j - t[i])] + a[i]);
    }
  }
  cout << dp[n];
  return 0;
}
