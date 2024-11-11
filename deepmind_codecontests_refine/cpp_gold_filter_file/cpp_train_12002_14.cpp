#include <bits/stdc++.h>
using namespace std;
template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
int n, m, k;
int arr[70][70];
int dp[71][71][36][71];
int func(int s, int e, int cnd, int rem) {
  if (cnd >= m / 2) {
    return -1e9;
  }
  if (s == n) {
    if (rem == 0) {
      return 0;
    }
    return -1e9;
  }
  if (e == m) {
    return -1e9;
  }
  if (dp[s][e][cnd][rem] != -1) {
    return dp[s][e][cnd][rem];
  }
  int ans;
  int nc = (rem + arr[s][e]) % k;
  ans =
      max({func(s, e + 1, cnd, rem), arr[s][e] + func(s, e + 1, cnd + 1, nc)});
  ans = max({ans, func(s + 1, 0, 0, rem), arr[s][e] + func(s + 1, 0, 0, nc)});
  return dp[s][e][cnd][rem] = ans;
}
void solve() {
  memset(dp, -1, sizeof(dp));
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }
  int ans = func(0, 0, 0, 0);
  if (ans < 0) {
    ans = 0;
  }
  cout << ans << endl;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
}
