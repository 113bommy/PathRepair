#include <bits/stdc++.h>
using namespace std;
const int mxn = 100000;
int n, m, q;
int u[mxn], d[mxn], l[mxn], r[mxn];
int dp[mxn][2];
void in(int n, int a[mxn]) {
  for (int i = 1; i <= n; i++) {
    char c;
    cin >> c;
    a[i] = c == 'B';
  }
}
int sol(int n, int m, int u[mxn], int d[mxn], int l[mxn], int r[mxn]) {
  dp[0][0] = dp[0][1] = 0;
  for (int i = 1; i <= n; i++) dp[0][l[i]]++;
  for (int i = 1; i <= m; i++) {
    dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + n) + !u[i] + !d[i];
    dp[i][1] = min(dp[i - 1][0] + n, dp[i - 1][1]) + u[i] + d[i];
  }
  for (int i = 1; i <= n; i++) dp[m][r[i]]++;
  return min(dp[m][0], dp[m][1]);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> q;
  in(n, l), in(n, r), in(m, u), in(m, d);
  int ret = min(sol(n, m, u, d, l, r), sol(m, n, l, r, u, d));
  cout << ret << '\n';
  return 0;
}
