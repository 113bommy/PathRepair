#include <bits/stdc++.h>
using namespace std;
int dp[102][10004], d[102], lu[102];
int n, k, l;
bool magic(int x, int t) {
  if (x == 0) {
    dp[x][t] = 1;
    return dp[x][t];
  }
  if (t == 0) {
    dp[x][t] = 0;
    return dp[x][t];
  }
  if (x == n + 1) {
    dp[x][t] = max(dp[x][t - 1], dp[x - 1][t - 1]);
    return dp[x][t];
  }
  int chk = (lu[t % (2 * k)] + d[x] <= l) ? 1 : 0;
  dp[x][t] = max(dp[x][t - 1] & chk, dp[x - 1][t - 1] & chk);
  return dp[x][t];
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k >> l;
    for (int i = 1; i <= n; i++) cin >> d[i];
    for (int i = 0; i <= k; i++) lu[i] = i;
    int tmp = k;
    for (int i = k + 1; i < 2 * k; i++, tmp--) lu[i] = tmp;
    for (int i = 0; i < n + 2; i++)
      for (int j = 0; j < (n + 1) * (k + 1) + 1; j++) magic(i, j);
    string s = (dp[n + 1][(n + 1) * (k + 1)]) ? "Yes" : "No";
    cout << s << '\n';
  }
  return 0;
}
