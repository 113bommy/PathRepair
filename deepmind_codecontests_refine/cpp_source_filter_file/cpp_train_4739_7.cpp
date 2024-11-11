#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  long long ans = 0;
  int x, y, w;
  vector<pair<int, int> > edge[100010];
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d%d%d", &x, &y, &w);
    edge[x].push_back(make_pair(y, w));
    edge[y].push_back(make_pair(x, w));
    ans += (long long)w * 2;
  }
  long long int dp[100010];
  memset(dp, -1, sizeof dp);
  dp[1] = 0;
  queue<int> Q;
  Q.push(1);
  long long int mx = -1;
  while (!Q.empty()) {
    int temp = Q.front();
    Q.pop();
    int sz = edge[temp].size();
    for (int i = 0; i < sz; i++) {
      int temp2 = edge[temp][i].first;
      if (dp[temp2] == -1) {
        dp[temp2] = dp[temp] + edge[temp][i].second;
        Q.push(temp2);
        mx = max(dp[temp2], mx);
      }
    }
  }
  cout << ans - mx << endl;
  return 0;
}
