#include <bits/stdc++.h>
using namespace std;
const int maxn = (1 << 20) + 7;
int n, m, b;
struct node {
  int x, k, c;
} p[105];
bool cmp(node a, node b) { return a.k < b.k; }
int ed;
long long ans = 2000000000000000000;
long long dp[maxn];
int main() {
  scanf("%d%d%d", &n, &m, &b);
  for (int i = 1; i <= n; ++i) {
    int cnt, pid;
    scanf("%d%d%d", &p[i].x, &p[i].k, &cnt);
    for (int j = 1; j <= cnt; ++j) {
      scanf("%d", &pid);
      p[i].c |= 1 << (pid - 1);
    }
  }
  ed = (1 << m) - 1;
  for (int i = 0; i <= ed; ++i) dp[i] = 2000000000000000000;
  sort(p + 1, p + 1 + n, cmp);
  dp[0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= ed; ++j) {
      if (dp[j] + p[i].x < dp[j | p[i].c]) {
        dp[j | p[i].c] = dp[j] + p[i].x;
      }
    }
    ans = min(ans, dp[ed] + 1ll * b * p[i].k);
  }
  if (ans == 2000000000000000000)
    puts("-1");
  else
    printf("%lld\n", ans);
  return 0;
}
