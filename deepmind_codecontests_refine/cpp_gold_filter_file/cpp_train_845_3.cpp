#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
int p[maxn], c[maxn];
bool vis[maxn], ban[maxn];
int que[maxn], ans[maxn];
vector<int> v[maxn];
int link[maxn];
inline bool dfs(int u) {
  for (int i = 0; i < v[u].size(); i++) {
    int t = v[u][i];
    if (vis[t]) continue;
    vis[t] = true;
    if (link[t] == -1 || dfs(link[t])) {
      link[t] = u;
      return true;
    }
  }
  return false;
}
int main() {
  int n, m;
  cin >> n >> m;
  memset(link, -1, sizeof link);
  for (int i = 1; i <= n; i++) cin >> p[i];
  for (int i = 1; i <= n; i++) cin >> c[i];
  int d;
  cin >> d;
  for (int i = 1; i <= d; i++) cin >> que[i], ban[que[i]] = true;
  for (int i = 1; i <= n; i++)
    if (!ban[i]) v[p[i]].push_back(c[i]);
  int cur = 0;
  memset(link, -1, sizeof link);
  for (int i = d; i >= 1; i--) {
    while (true) {
      memset(vis, 0, sizeof(vis));
      if (dfs(cur))
        cur++;
      else
        break;
    }
    ans[i] = cur;
    v[p[que[i]]].push_back(c[que[i]]);
  }
  for (int i = 1; i <= d; i++) cout << ans[i] << endl;
  return 0;
}
