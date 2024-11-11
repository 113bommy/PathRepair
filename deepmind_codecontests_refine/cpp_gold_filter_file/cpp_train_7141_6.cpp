#include <bits/stdc++.h>
using namespace std;
using namespace std;
namespace mcmf {
const int INF = 1 << 28;
struct edge {
  int u, v;
  int cap, cost;
  inline edge() {}
  inline edge(int u, int v, int cap, int cost)
      : u(u), v(v), cap(cap), cost(cost) {}
};
int dis[1000010];
vector<struct edge> adj[1000010];
int n, s, t, flag, len[1000010], last[1000010], link[1000010], idx[1000010],
    visited[1000010];
void init(int nodes, int source, int sink, int optimize = 0) {
  flag = optimize, n = nodes, s = source, t = sink;
  for (int i = 0; i < 1000010; i++) {
    adj[i].clear();
    dis[i] = 0, len[i] = 0, last[i] = 0, link[i] = 0, idx[i] = 0,
    visited[i] = 0;
  }
}
inline void addEdge(int u, int v, int f, int c) {
  adj[u].push_back(edge(len[v]++, v, f, c));
  adj[v].push_back(edge(len[u]++, u, 0, -c));
}
bool spfa(int s) {
  int i, v, counter = 0;
  priority_queue<pair<int, int> > PQ;
  if (flag > 0) {
    for (i = 1, dis[s] = 0; i < n; i++) {
      dis[i] = INF, counter = 0;
      for (edge e : adj[i]) {
        if (!e.cap) {
          dis[i] = min(dis[i], dis[e.v] + e.cost);
        }
        counter++;
      }
    }
  } else {
    for (i = 0; i < n; i++) dis[i] = INF, dis[s] = 0;
    PQ.push(make_pair(dis[s], s));
    while (!PQ.empty()) {
      pair<int, int> cur = PQ.top();
      v = cur.second, counter = 0;
      PQ.pop();
      if (-cur.first == dis[v]) {
        for (edge e : adj[v]) {
          if (e.cap > 0 && dis[e.v] > (dis[v] + e.cost)) {
            dis[e.v] = dis[v] + e.cost, last[e.v] = v, link[e.v] = counter;
            PQ.push(make_pair(-dis[e.v], e.v));
          }
          counter++;
        }
      }
    }
  }
  flag &= 666;
  return (dis[t] != INF);
}
inline int dfs(int i, int flow) {
  if (i == t) return flow;
  visited[i] = 1;
  int f = 0, old_flow = flow;
  for (int &j = idx[i]; j < len[i]; j++) {
    edge &e = adj[i][j];
    if (e.cap > 0 && (dis[i] + e.cost) == dis[e.v] && !visited[e.v]) {
      f = dfs(e.v, min(flow, e.cap));
      flow -= f, e.cap -= f;
      adj[e.v][e.u].cap += f;
    }
    if (flow == 0) {
      visited[i] = 0;
      return old_flow - flow;
    }
  }
  return old_flow - flow;
}
inline pair<int, int> solve() {
  int sum = 0, cost = 0, flow = 0;
  while (spfa(s)) {
    sum += dis[t];
    for (int i = 0; i < n; i++) idx[i] = 0, visited[i] = 0;
    int f = dfs(s, INF);
    cost += (sum * f), flow += f;
    for (int i = 0; i < n; i++) {
      for (auto &e : adj[i]) {
        e.cost += (dis[i] - dis[e.v]);
      }
    }
  }
  return make_pair(flow, cost);
}
}  // namespace mcmf
int n, s, t, src;
int a[3005];
bool one(int x) { return (x == 1 || x == -1); }
int ck[100005];
int ck2[15];
int main() {
  cin >> n;
  t = 2 * n + 2;
  src = 2 * n + 1;
  mcmf::init(n * 2 + 3, src, t);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    mcmf::addEdge(s, 2 * i - 1, 1, 0);
    mcmf::addEdge(2 * i - 1, 2 * i, 1, -1);
    mcmf::addEdge(2 * i, t, 1, 0);
  }
  for (int i = 1; i <= n; i++) {
    memset(ck, 0, sizeof(ck));
    memset(ck2, 0, sizeof(ck2));
    for (int j = i + 1; j <= n; j++) {
      if ((a[i] % 7 == a[j] % 7 && ck2[a[j] % 7] <= 7))
        mcmf::addEdge(2 * i, 2 * j - 1, 1, 0), ck2[a[j] % 7]++;
      if ((one(a[i] - a[j])) && ck[a[j]] <= 7)
        mcmf::addEdge(2 * i, 2 * j - 1, 1, 0), ck[a[j]]++;
    }
  }
  mcmf::addEdge(src, s, 4, 0);
  auto ans = mcmf::solve();
  cout << -ans.second << endl;
  return 0;
}
