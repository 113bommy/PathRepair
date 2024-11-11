#include <bits/stdc++.h>
using namespace std;
void inout() {}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  inout();
  long long int n, i, y1, z1, y2, z2, sum = 0;
  cin >> n;
  long long int a[n], dp[n];
  cin >> a[0];
  for (i = 0; i < n; i++) dp[i] = 1000000000000000000;
  dp[0] = 20;
  for (i = 1; i < n; i++) {
    cin >> a[i];
    y1 = a[i] - 90;
    if (y1 < a[0]) dp[i] = min(dp[i], 50LL);
    z1 = upper_bound(a, a + i, y1) - a;
    dp[i] = min(dp[i], dp[z1 - 1] + 50LL);
    y2 = a[i] - 1440;
    if (y2 < a[0]) dp[i] = min(dp[i], 120LL);
    z2 = upper_bound(a, a + i, y2) - a;
    dp[i] = min(dp[i], dp[z2 - 1] + 120LL);
    dp[i] = min(dp[i], dp[i - 1] + 20LL);
  }
  cout << dp[0] << endl;
  for (i = 1; i < n; i++) {
    cout << dp[i] - dp[i - 1] << endl;
  }
  return 0;
}
