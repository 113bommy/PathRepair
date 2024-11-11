#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int siz[100005];
int dp[100005], cnt[100005], fa[100005];
bool vis[100005];
int getfa(int x) {
  if (x == fa[x]) {
    return x;
  } else {
    return fa[x] = getfa(fa[x]);
  }
}
pair<int, int> q[100005];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) siz[i] = 1, fa[i] = i;
  memset(dp, 0x3f3f3f3f, sizeof(dp));
  dp[0] = 0;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    x = getfa(x);
    y = getfa(y);
    if (x != y) {
      fa[x] = y;
      siz[y] += siz[x];
    }
  }
  for (int i = 1; i <= n; i++)
    if (!vis[getfa(i)]) {
      cnt[siz[getfa(i)]]++;
      vis[getfa(i)] = 1;
    }
  for (int i = 1; i <= n; i++)
    if (cnt[i]) {
      for (int j = 0; j < i; j++) {
        int s = 1, t = 0;
        for (int k = j; k <= n; k += i) {
          int now = dp[k];
          if (s <= t) {
            dp[k] = min(dp[k], k / i - q[s].first);
          }
          if (s <= t && q[t].second == k) s++;
          while (s <= t && q[t].first <= k / i - now) {
            t--;
          }
          q[++t] = make_pair(k / i - now, k + cnt[i] * i);
        }
      }
    }
  int ans = 1e9;
  for (int i = 1; i <= n; i++) {
    bool ff = 0;
    int t = i;
    while (t) {
      if (t % 10 != 7 && t % 10 != 4) {
        ff = 1;
        break;
      }
      t /= 10;
    }
    if (!ff) {
      ans = min(ans, dp[i] - 1);
    }
  }
  if (ans >= 1e9) {
    cout << -1;
  } else
    cout << ans;
  return 0;
}
