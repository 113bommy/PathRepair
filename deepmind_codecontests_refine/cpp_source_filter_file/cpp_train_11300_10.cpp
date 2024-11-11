#include <bits/stdc++.h>
using namespace std;
const int MAX = 112345;
int n, m, a, b, vis[MAX], dis[MAX];
vector<int> adj[MAX];
queue<int> q;
void bfs(int v) {
  memset(dis, 0, sizeof(dis));
  memset(vis, 0, sizeof(dis));
  q.push(v);
  vis[v] = 1;
  while (!q.empty()) {
    int top = q.front();
    q.pop();
    int tam = adj[top].size();
    for (int i = 0; i < tam; i++) {
      int u = adj[top][i];
      if (!vis[u]) {
        dis[u] = dis[top] + 1;
        vis[u] = 1;
        q.push(u);
      }
    }
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  bfs(1);
  int nxt = 0, ans = 0;
  for (int i = 0; i < n; i++)
    if (dis[i] > dis[nxt]) nxt = i;
  bfs(nxt);
  for (int i = 0; i < n; i++) ans = max(ans, dis[i]);
  cout << ans << endl;
  return 0;
}
