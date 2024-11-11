#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool chkmin(T &a, const T &b) {
  return b < a ? a = b, 1 : 0;
}
template <typename T>
inline bool chkmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
const int oo = 0x3f3f3f3f;
const int maxn = 500100;
long long dp[maxn + 5][2];
int n, K;
vector<pair<int, int> > adj[maxn + 5];
void dfs(int first, int f = -1) {
  vector<long long> all;
  dp[first][0] = dp[first][1] = 0;
  for (auto second : adj[first])
    if (second.first != f) {
      dfs(second.first, first);
      dp[first][0] += dp[second.first][0];
      dp[first][1] += dp[second.first][0];
      all.push_back(dp[second.first][1] + second.second - dp[second.first][0]);
    }
  sort((all).begin(), (all).end(), greater<long long>());
  for (int i = (0), i_end_ = (min((int((all).size())), K)); i < i_end_; ++i)
    dp[first][0] += max(0LL, all[i]);
  for (int i = (0), i_end_ = (min((int((all).size())), K - 1)); i < i_end_; ++i)
    dp[first][1] += max(0LL, all[i]);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &K);
    for (int i = (0), i_end_ = (n); i < i_end_; ++i) adj[i].clear();
    for (int i = (0), i_end_ = (n - 1); i < i_end_; ++i) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w), --u, --v;
      adj[u].push_back(make_pair(v, w));
      adj[v].push_back(make_pair(u, w));
    }
    dfs(0);
    printf("%lld\n", dp[0][0]);
  }
  return 0;
}
