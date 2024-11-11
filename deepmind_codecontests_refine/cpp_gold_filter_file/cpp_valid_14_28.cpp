#include <bits/stdc++.h>
using namespace std;
template <typename T>
void umax(T &a, const T b) {
  if (a < b) a = b;
}
template <typename T>
void umin(T &a, const T b) {
  if (a > b) a = b;
}
void solve_problem() {
  int n, k;
  cin >> n >> k;
  vector<int> dp(n + 1, -1);
  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    for (int j = n; j > 0; --j) {
      if (dp[j - 1] != -1) {
        umax(dp[j], dp[j - 1] + (x == j));
      }
    }
  }
  int it = n;
  while (it >= 0) {
    if (dp[it] >= k) break;
    it--;
  }
  cout << (it == -1 ? -1 : n - it) << '\n';
}
int32_t main() {
  int T = 1;
  cin >> T;
  for (int tc = 0; tc < T; ++tc) {
    solve_problem();
  }
}
