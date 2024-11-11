#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 3e5 + 50;
bool vis[maxn];
int st[maxn], d[maxn];
int n, k, dis, cnt = 0;
struct node {
  int to, w;
  node() {}
  node(int to, int w) : to(to), w(w) {}
};
vector<node> G[maxn];
queue<int> q;
void bfs() {
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < G[u].size(); i++) {
      node tmp = G[u][i];
      int v = tmp.to, edg = tmp.w;
      if (d[v] == -1) {
        d[v] = d[u] + 1;
        q.push(v);
        if (d[v] <= dis) vis[edg] = true;
        ++cnt;
      }
    }
  }
}
int main() {
  memset(d, -1, sizeof(d));
  memset(vis, false, sizeof(vis));
  scanf("%d%d%d", &n, &k, &dis);
  for (int i = 1; i <= k; i++) {
    int u;
    scanf("%d", &u);
    d[u] = 0;
    q.push(u);
  }
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(node(v, i));
    G[v].push_back(node(u, i));
  }
  bfs();
  printf("%d\n", k - 1);
  for (int i = 1; i <= n - 1; i++) {
    if (!vis[i]) printf("%d\n", i);
  }
  return 0;
}
