#include <bits/stdc++.h>
using namespace std;
int n, res, k;
long long e[47];
int dp[1 << 20];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int a;
      cin >> a;
      if (a) {
        e[i] |= (1 << j);
        e[j] |= (1 << i);
      }
    }
  }
  int m = n / 2;
  for (int i = 0; i < (1 << m); ++i) {
    for (int j = 0; j < m; ++j) {
      if (i & (1 << j)) dp[i] = max(dp[i], dp[i ^ (1 << j)]);
    }
    int c = i;
    for (int j = 0; j < m; ++j) {
      if (i & (1 << j)) c &= e[j] | (1 << j);
    }
    if (c == i) dp[i] = __builtin_popcount(i);
  }
  res = dp[(1 << m) - 1];
  for (int i = 0; i < (1 << (n - m)); ++i) {
    int c = i;
    for (int j = 0; j < n - m; ++j) {
      if (i & (1 << j)) c &= (e[j + m] >> m) | (1 << j);
    }
    if (c == i) {
      int adj = (1 << m) - 1;
      for (int j = 0; j < n - m; ++j) {
        if (i & (1 << j)) adj &= e[j + m];
      }
      res = max(res, __builtin_popcount(i) + dp[adj]);
    }
  }
  cout << fixed << " " << setprecision(10)
       << (double)k * k * (res - 1) / res / 2;
}
