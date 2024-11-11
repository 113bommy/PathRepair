#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, i, l1, l2, l3;
long long pre[311111], ans;
long long dp[111111][3];
vector<long long> v[3];
bool cmp(long long x, long long y) { return x > y; }
long long min(long long x, long long y) { return x < y ? x : y; }
long long max(long long x, long long y) { return x > y ? x : y; }
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) {
    scanf("%d%d", &x, &y);
    v[x].push_back(y);
  }
  l1 = (int)v[1].size();
  l2 = (int)v[2].size();
  l3 = (int)v[3].size();
  sort(v[1].begin(), v[1].end(), cmp);
  sort(v[2].begin(), v[2].end(), cmp);
  sort(v[3].begin(), v[3].end(), cmp);
  if (l3) pre[0] = v[3][0];
  for (i = 1; i < l3; i++) pre[i] = pre[i - 1] + v[3][i];
  for (i = 0; i < m; i++) {
    if (dp[i + 1][0] < dp[i][0]) {
      dp[i + 1][0] = dp[i][0];
      dp[i + 1][1] = dp[i][1];
      dp[i + 1][2] = dp[i][2];
    }
    if (dp[i][1] < l1) {
      if (dp[i + 1][0] < dp[i][0] + v[1][dp[i][1]]) {
        dp[i + 1][0] = dp[i][0] + v[1][dp[i][1]];
        dp[i + 1][1] = dp[i][1] + 1;
        dp[i + 1][2] = dp[i][2];
      }
    }
    if (dp[i][2] < l2) {
      dp[i + 2][0] = dp[i][0] + v[2][dp[i][2]];
      dp[i + 2][1] = dp[i][1];
      dp[i + 2][2] = dp[i][2] + 1;
    }
    if (l3 && (m - i) / 3)
      ans = max(ans, dp[i][0] + pre[min((m - i) / 3 - 1, l3 - 1)]);
  }
  ans = max(ans, dp[m][0]);
  printf("%lld", ans);
}
