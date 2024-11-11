#include <bits/stdc++.h>
using namespace std;
const int N = 52;
const int INF = 1e9;
int mat[N][N];
int n, k;
struct edge {
  int from, to, cap, cost, flow;
  edge(int from, int to, int cap, int cost)
      : from(from), to(to), cap(cap), cost(cost) {
    flow = 0;
  }
};
vector<edge> e;
vector<int> g[N];
void add_edge(int from, int to, int cap, int cost) {
  g[from].push_back(e.size());
  e.push_back(edge(from, to, cap, cost));
  g[to].push_back(e.size());
  e.push_back(edge(to, from, 0, -cost));
}
int d[N];
int ptr[N];
bool bfs() {
  d[1] = 1;
  queue<int> q;
  q.push(1);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int id : g[v]) {
      int to = e[id].to;
      if (e[id].flow == e[id].cap) continue;
      if (d[to] == -1) {
        d[to] = d[v] + 1;
        q.push(to);
      }
    }
  }
  return d[n] != -1;
}
int dfs(int v, int flow) {
  if (!flow || v == n) return flow;
  for (; ptr[v] < (int)g[v].size(); ++ptr[v]) {
    int id = g[v][ptr[v]];
    int to = e[id].to;
    if (d[to] == d[v] + 1) {
      int pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
      if (pushed) {
        e[id].flow += pushed;
        e[id ^ 1].flow -= pushed;
        return pushed;
      }
    }
  }
  return 0;
}
int dinic() {
  int flow = 0;
  while (1) {
    fill(d, d + N, -1);
    fill(ptr, ptr + N, 0);
    if (!bfs()) return flow;
    while (int pushed = dfs(1, INF)) {
      flow += pushed;
    }
  }
  return flow;
}
char in_que[N];
int from[N];
void show(edge e) {
  cout << "(" << e.from << ", " << e.to << ", " << e.flow << ", " << e.cap
       << ", " << e.cost << ")" << endl;
}
vector<int> spfa() {
  fill(d, d + N, INF);
  fill(in_que, in_que + N, 0);
  d[1] = 0;
  queue<int> q;
  q.push(1);
  in_que[1] = 1;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    in_que[v] = 0;
    for (int id : g[v]) {
      int to = e[id].to;
      if (e[id].cap == e[id].flow) continue;
      if (d[to] > d[v] + e[id].cost) {
        d[to] = d[v] + e[id].cost;
        from[to] = id;
        if (!in_que[to]) {
          in_que[to] = 1;
          q.push(to);
        }
      }
    }
  }
  if (d[n] == INF) return {};
  int v = n;
  vector<int> ret;
  while (v != 1) {
    ret.push_back(from[v]);
    v = e[from[v]].from;
  }
  reverse(ret.begin(), ret.end());
  return ret;
}
int mcf(int flow) {
  int cost = 0;
  while (1) {
    vector<int> kek = spfa();
    if (kek.empty()) return flow;
    int delta = 1000000;
    int sum = 0;
    for (int id : kek) {
      delta = min(delta, e[id].cap - e[id].flow);
      sum += e[id].cost;
    }
    if (sum > 0) delta = min(delta, (k - cost) / sum);
    for (int id : kek) {
      e[id].flow += delta;
      e[id ^ 1].flow -= delta;
      cost += e[id].cost * delta;
    }
    flow += delta;
    if (!delta) return flow;
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
      cin >> mat[i][j];
      if (!mat[i][j]) continue;
      add_edge(i, j, mat[i][j], 0);
    }
  int din = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
      if (!mat[i][j]) continue;
      add_edge(i, j, k, 1);
    }
  int ans = mcf(din);
  cout << ans;
}
