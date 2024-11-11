#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 7;
const int MOD = 1e9 + 7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
int n;
int a[N], dp[N][N];
inline int check(const int &l, const int &r) {
  stack<int> stk;
  for (int i = l, x; i <= r; ++i) {
    x = a[i];
    while (stk.size() && stk.top() == x) {
      stk.pop();
      ++x;
    }
    stk.push(x);
  }
  return stk.size();
}
inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int len = 1; len <= n; ++len) {
    for (int l = 1, r; (r = l + len - 1) <= n; ++l) {
      dp[l][r] = check(l, r);
      for (int k = l; k < r; ++k) {
        dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
      }
    }
  }
  cout << dp[1][n] << endl;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int testcase = 1;
  for (int i = 1; i <= testcase; ++i) {
    solve();
  }
  return 0;
}
