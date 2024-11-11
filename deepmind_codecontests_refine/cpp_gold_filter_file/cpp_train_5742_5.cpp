#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<pair<int, int> > G[200010];
int ans[200010], res;
void DFS(int u, int fa, int pre) {
  int cnt = 0;
  for (auto it : G[u])
    if (it.first != fa) {
      ++cnt;
      if (cnt > res) cnt = 1;
      if (cnt == pre) ++cnt;
      if (cnt > res) cnt = 1;
      ans[it.second] = cnt;
    }
  for (auto it : G[u])
    if (it.first != fa) DFS(it.first, u, ans[it.second]);
}
int main() {
  while (scanf("%d%d", &n, &k) != EOF) {
    for (int i = 1; i <= n; ++i) G[i].clear();
    for (int i = 1, u, v; i < n; ++i) {
      scanf("%d%d", &u, &v);
      G[u].push_back(pair<int, int>(v, i));
      G[v].push_back(pair<int, int>(u, i));
    }
    int l = 1, r = n - 1;
    res = -1;
    while (r - l >= 0) {
      int mid = (l + r) >> 1;
      int tot = 0;
      for (int i = 1; i <= n; ++i)
        if ((int)G[i].size() > mid) ++tot;
      if (tot <= k) {
        res = mid;
        r = mid - 1;
      } else
        l = mid + 1;
    }
    DFS(1, 0, 0);
    printf("%d\n", res);
    for (int i = 1; i < n; ++i) printf("%d%c", ans[i], " \n"[i == n - 1]);
  }
  return 0;
}
