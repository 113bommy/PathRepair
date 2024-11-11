#include <bits/stdc++.h>
using namespace std;
long long dp[(1 << 22) + 1];
int mark[(1 << 22) + 1];
int a[4000001];
int main() {
  int t, n, i;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    mark[a[i]] = 1;
  }
  for (int i = 0; i < (1 << 22); ++i) dp[i] = mark[i] == 0 ? -1 : i;
  for (int i = 0; i < 22; ++i) {
    for (int mask = 0; mask < (1 << 22); ++mask) {
      if (mask & (1 << i)) dp[mask] = max(dp[mask], dp[mask ^ (1 << i)]);
    }
  }
  for (i = 0; i < n; i++) {
    cout << (dp[(1 << 22) - 1 - a[i]]) << " ";
  }
  return 0;
}
