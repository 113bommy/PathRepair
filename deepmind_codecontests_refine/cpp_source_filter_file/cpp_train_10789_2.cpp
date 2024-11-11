#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 7;
const long long INF = 1e16 + 7;
int n, W, B, X, c[N], cost[N];
long long dp[N];
vector<pair<int, int> > gv;
int main() {
  scanf("%d%d%d%d", &n, &W, &B, &X);
  for (int i = (0); i < (n); ++i) scanf("%d", c + i);
  for (int i = (0); i < (n); ++i) scanf("%d", cost + i);
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (c[i]); ++j) gv.push_back(make_pair(cost[i], i));
  n = ((int)(gv).size());
  for (int i = (0); i < (n + 1); ++i) dp[i] = -INF;
  dp[0] = W;
  int last = gv[0].second;
  for (int i = (0); i < (n); ++i) {
    int cost, tree;
    tie(cost, tree) = gv[i];
    if (last != tree) {
      for (int j = (0); j < (i); ++j)
        if (dp[j] >= 0) dp[j] = max(dp[j], min(W + 1ll * j * B, dp[j] + X));
    }
    for (int j = (i + 2) - 1; j >= (1); --j)
      if (dp[j - 1] >= cost)
        dp[j] = max(dp[j], min(W + 1ll * j * B, dp[j - 1] - cost));
    last = tree;
  }
  int ans = 0;
  for (int i = (n + 1) - 1; i >= (1); --i)
    if (dp[i] >= 0) {
      ans = i;
      break;
    }
  printf("%d\n", ans);
  return 0;
}
