#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const LL mod = 1e9 + 7;
int n, k, u, v;
vector<int> graph[205];
LL dp[205][205];
bool vis[205];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i < n; ++i) {
      scanf("%d%d", &u, &v);
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
    if (k > 2) {
      LL ans = 0;
      for (int i = 1; i <= n; ++i) {
        fill_n(vis + 1, n, false);
        vis[i] = true;
        vector<int> cnt(graph[i].size(), 0);
        queue<tuple<int, int, int>> quu;
        for (int j = 0; j < graph[i].size(); ++j) {
          quu.push({graph[i][j], j, 1});
        }
        int nowHeight = 1;
        while (!quu.empty()) {
          auto cur = quu.front();
          quu.pop();
          vis[get<0>(cur)] = true;
          if (get<2>(cur) > nowHeight) {
            dp[0][0] = 1;
            for (int j = 1; j <= graph[i].size(); ++j) {
              for (int l = 0; l <= k; ++l) {
                dp[j][l] = (dp[j - 1][l] + dp[i][l]) % mod;
                if (l > 0) {
                  dp[j][l] =
                      (dp[j - 1][l - 1] * cnt[j - 1] % mod + dp[j][l]) % mod;
                }
              }
            }
            ans = (ans + dp[graph[i].size()][k]) % mod;
            for (int j = 0; j <= graph[i].size(); ++j) {
              for (int l = 0; l <= k; ++l) {
                dp[j][l] = 0;
              }
            }
            fill_n(cnt.begin(), graph[i].size(), 0);
            ++nowHeight;
          }
          ++cnt[get<1>(cur)];
          for (auto nxt : graph[get<0>(cur)]) {
            if (vis[nxt]) continue;
            quu.push({nxt, get<1>(cur), get<2>(cur) + 1});
          }
        }
        dp[0][0] = 1;
        for (int j = 1; j <= graph[i].size(); ++j) {
          for (int l = 0; l <= k; ++l) {
            dp[j][l] = (dp[j - 1][l] + dp[i][l]) % mod;
            if (l > 0) {
              dp[j][l] = (dp[j - 1][l - 1] * cnt[j - 1] % mod + dp[j][l]) % mod;
            }
          }
        }
        ans = (ans + dp[graph[i].size()][k]) % mod;
        for (int j = 0; j <= graph[i].size(); ++j) {
          for (int l = 0; l <= k; ++l) {
            dp[j][l] = 0;
          }
        }
        fill_n(cnt.begin(), graph[i].size(), 0);
      }
      printf("%lld\n", ans);
    } else {
      printf("%lld\n", 1ll * n * (n - 1) / 2 % mod);
    }
    for (int i = 1; i <= n; ++i) {
      graph[i].clear();
    }
  }
  return 0;
}
