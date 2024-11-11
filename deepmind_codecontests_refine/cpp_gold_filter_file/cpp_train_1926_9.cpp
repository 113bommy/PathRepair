#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 35 + 10;
int n, k;
long long dp[maxn][maxn][maxn];
vector<pair<int, int> > q[maxn];
bool judge(int l1, int r1, int l, int r) {
  int v, type;
  for (int i = 0; i < q[l1].size(); i++) {
    v = q[l1][i].first;
    type = q[l1][i].second;
    if (type == 1 && v > l && v < r) return false;
    if (type == 2 && v > l && v != l1 && v < r && v != r1) return false;
    if (type == 3 && v != l1 && v != r1) return false;
  }
  for (int i = 0; i < q[r1].size(); i++) {
    v = q[r1][i].first;
    type = q[r1][i].second;
    if (type == 1 && v > l && v < r) return false;
    if (type == 2 && v > l && v != l1 && v < r && v != r1) return false;
    if (type == 3 && v != l1 && v != r1) return false;
  }
  return true;
}
long long dfs(int l, int r, int num) {
  if (r - l == 1) return 1;
  if (dp[l][r][num] >= 0) return dp[l][r][num];
  long long ans = 0;
  if (judge(l + 1, l + 2, l, r)) ans += dfs(l + 2, r, num + 1);
  if ((l + 2) != (r - 1) && judge(l + 1, r - 1, l, r))
    ans += dfs(l + 1, r - 1, num + 1);
  if ((l + 2) != (r - 1) && judge(r - 1, r - 2, l, r))
    ans += dfs(l, r - 2, num + 1);
  dp[l][r][num] = ans;
  return ans;
}
int main() {
  while (~scanf("%d%d", &n, &k)) {
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < maxn; i++) q[i].clear();
    while (k--) {
      int x, y, type;
      string str;
      cin >> x >> str >> y;
      if (str == ">") type = 1;
      if (str == ">=") type = 2;
      if (str == "=") type = 3;
      if (str == "<=") type = 4;
      if (str == "<") type = 5;
      if (type <= 3)
        q[x].push_back(make_pair(y, type));
      else
        q[y].push_back(make_pair(x, 6 - type));
    }
    printf("%I64d\n", dfs(0, 2 * n + 1, 0));
  }
  return 0;
}
