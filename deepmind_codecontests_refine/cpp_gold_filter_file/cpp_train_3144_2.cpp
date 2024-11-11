#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 10, MAXM = 2e6 + 10, INF = INT_MAX;
const int MOD = 1e9 + 7, mod = 998244353;
int n, nxt[MAXN], a[MAXN], t;
long long dp[MAXN], ans;
map<int, int> mp[MAXN];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    ans = 0;
    memset(dp, 0, (n + 5) * sizeof(long long));
    memset(nxt, 0, (n + 5) * sizeof(int));
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), mp[i + 1].clear();
    for (int i = n; i; i--) {
      if (mp[i + 1][a[i]] && i < n) {
        int pos = mp[i + 1][a[i]];
        nxt[i] = pos;
        swap(mp[pos + 1], mp[i]);
        if (pos < n) mp[i][a[pos + 1]] = pos + 1;
      }
      mp[i][a[i]] = i;
    }
    for (int i = n; i; i--)
      if (a[i] == a[nxt[i]] && i != nxt[i]) {
        dp[i] = dp[nxt[i] + 1] + 1;
        ans += dp[i];
      }
    printf("%lld\n", ans);
  }
  return 0;
}
