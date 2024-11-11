#include <bits/stdc++.h>
using namespace std;
const int MAXN = 600;
int dp[MAXN][MAXN], q[MAXN], n;
void fwar(int x) {
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      if (dp[i][j] > dp[i][x] + dp[x][j]) dp[i][j] = dp[i][x] + dp[x][j];
}
long long sum(int x) {
  long long s = 0;
  for (int i = 0; i <= x; ++i)
    for (int j = 0; j <= x; ++j) {
      s += dp[q[i]][q[j]];
    }
  return s;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) cin >> dp[i][j];
  for (int i = n - 1; i >= 0; --i) cin >> q[i];
  vector<long long> ans;
  for (int i = 0; i < n; ++i) {
    fwar(q[i]);
    ans.push_back(sum(i));
  }
  for (int i = n - 1; i >= 0; --i) cout << ans[i] << " ";
  return 0;
}
