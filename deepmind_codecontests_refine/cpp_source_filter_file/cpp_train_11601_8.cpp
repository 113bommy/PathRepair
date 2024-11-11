#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int> > > ans;
int cnt[2502], dp[2502];
bool vis[52][52];
int n, m, k;
vector<pair<int, int> > cur;
int res = 0;
void dfs(int i, int j, int d) {
  cur.emplace_back(pair<int, int>(i, j));
  vis[i][j] = 1;
  if (i <= n) {
    if (!vis[i + 1][j] && dp[d + 1] > 0) dfs(i + 1, j, d + 1);
  }
  if (j <= m) {
    if (!vis[i][j + 1] && dp[d + 1] > 0) dfs(i, j + 1, d + 1);
  }
  ans.emplace_back(cur);
  res += cur.size();
  dp[d]--;
  cur.pop_back();
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cnt[i + j - 1]++;
  int sum = 0;
  for (int i = 1; i <= n + m - 1; i++) {
    if (sum + cnt[i] > k) {
      dp[i] = k - sum;
      break;
    }
    dp[i] = cnt[i];
    sum += cnt[i];
  }
  dfs(1, 1, 1);
  printf("%d\n", res);
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++) {
      printf("(%d,%d) ", ans[i][j].first, ans[i][j].second);
    }
    printf("\n");
  }
}
