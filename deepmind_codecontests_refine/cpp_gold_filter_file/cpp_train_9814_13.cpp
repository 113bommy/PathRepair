#include <bits/stdc++.h>
using namespace std;
int a[5005], cnt, tmp, nxt, V[5005], j, n, i;
long long dp[2][5005], ans;
struct LS {
  int pos, val;
} ls[5005];
inline bool cmp(LS aa, LS bb) { return aa.val < bb.val; }
int main() {
  cin >> n;
  for (i = 1; i <= n; ++i) cin >> a[i], ls[i].val = a[i], ls[i].pos = i;
  sort(ls + 1, ls + n + 1, cmp);
  ls[0].val = -1000000001;
  for (i = 1; i <= n; ++i) {
    if (ls[i].val != ls[i - 1].val) ++cnt, V[cnt] = ls[i].val;
    a[ls[i].pos] = cnt;
  }
  for (i = 1; i <= a[1]; ++i) dp[0][i] = V[a[1]] - V[i];
  for (i = a[1] + 1; i <= cnt; ++i) dp[0][i] = 0;
  for (i = 2; i <= n; tmp ^= 1, ++i) {
    nxt = tmp ^ 1;
    dp[nxt][0] = 1e16;
    for (j = 1; j <= cnt; ++j)
      dp[nxt][j] = min(dp[nxt][j - 1], dp[tmp][j] + abs(V[a[i]] - V[j]));
  }
  for (ans = 1e16, j = 1; j <= cnt; ++j) ans = min(ans, dp[tmp][j]);
  cout << ans;
}
