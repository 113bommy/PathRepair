#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 * 1000 + 10;
vector<int> vec[MAXN];
bool mark[MAXN];
int ans = 0, dg[MAXN], dp[MAXN];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (a > b)
      vec[a].push_back(b);
    else
      vec[b].push_back(a);
    dg[a]++;
    dg[b]++;
  }
  for (int i = 0; i < n; i++) {
    if (vec[i].size() == 0)
      dp[i] = 1;
    else
      for (int j = 0; j < vec[i].size(); j++)
        dp[i] = max(dp[i], dp[vec[i][j]] + 1);
    ans = max(ans, dp[i] * dg[i]);
  }
  cout << ans << endl;
}
