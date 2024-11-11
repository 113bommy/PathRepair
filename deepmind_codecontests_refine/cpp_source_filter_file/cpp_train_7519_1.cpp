#include <bits/stdc++.h>
using namespace std;
mt19937_64 mt(time(0));
const int MAXN = 1e4 + 10;
int nums[MAXN];
int dp[MAXN][1001];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(10);
  cout << fixed;
  int n, m, g, r;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> nums[i];
  }
  cin >> g >> r;
  sort(nums, nums + m);
  memset(dp, -1, sizeof(dp));
  deque<pair<int, int> > dq;
  dp[0][0] = 0;
  dq.emplace_back(0, 0);
  while (!dq.empty()) {
    pair<int, int> item = dq.front();
    dq.pop_front();
    int i = item.first;
    int j = item.second;
    if (j == g) {
      if (dp[i][0] == -1 || dp[i][0] > dp[i][j] + 1) {
        dp[i][0] = dp[i][j] + 1;
        dq.emplace_back(i, 0);
      }
    }
    for (int delta = -1; delta <= 1; delta += 2) {
      if (i + delta < 0 || i + delta >= n) continue;
      int tmp = abs(nums[i] - nums[i + delta]);
      if (tmp + j > g) continue;
      if (dp[i + delta][tmp + j] == -1 || dp[i + delta][tmp + j] > dp[i][j]) {
        dp[i + delta][tmp + j] = dp[i][j];
        dq.emplace_front(i + delta, tmp + j);
      }
    }
  }
  int ret = INT_MAX;
  for (int i = 0; i <= g; i++) {
    if (dp[m - 1][i] == -1) continue;
    int tmp = dp[m - 1][i] * (r + g) + i;
    ret = min(ret, tmp);
  }
  if (ret == INT_MAX) ret = -1;
  cout << ret << endl;
  return 0;
}
