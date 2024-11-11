#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
const int MAXM = 1000000;
const int INF = 0x3f3f3f3f;
struct Edge {
  int to, next;
  long long cap, flow;
  long long cost;
} edge[MAXM];
int head[MAXN], tol;
int pre[MAXN];
long long dis[MAXN];
bool vis[MAXN];
int N;
void init(int n) {
  N = n;
  tol = 0;
  memset(head, -1, sizeof(head));
}
void addedge(int u, int v, int cap, long long cost) {
  edge[tol].to = v;
  edge[tol].cap = cap;
  edge[tol].cost = cost;
  edge[tol].flow = 0;
  edge[tol].next = head[u];
  head[u] = tol++;
  edge[tol].to = u;
  edge[tol].cap = 0;
  edge[tol].cost = -cost;
  edge[tol].flow = 0;
  edge[tol].next = head[v];
  head[v] = tol++;
}
bool spfa(int s, int t) {
  queue<int> q;
  for (int i = 0; i < N; i++) {
    dis[i] = INF;
    vis[i] = false;
    pre[i] = -1;
  }
  dis[s] = 0;
  vis[s] = true;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = false;
    for (int i = head[u]; i != -1; i = edge[i].next) {
      int v = edge[i].to;
      if (edge[i].cap > edge[i].flow && dis[v] > dis[u] + edge[i].cost) {
        dis[v] = dis[u] + edge[i].cost;
        pre[v] = i;
        if (!vis[v]) {
          vis[v] = true;
          q.push(v);
        }
      }
    }
  }
  if (pre[t] == -1)
    return false;
  else
    return true;
}
int minCostMaxflow(int s, int t, long long& cost) {
  int flow = 0;
  cost = 0;
  while (spfa(s, t)) {
    long long Min = INF;
    for (int i = pre[t]; i != -1; i = pre[edge[i ^ 1].to]) {
      if (Min > edge[i].cap - edge[i].flow) Min = edge[i].cap - edge[i].flow;
    }
    for (int i = pre[t]; i != -1; i = pre[edge[i ^ 1].to]) {
      edge[i].flow += Min;
      edge[i ^ 1].flow -= Min;
      cost += edge[i].cost * Min;
    }
    flow += Min;
  }
  return flow;
}
int f[5005];
int d[5005];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> f[i];
  for (int i = 1; i <= n; i++) cin >> d[i];
  int s = 0, t = 2 * (n + 1);
  long long ans = INF;
  for (int p = 1; p <= k; p++) {
    init(t + 1);
    addedge(0, 1, p, 0);
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (f[i] == f[j])
          addedge(2 * i + 1, 2 * j, 1, 0);
        else
          addedge(2 * i + 1, 2 * j, 1, d[f[j]]);
      }
    }
    for (int i = 1; i <= n; i++) {
      addedge(2 * i, 2 * i + 1, 1, -INF);
      addedge(1, 2 * i, 1, d[f[i]]);
      addedge(2 * i + 1, t, 1, 0);
    }
    long long cost;
    minCostMaxflow(s, t, cost);
    cost += (long long)n * INF;
    ans = min(ans, cost);
  }
  cout << ans << endl;
  return 0;
}
