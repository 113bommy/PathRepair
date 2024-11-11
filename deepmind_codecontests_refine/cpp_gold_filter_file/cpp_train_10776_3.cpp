#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj(505);
int n, m;
int cor[505] = {0};
int vis[505] = {0};
int dfs(int v, int c) {
  vis[v] = 1;
  cor[v] = c;
  long long vv = 1;
  for (int w : adj[v])
    if (!vis[w] and cor[w] == 0) vv += dfs(w, c);
  return vv;
}
int main() {
  cin >> n >> m;
  int x, y;
  for (int i = 0; i < m; ++i) {
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  int b = 0;
  for (int i = 1; i <= n; ++i)
    if (adj[i].size() == n - 1) {
      vis[i] = 1;
      cor[i] = 1;
      b++;
    }
  int c = 0;
  for (int i = 1; i <= n; ++i)
    if (!vis[i] and cor[i] == 0) {
      c += dfs(i, 2);
      break;
    }
  int a = 0;
  for (int i = 1; i <= n; ++i)
    if (!vis[i] and cor[i] == 0) {
      a += dfs(i, 0);
      break;
    }
  bool flag = true;
  for (int i = 1; i <= n and flag; ++i) {
    if (!vis[i]) flag = 0;
    if (cor[i] == 0 and adj[i].size() != b + a - 1) flag = 0;
    if (cor[i] == 1 and adj[i].size() != a + b + c - 1) flag = 0;
    if (cor[i] == 2 and adj[i].size() != c + b - 1) flag = 0;
  }
  if (flag) {
    cout << "Yes\n";
    for (int i = 1; i <= n; ++i) cout << (char)('a' + cor[i]);
    cout << '\n';
  } else
    cout << "No\n";
  return 0;
}
