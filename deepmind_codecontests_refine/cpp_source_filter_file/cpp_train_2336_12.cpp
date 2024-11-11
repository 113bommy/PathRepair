#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y) {
  long long int res = 1;
  while (y) {
    if (y & 1) res = (res * x) % 1000000007;
    y = y / 2, x = (x * x) % 1000000007;
  }
  return res % 1000000007;
}
long long int dp[1 << 20];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int i;
  for (i = 0; i < (1 << 20); i++) dp[i] = 1e18;
  long long int n, m, b;
  cin >> n >> m >> b;
  pair<long long int, pair<long long int, long long int> > arr[n];
  long long int ans = 2e18;
  for (i = 0; i < n; i++) {
    long long int x, k, mm;
    cin >> x >> k >> mm;
    arr[i].first = k;
    arr[i].second.first = x;
    long long int j;
    long long int mask = 0;
    for (j = 0; j < mm; j++) {
      long long int p;
      cin >> p;
      p--;
      mask = mask | (1 << p);
    }
    arr[i].second.second = mask;
  }
  sort(arr, arr + n);
  dp[0] = 0;
  long long int j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < (1 << 20); j++) {
      long long int nextt = j | arr[i].second.second;
      dp[nextt] = min(dp[nextt], dp[j] + arr[i].second.first);
    }
    ans = min(ans, dp[(1 << m) - 1] + b * arr[i].first);
  }
  if (ans >= 1e18)
    cout << -1;
  else
    cout << ans;
}
