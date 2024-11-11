#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int nm = (1 << 22) - 1, n;
  vector<int> dp(nm + 1, -1);
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i], dp[a[i]] = a[i];
  for (int i = 0; i < nm + 1; ++i) {
    for (int j = 0; j < 22; ++j) {
      if (((i >> j) & 1) && dp[i ^ (1 << j)] != -1) dp[i] = dp[i ^ (1 << j)];
    }
  }
  for (int i = 0; i < n; ++i) cout << dp[a[i] ^ nm] << ' ';
}
