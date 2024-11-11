#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
vector<int> vec[MAXN];
int val[MAXN], n;
int dp[MAXN][2];
void dfs(int x, int fa) {
  for (unsigned i = 0; i < vec[x].size(); i++) {
    int y = vec[x][i];
    if (y == fa) continue;
    dfs(y, x);
    dp[x][0] = max(dp[x][0], dp[y][0]);
    dp[x][1] = max(dp[x][1], dp[y][1]);
  }
  val[x] += dp[x][0] - dp[x][1];
  if (val[x] < 0) dp[x][0] -= val[x];
  if (val[x] > 0) dp[x][1] += val[x];
}
int main() {
  int x, y;
  while (cin >> n) {
    for (int i = 0; i < n + 1; i++) vec[i].clear();
    for (int i = 0; i < n - 1; i++) {
      scanf("%d%d", &x, &y);
      vec[x].push_back(y);
      vec[y].push_back(x);
    }
    for (int i = 1; i < n + 1; i++) scanf("%d", &val[i]);
    memset(dp, 0, sizeof(dp));
    dfs(1, -1);
    cout << dp[1][0] + dp[1][1] << endl;
  }
  return 0;
}
