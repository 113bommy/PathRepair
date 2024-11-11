#include <bits/stdc++.h>
using namespace std;
const int N = 1e3, OO = 0x3f3f3f3f;
int d() {
  int ret;
  scanf("%d", &ret);
  return ret;
}
long long lld() {
  long long ret;
  scanf("%lld", &ret);
  return ret;
}
vector<pair<int, int>> adj;
int vis[200];
void dfs(int u) {
  vis[u] = 1;
  for (int i = 0; i < adj.size(); i++) {
    if (vis[i]) continue;
    if (adj[i].first > adj[u].first && adj[i].first < adj[u].second)
      dfs(i);
    else if (adj[i].second > adj[u].first && adj[i].second < adj[u].second)
      dfs(i);
  }
}
int main() {
  int n = d();
  int j = 0;
  for (int i = 0; i < n; i++) {
    int x = d(), a = d(), b = d();
    if (x == 1)
      adj.push_back({a, b});
    else {
      memset(vis, 0, sizeof vis);
      a--;
      b--;
      dfs(a);
      if (vis[b])
        puts("YES");
      else
        puts("NO");
    }
  }
}
