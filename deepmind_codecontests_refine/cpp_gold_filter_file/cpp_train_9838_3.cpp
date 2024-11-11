#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 5005;
const int maxm = 1e4 + 5;
int n;
int num[maxm], l[maxm], r[maxm], cost[maxm], pos, cnt;
long long dp[2][maxm];
map<int, int> M;
long long min(long long a, long long b) { return a < b ? a : b; }
void solve() {
  for (int i = 1; i <= n; ++i) {
    num[2 * i - 1] = l[i];
    num[2 * i] = r[i];
  }
  num[2 * n + 1] = pos;
  sort(num + 1, num + 1 + 2 * n + 1);
  cnt = 1;
  for (int i = 2; i <= 2 * n + 1; ++i) {
    if (num[i] != num[i - 1]) num[++cnt] = num[i];
  }
  num[0] = num[1];
  num[cnt + 1] = num[cnt];
  for (int i = 1; i <= cnt; ++i) M[num[i]] = i;
  pos = M[pos];
  memset(dp, 0x3f, sizeof(dp));
  dp[0][pos] = 0;
  for (int i = 1; i <= n; ++i) {
    int now = i & 1;
    int pre = now ^ 1;
    memset(dp[now], 0x3f, sizeof(dp[now]));
    for (int j = 1; j <= cnt; ++j) {
      cost[j] = (num[j] >= l[i] && num[j] <= r[i])
                    ? 0
                    : min(abs(num[j] - l[i]), abs(num[j] - r[i]));
      dp[now][j] = min(dp[now][j], dp[pre][j] + cost[j]);
    }
    long long dpnum = INF;
    for (int j = 1; j <= cnt; ++j) {
      dpnum += num[j] - num[j - 1];
      dp[now][j] = min(dp[now][j], dpnum + cost[j]);
      dpnum = min(dpnum, dp[pre][j]);
    }
    dpnum = INF;
    for (int j = cnt; j >= 1; --j) {
      dpnum += num[j + 1] - num[j];
      dp[now][j] = min(dp[now][j], dpnum + cost[j]);
      dpnum = min(dpnum, dp[pre][j]);
    }
  }
  long long ans = INF;
  for (int i = 1; i <= cnt; ++i) ans = min(ans, dp[n & 1][i]);
  printf("%lld\n", ans);
}
int main() {
  scanf("%d%d", &n, &pos);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &l[i], &r[i]);
  solve();
  return 0;
}
