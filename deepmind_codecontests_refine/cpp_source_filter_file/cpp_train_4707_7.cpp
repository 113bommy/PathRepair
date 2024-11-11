#include <bits/stdc++.h>
using namespace std;
string s, t;
long long n, m, mx, dp[205][205][605];
long long solve(int i, int j, int op) {
  if (i == n && j == m) return op;
  if (op > mx) return INT_MAX;
  long long &ret = dp[i][j][op];
  if (~ret) return ret;
  long long ans = INT_MAX;
  long long x = (i < n && s[i] == '(' ? i + 1 : i);
  long long y = (j < m && t[j] == '(' ? j + 1 : j);
  ans = min(ans, solve(x, y, op + 1) + 1);
  if (op) {
    x = (i < n && s[i] == ')' ? i + 1 : i);
    y = (j < m && t[j] == ')' ? j + 1 : j);
    ans = min(ans, solve(x, y, op - 1) + 1);
  }
  return ret = ans;
}
void path(int i, int j, int op) {
  if (i == n && j == m) {
    while (op--) cout << ')';
    return;
  }
  if (op > mx) return;
  long long x = (i < n && s[i] == '(' ? i + 1 : i);
  long long y = (j < m && t[j] == '(' ? j + 1 : j);
  long long ans1 = solve(x, y, op + 1) + 1, ans2 = INT_MAX;
  if (op) {
    x = (i < n && s[i] == ')' ? i + 1 : i);
    y = (j < m && t[j] == ')' ? j + 1 : j);
    ans2 = solve(x, y, op - 1) + 1;
  }
  if (ans1 < ans2) {
    cout << '(';
    x = (i < n && s[i] == '(' ? i + 1 : i);
    y = (j < m && t[j] == '(' ? j + 1 : j);
    path(x, y, op + 1);
  } else {
    cout << ')';
    x = (i < n && s[i] == ')' ? i + 1 : i);
    y = (j < m && t[j] == ')' ? j + 1 : j);
    path(x, y, op - 1);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> s >> t;
  memset(dp, -1, sizeof dp);
  n = s.size(), m = t.size();
  mx = (n + m) * 10;
  solve(0, 0, 0);
  path(0, 0, 0);
  return 0;
}
