#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int k[N], f[N];
int vis[N];
vector<pair<int, int>> ve[N];
int main() {
  int n, m;
  cin >> n >> m;
  memset(f, 0, sizeof(f));
  for (int i = 1; i <= n; i++) cin >> k[i];
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    ve[y].push_back({x, i});
    ve[x].push_back({y, i});
    f[x]++;
    f[y]++;
  }
  queue<int> qu;
  for (int i = 1; i <= n; i++) {
    if (f[i] <= k[i]) qu.push(i);
  }
  memset(vis, 0, sizeof(vis));
  vector<int> ans;
  while (!qu.empty()) {
    int z = qu.front();
    qu.pop();
    for (auto p : ve[z]) {
      if (vis[p.second]) continue;
      vis[p.second] = 1;
      f[p.first]--;
      int h = p.first;
      ans.push_back(p.second);
      if (f[h] == k[h]) qu.push(h);
    }
  }
  if (ans.size() < m)
    printf("DEAD\n");
  else {
    printf("ALIVE\n");
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < m; i++) printf("%d ", ans[i]);
    printf("\n");
  }
}
