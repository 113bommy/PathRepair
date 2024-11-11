#include <bits/stdc++.h>
using namespace std;
int n, k, t;
vector<pair<int, int> > G[21];
int cnt;
bool vis[21];
int mid;
void dfs(int x, int sum) {
  if (x > n) {
    cnt++;
    return;
  }
  dfs(x + 1, sum);
  if (cnt >= t) return;
  for (int i = 0; i < (int)G[x].size(); i++) {
    int y = G[x][i].first, w = G[x][i].second;
    if (!vis[y] && sum + w <= mid) {
      vis[y] = true;
      dfs(x + 1, sum + w);
      vis[y] = false;
      if (cnt >= t) return;
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &k, &t);
  for (int i = 1; i <= k; i++) {
    int h, w, r;
    scanf("%d%d%d", &h, &w, &r);
    G[h].push_back(make_pair(w, r));
  }
  int l = 1, r = 1e5;
  while (l <= r) {
    mid = (l + r) >> 1;
    cnt = 0;
    dfs(1, 0);
    if (cnt < t)
      l = mid + 1;
    else
      r = mid - 1;
  }
  printf("%d", l);
  return 0;
}
