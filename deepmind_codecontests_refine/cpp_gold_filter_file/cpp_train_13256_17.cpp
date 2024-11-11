#include <bits/stdc++.h>
using namespace std;
inline int L(int i) { return i << 1; }
inline int R(int i) { return (i << 1) | 1; }
inline int B(int i) { return 1 << i; }
inline int low_bit(int x) { return x & (-x); }
int a[4010], b[4010], l, n;
int dp[110][2][4010];
int dfs(int id, int cho, int ll) {
  int ret = 0, ppp, pre;
  if (id == -1)
    ppp = 101;
  else
    ppp = id;
  if (id == -1)
    pre = 101;
  else if (cho == 0)
    pre = a[id];
  else
    pre = b[id];
  if (ll > l) return dp[ppp][cho][ll] = 0;
  if (ll == l) return dp[ppp][cho][ll] = 1;
  if (dp[ppp][cho][ll] >= 0) return dp[ppp][cho][ll];
  for (int i = 0; i < n; i++)
    if (i != id) {
      if (id == -1) {
        ret = (ret + dfs(i, 1, ll + a[i])) % 1000000007;
        if (a[i] == b[i]) continue;
        ret = (ret + dfs(i, 0, ll + b[i])) % 1000000007;
        continue;
      }
      if (a[i] == pre) {
        ret = (ret + dfs(i, 1, ll + a[i])) % 1000000007;
      } else if (b[i] == pre) {
        ret = (ret + dfs(i, 0, ll + b[i])) % 1000000007;
      }
    }
  return dp[ppp][cho][ll] = ret;
}
int main() {
  while (scanf("%d%d", &n, &l) != EOF) {
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++) scanf("%d%d", &a[i], &b[i]);
    printf("%d\n", dfs(-1, 0, 0));
  }
  return 0;
}
