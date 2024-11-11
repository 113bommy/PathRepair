#include <bits/stdc++.h>
int Set(int n, int pos) { return n | (1 << pos); }
int Reset(int n, int pos) { return n & ~(1 << pos); }
int Check(int n, int pos) { return n & (1 << pos); }
using namespace std;
int ans;
bool vis[2002];
vector<int> v, G[2002];
void dfs(int u, int d) {
  ans = max(d, ans);
  vis[u] = true;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (vis[v] == false) {
      dfs(v, d + 1);
    }
  }
}
void solve() {
  memset(vis, false, sizeof(vis));
  ans = 0;
  for (int i = 0; i < v.size(); i++) {
    dfs(i, 1);
  }
  printf("%d\n", ans);
}
int main() {
  int u, vv, n;
  scanf("%d", &n);
  vv = 1;
  while (n--) {
    scanf("%d", &u);
    if (u == -1)
      v.push_back(vv);
    else
      G[u].push_back(vv);
    vv++;
  }
  solve();
  return 0;
}
