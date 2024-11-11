#include <bits/stdc++.h>
using namespace std;
int n;
bool vis[111111], t[111111], g[111111];
vector<vector<int> > adj;
vector<int> ans;
void bfs() {
  queue<pair<int, int> > q;
  q.push(make_pair(0, 0));
  vis[0] = 1;
  while (!q.empty()) {
    int v = q.front().first;
    int s = q.front().second;
    q.pop();
    if (t[v] != g[v]) {
      if (!s)
        s = 1, ans.push_back(v + 1);
      else if (s == 1)
        ans.push_back(v + 1), s = 3;
      else if (s == 2)
        s = 1;
    } else {
      if (s == 1)
        s = 2;
      else if (s == 2)
        s = 0, ans.push_back(v + 1);
      else if (s == 3)
        s = 2, ans.push_back(v + 1);
    }
    for (int i = 0; i < (int)adj[v].size(); ++i) {
      int u = adj[v][i];
      if (!vis[u]) q.push(make_pair(u, s)), vis[u] = 1;
    }
  }
}
int main() {
  scanf("%d", &n);
  adj = vector<vector<int> >(n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--, y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    if (x) t[i] = 1;
  }
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    if (x) g[i] = 1;
  }
  bfs();
  printf("%d\n", ans.size());
  for (size_t i = 0; i < ans.size(); ++i) printf("%d\n", ans[i]);
  return 0;
}
