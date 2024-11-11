#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 10005;
struct edge {
  int to;
  int flow;
  int C;
  int rev;
};
vector<edge> adj[MAX_N];
int dist[MAX_N];
int pos[MAX_N];
int n, m;
int eu[MAX_N], ev[MAX_N];
vector<pair<int, int> > res;
void addEdge(int u, int v, int c) {
  edge a = {v, 0, c, (int)adj[v].size()};
  edge b = {u, 0, 0, (int)adj[u].size()};
  adj[u].push_back(a);
  adj[v].push_back(b);
}
bool BFS(int s, int t) {
  for (int i = 0; i <= n; i++) {
    dist[i] = -1;
  }
  dist[s] = 0;
  queue<int> myqueue;
  myqueue.push(s);
  while (!myqueue.empty()) {
    int u = myqueue.front();
    myqueue.pop();
    if (u == t) {
      break;
    }
    for (int i = 0; i < (int)adj[u].size(); i++) {
      edge e = adj[u][i];
      int v = e.to;
      if (dist[v] == -1 && e.flow < e.C) {
        dist[v] = dist[u] + 1;
        myqueue.push(v);
      }
    }
  }
  return (dist[t] == -1 ? false : true);
}
int sendFlow(int s, int t, int flow, int pos[]) {
  if (s == t) {
    return flow;
  }
  for (; pos[s] < (int)adj[s].size(); pos[s]++) {
    edge &e = adj[s][pos[s]];
    if (dist[e.to] == dist[s] + 1 && e.flow < e.C) {
      int curFlow = min(flow, e.C - e.flow);
      int nxtFlow = sendFlow(e.to, t, curFlow, pos);
      if (nxtFlow > 0) {
        e.flow += nxtFlow;
        adj[e.to][e.rev].flow -= nxtFlow;
        return nxtFlow;
      }
    }
  }
  return 0;
}
int maxFlow(int s, int t) {
  if (s == t) {
    return -1;
  }
  int res = 0;
  while (BFS(s, t)) {
    for (int i = 0; i <= n; i++) {
      pos[i] = 0;
    }
    while (int flow = sendFlow(0, n, INT_MAX, pos)) {
      res += flow;
    }
  }
  return res;
}
void init() {
  for (int i = 0; i <= n; i++) {
    adj[i].clear();
  }
}
bool check(int val) {
  init();
  for (int i = 1; i <= m; i++) {
    addEdge(0, i, 1);
    addEdge(i, m + eu[i], 1);
    addEdge(i, m + ev[i], 1);
  }
  for (int i = 1; i <= n - m - 1; i++) {
    addEdge(i + m, n, val);
  }
  int flow = maxFlow(0, n);
  if (flow == m) {
    res.clear();
    for (int i = 1; i <= m; i++) {
      for (int j = 0; j < (int)adj[i].size(); j++) {
        edge e = adj[i][j];
        if (e.flow == 1) {
          int u = e.to - m;
          res.push_back(make_pair(u, eu[i] + ev[i] - u));
        }
      }
    }
    return true;
  } else {
    return false;
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &eu[i], &ev[i]);
  }
  n += (m + 1);
  int l = 0;
  int r = m;
  int mini;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
      mini = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  printf("%d\n", mini);
  for (int i = 0; i < m; i++) {
    printf("%d %d\n", res[i].first, res[i].second);
  }
  return 0;
}
