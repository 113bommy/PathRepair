#include <bits/stdc++.h>
const int N = 1e4 + 10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int n, m, b;
int up;
struct node {
  int p, num, val;
  bool operator<(const node& rhs) const { return num < rhs.num; }
} op[N];
long long dp[(1 << 20) + 20], ans = 0x3f3f3f3f3f3f3f3f;
int a[120];
void dfs(int x, int now, long long sum) {
  if (sum >= dp[now])
    return;
  else
    dp[now] = sum;
  if ((now | a[x + 1]) != up - 1) return;
  if (sum >= ans) return;
  if (now == up - 1) {
    ans = min(ans, sum);
    return;
  }
  for (int i = x + 1; i < n; i++) {
    if (now == 0)
      dfs(i, now | op[i].p, 1LL * (op[i].val + 1LL * op[i].num * b));
    else
      dfs(i, now | op[i].p, sum + op[i].val);
    dfs(i, now, sum);
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &b);
  up = 1 << m;
  int pp = 0;
  for (int i = 0, x, k, y; i < n; i++) {
    scanf("%d%d%d", &x, &y, &k);
    for (int j = 0, o; j < k; j++) {
      scanf("%d", &o);
      o--;
      op[i].p |= 1 << o;
    }
    op[i].num = y;
    op[i].val = x;
  }
  sort(op, op + n);
  memset(dp, -1, sizeof(dp));
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < up; j++) {
      if (dp[j] == -1) continue;
      int u = j | op[i].p;
      if (dp[u] == -1)
        dp[u] = dp[j] + op[i].val;
      else
        dp[u] = min(dp[u], dp[j] + op[i].val);
    }
    if (dp[up - 1] != -1) ans = min(ans, dp[up - 1] + op[i].num * b);
  }
  if (ans == 0x3f3f3f3f3f3f3f3f)
    cout << -1;
  else
    cout << ans;
  return 0;
}
