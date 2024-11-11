#include <bits/stdc++.h>
using namespace std;
const int maxn = 1002;
const int maxm = 10000;
const int inf = 0x3f3f3f3f;
struct Edge {
  int u, v, cap, cost, next;
} edge[maxm << 1];
int sumflow;
int head[maxn], dist[maxn], pp[maxn], ind;
bool vis[maxn];
void init() {
  ind = 0;
  memset(head, -1, sizeof(head));
}
void addedge(int u, int v, int cap, int cost) {
  edge[ind].u = u;
  edge[ind].v = v;
  edge[ind].cap = cap;
  edge[ind].cost = cost;
  edge[ind].next = head[u];
  head[u] = ind++;
  edge[ind].u = v;
  edge[ind].v = u;
  edge[ind].cap = 0;
  edge[ind].cost = -cost;
  edge[ind].next = head[v];
  head[v] = ind++;
}
bool spfa(int s, int t, int n) {
  int u, v;
  queue<int> qu;
  memset(vis, 0, sizeof(vis));
  memset(pp, -1, sizeof(pp));
  for (int i = 0; i <= n; i++) dist[i] = inf;
  vis[s] = 1;
  dist[s] = 0;
  qu.push(s);
  while (!qu.empty()) {
    u = qu.front();
    qu.pop();
    vis[u] = false;
    for (int i = head[u]; i != -1; i = edge[i].next) {
      v = edge[i].v;
      if (edge[i].cap && dist[v] > dist[u] + edge[i].cost) {
        dist[v] = dist[u] + edge[i].cost;
        pp[v] = i;
        if (!vis[v]) {
          qu.push(v);
          vis[v] = 1;
        }
      }
    }
  }
  if (dist[t] == inf) return false;
  return true;
}
int mp[100][100];
int k;
bool check(int s, int t, int n, int ck) {
  init();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      if (mp[i][j] != 0) {
        addedge(i, j, mp[i][j], 0);
        addedge(i, j, ck, 1);
      }
    }
  addedge(s, 1, ck, 0);
  addedge(t - 1, t, ck, 0);
  int flow = 0;
  int minflow, mincost;
  mincost = 0;
  int tmp;
  while (spfa(s, t, n)) {
    minflow = inf + 1;
    for (int i = pp[t]; i != -1; i = pp[edge[i].u])
      if (edge[i].cap < minflow) {
        minflow = edge[i].cap;
      }
    flow += minflow;
    for (int i = pp[t]; i != -1; i = pp[edge[i].u]) {
      edge[i].cap -= minflow;
      edge[i ^ 1].cap += minflow;
    }
    mincost += dist[t] * minflow;
  }
  sumflow = flow;
  if (sumflow == ck && mincost <= k) return 1;
  return 0;
}
int main() {
  int n;
  while (cin >> n >> k) {
    int mx = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) {
        cin >> mp[i][j];
        mx = max(mp[i][j], mx);
      }
    int low = 0, high = (mx + k) * 2;
    int ans = 0;
    while (low + 1 < high) {
      int mid = (low + high) / 2;
      if (check(0, n + 1, n + 2, mid)) {
        ans = max(ans, mid);
        low = mid;
      } else {
        high = mid;
      }
    }
    cout << ans << endl;
  }
}
