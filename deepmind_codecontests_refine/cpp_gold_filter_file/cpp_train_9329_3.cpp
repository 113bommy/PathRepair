#include <bits/stdc++.h>
using namespace std;
const int N = 205;
int n, s, t, ct;
int mn[N], mx[N], dis[N], par[N];
vector<int> G[5 * N];
bool vis[5 * N];
struct ed {
  int u, v, cap, cost, id;
} edge[N * N * 10];
void add(int u, int v, int cap, int cost) {
  G[u].push_back(ct);
  edge[ct].u = u, edge[ct].v = v, edge[ct].cap = cap, edge[ct].cost = cost,
  edge[ct].id = ct++;
  G[v].push_back(ct);
  edge[ct].u = v, edge[ct].v = u, edge[ct].cap = 0, edge[ct].cost = -cost,
  edge[ct].id = ct++;
}
long long spfa() {
  memset(dis, 63, sizeof(dis));
  memset(vis, false, sizeof(vis));
  memset(par, -1, sizeof(par));
  queue<int> q;
  q.push(s);
  dis[s] = 0;
  par[s] = -1;
  while (q.size()) {
    int v = q.front();
    q.pop();
    vis[v] = false;
    for (int i = 0; i < (G[v].size()); i++) {
      ed &e = edge[G[v][i]];
      int u = e.v;
      if (e.cap && e.cost + dis[v] < dis[u]) {
        dis[u] = dis[v] + e.cost;
        par[u] = e.id;
        if (!vis[u]) {
          vis[u] = true;
          q.push(u);
        }
      }
    }
  }
  int v = t;
  while (par[v] != -1) {
    ed &e = edge[par[v]];
    e.cap--;
    edge[e.id ^ 1].cap++;
    v = e.u;
  }
  return dis[t];
}
long long flow() {
  long long res = 0;
  for (int i = 0; i < (n); i++) res += spfa();
  return res;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int x, y, tp, q, l, r;
  cin >> n >> q;
  s = 2 * n + 2, t = s + 1;
  for (int i = 0; i < (n); i++) mn[i] = 0, mx[i] = n - 1;
  for (int i = 0; i < (q); i++) {
    cin >> tp >> l >> r >> y;
    l--, r--, y--;
    for (int j = l; j <= r; j++)
      if (tp == 1)
        mn[j] = max(mn[j], y);
      else
        mx[j] = min(mx[j], y);
  }
  for (int i = 0; i < (n); i++)
    if (mn[i] > mx[i]) return cout << "-1", 0;
  for (int i = 0; i < (n); i++) {
    for (int j = mn[i]; j <= mx[i]; j++) add(j, i + n, 1, 0);
  }
  for (int i = 0; i < (n); i++)
    for (int j = 1; j <= n; j++) add(s, i, 1, 2 * j - 1);
  for (int i = 0; i < (n); i++) add(i + n, t, 1, 0);
  cout << flow();
  return 0;
}
