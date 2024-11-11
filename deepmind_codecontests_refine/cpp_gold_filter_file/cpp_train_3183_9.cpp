#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
const int inf = 0x3f3f3f3f;
const int s = 1 << 8;
int n, a[maxn], dp[maxn][s], cur[maxn];
vector<int> vec[maxn];
int check(int len) {
  memset(cur, 0, sizeof cur);
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j < s; ++j) dp[i][j] = -inf;
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < s; ++j) {
      if (dp[i][j] == -inf) continue;
      for (int k = 0; k < 8; ++k) {
        if (j & (1 << k)) continue;
        unsigned int t = len + cur[k] - 1;
        if (t >= vec[k].size()) continue;
        dp[vec[k][t] + 1][j | (1 << k)] =
            max(dp[vec[k][t] + 1][j | (1 << k)], dp[i][j]);
        ++t;
        if (t >= vec[k].size()) continue;
        dp[vec[k][t] + 1][j | (1 << k)] =
            max(dp[vec[k][t] + 1][j | (1 << k)], dp[i][j] + 1);
      }
    }
    ++cur[a[i]];
  }
  int ret = -inf;
  for (int i = 0; i <= n; ++i) ret = max(ret, dp[i][s - 1]);
  return ret == -inf ? -1 : len * 8 + ret;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    --a[i];
    vec[a[i]].push_back(i);
  }
  int l = 1, r = n >> 3, r1 = 0, res = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    r1 = check(mid);
    if (r1 != -1) {
      res = max(res, r1);
      l = mid + 1;
    } else
      r = mid - 1;
  }
  if (res == 0)
    for (int i = 0; i < 8; ++i)
      if (vec[i].size()) ++res;
  printf("%d\n", res);
  return 0;
}
