#include <bits/stdc++.h>
using namespace std;
long long cnt, cnt_e;
vector<int> g[100001];
int vis[100001];
int flag = 0;
void dfs(int first, int p) {
  vis[first] = 1;
  for (int u : g[first]) {
    if (!vis[u])
      dfs(u, first);
    else if (vis[u] && u != p)
      flag = 1;
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      flag = 0;
      dfs(i, -1);
      if (!flag) ans++;
    }
  }
  cout << ans;
}
