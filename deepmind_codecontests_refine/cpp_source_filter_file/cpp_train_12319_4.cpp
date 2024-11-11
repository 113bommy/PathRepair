#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 4e6 + 2;
const int B = 32 - __builtin_clz(N);
int n;
ll a[N / 4], dp[1 << B];
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < 1 << B; i++) {
    dp[i] = -1;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    dp[a[i]] = a[i];
  }
  for (int i = 0; i < B; i++) {
    for (int mask = 0; mask < (1 << B); mask++) {
      if (~dp[mask]) continue;
      if (mask & (1 << i)) {
        dp[mask] = dp[mask ^ (1 << i)];
      }
    }
  }
  int mask = (1 << B) - 1;
  for (int i = 1; i <= n; i++) {
    cout << dp[(~a[i]) & mask] << ' ';
  }
  cout << endl;
  return 0;
}
