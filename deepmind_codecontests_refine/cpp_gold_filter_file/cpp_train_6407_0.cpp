#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e6 + 5;
const int mod = 1000000007;
int vis[N];
vector<int> adj[N];
void dfs(int u, int par) {
  vis[u] = 1;
  for (auto v : adj[u]) {
    if (v == par) continue;
    if (!vis[v]) dfs(v, u);
  }
}
int main() {
  int n, m;
  scanf("%d", &n);
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  if (n - 1 != m) {
    cout << "no\n";
    return 0;
  }
  dfs(1, 0);
  int flag = 0;
  for (int i = 1; i <= n; i++) {
    flag += 1 - (vis[i]);
  }
  printf(flag == 0 ? "yes" : "no");
  printf("\n");
  return 0;
}
