#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 20;
const int MAXS = (1 << 16) + 10;
long long dp[MAXS];
int ans[MAXN], req[MAXN];
bool vis[MAXN];
int main() {
  long long n, y, m;
  cin >> n >> y >> m;
  y -= 2001;
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    req[b - 1] |= (1 << (a - 1));
  }
  memset(ans, -1, sizeof ans);
  for (int i = 0; i < n; i++) {
    for (ans[i] = 0; ans[i] < n; ans[i]++) {
      if (!vis[ans[i]]) {
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        for (int s = 0; s < (1 << n); s++) {
          if (dp[s] > 0) {
            for (int j = 0; j < n; j++) {
              if (!(s & (1 << j))) {
                if ((ans[j] == -1 || ans[j] == __builtin_popcount(s)) &&
                    ((s & req[j]) == req[j])) {
                  dp[s | (1 << j)] += dp[s];
                }
              }
            }
          }
        }
        if (y >= dp[(1 << n) - 1]) {
          y -= dp[(1 << n) - 1];
        } else {
          vis[ans[i]] = true;
          break;
        }
      }
    }
    if (ans[i] >= n) {
      cout << "The times have changed" << endl;
      return 0;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] + 1 << ' ';
  }
  cout << endl;
  return 0;
}
