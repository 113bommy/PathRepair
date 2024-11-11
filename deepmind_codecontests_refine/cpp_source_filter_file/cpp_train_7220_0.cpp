#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, bool> > e[3010];
pair<int, int> q[3010];
int dp[3010];
void dfs1(int x, int fat) {
  dp[x] = 0;
  for (vector<pair<int, bool> >::iterator it = e[x].begin(); it != e[x].end();
       it++) {
    int y = it->first;
    if (y == fat) continue;
    dfs1(y, x);
    dp[x] += dp[y];
    if (!it->second) dp[x]++;
  }
}
void dfs2(int x, int fat, int add, int& res) {
  res = min(res, dp[x] + add);
  for (vector<pair<int, bool> >::iterator it = e[x].begin(); it != e[x].end();
       it++) {
    int y = it->first;
    if (y == fat) continue;
    int _add = add + dp[x] - dp[y];
    if (it->second) {
      _add++;
    } else
      _add--;
    dfs2(y, x, _add, res);
  }
}
int calc(int x, int fat) {
  dfs1(x, fat);
  int now = n;
  dfs2(x, fat, 0, now);
  return now;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    q[i] = make_pair(x, y);
    e[x].push_back(make_pair(y, true));
    e[y].push_back(make_pair(x, false));
  }
  int res = n;
  for (int i = 1; i < n; i++) {
    int x = q[i].first, y = q[i].second;
    res = min(res, calc(x, y) + calc(y, x));
  }
  printf("%d\n", res);
  return 0;
}
