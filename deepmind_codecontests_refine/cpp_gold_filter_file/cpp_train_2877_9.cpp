#include <bits/stdc++.h>
using namespace std;
int vis[10006];
int colour[10006];
vector<int> adj[10006];
int ans = 0;
void dfs(int N, int clr) {
  stack<int> S;
  S.push(N);
  if (colour[N] != clr) {
    ans++;
  }
  while (!S.empty()) {
    int u = S.top();
    S.pop();
    int l = adj[u].size();
    for (int i = 0; i < l; i++) {
      if (vis[adj[u][i]] == 0) {
        vis[adj[u][i]] = 1;
        colour[adj[u][i]] = clr;
        S.push(adj[u][i]);
      }
    }
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n - 1; i++) {
    int pi;
    scanf("%d", &pi);
    adj[pi].push_back(i + 1);
  }
  for (int i = 1; i <= n; i++) {
    int ci;
    scanf("%d", &ci);
    memset(vis, 0, sizeof vis);
    dfs(i, ci);
  }
  cout << ans << "\n";
  return 0;
}
