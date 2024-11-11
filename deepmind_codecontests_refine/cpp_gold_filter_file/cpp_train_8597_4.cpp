#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int n, k, ed;
pair<int, int> dp[N], tmp[N];
vector<pair<int, int> > g[N];
bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
  return a.first != b.first ? a.first > b.first : a.second > b.second;
}
void dfs(int x = 0, int fa = -1) {
  for (auto &it : g[x])
    if (it.first != fa) dfs(it.first, x);
  ed = 0;
  for (auto &it : g[x])
    if (it.first != fa)
      tmp[++ed] = pair<int, int>(dp[it.first].first + it.second,
                                 dp[it.first].second + it.second);
  if (!ed) return;
  sort(tmp + 1, tmp + 1 + ed, cmp);
  for (int i = 1; i < k && i <= ed; i++) dp[x].first += tmp[i].first;
  int sum = 0;
  for (int i = 1; i <= k && i <= ed; i++) sum += tmp[i].first;
  for (int i = (1); i <= (ed); ++i) {
    if (i <= k) {
      dp[x].second = max(dp[x].second, sum + tmp[i].second - tmp[i].first);
    } else {
      dp[x].second = max(dp[x].second, sum + tmp[i].second - tmp[k].first);
    }
  }
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = (1); i <= (n - 1); ++i) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    g[x].push_back({y, z});
    g[y].push_back({x, z});
  }
  dfs();
  printf("%d\n", max(dp[0].second, dp[0].first));
  return 0;
}
