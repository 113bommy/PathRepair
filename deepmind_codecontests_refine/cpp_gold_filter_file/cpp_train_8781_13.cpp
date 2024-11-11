#include <bits/stdc++.h>
using namespace std;
using type = int;
const type INF = 1000000000;
const type MAXFLOW_LOG = 0;
struct edge {
  int from;
  int to;
  type capacity;
  type cost;
  type flow;
  int next_edge;
};
int n;
vector<edge> edges;
vector<int> first_edge;
vector<type> pot;
void init(int n) { first_edge.assign(n, -1); }
void add_edge(int from, int to, type capacity, type cost) {
  edge e_str = {from, to, capacity, cost, 0, first_edge[from]};
  edge e_inv = {to, from, 0, -cost, 0, first_edge[to]};
  edges.push_back(e_str);
  edges.push_back(e_inv);
  first_edge[from] = edges.size() - 2;
  first_edge[to] = edges.size() - 1;
}
void calc_pot(int s) {
  pot.assign(n, 0);
  return;
  pot[s] = 0;
  bool relaxed;
  for (int i = 0; i < n; i++) {
    relaxed = false;
    for (int j = 0; j < edges.size(); j += 2) {
      edge& e = edges[j];
      if (pot[e.from] < INF && pot[e.from] + e.cost < pot[e.to]) {
        pot[e.to] = pot[e.from] + e.cost;
        relaxed = true;
      }
    }
  }
  if (relaxed) {
    relaxed = true;
  }
}
pair<type, type> dijkstra(int s, int t, type scale) {
  vector<type> dist(n, INF);
  vector<type> p(n, -1);
  vector<bool> used(n, false);
  dist[s] = 0;
  priority_queue<pair<type, int>> q;
  q.push({0, s});
  while (!q.empty()) {
    int v = q.top().second;
    q.pop();
    if (!used[v]) {
      used[v] = true;
      for (int i = first_edge[v]; i != -1; i = edges[i].next_edge) {
        edge& e = edges[i];
        if (e.capacity - e.flow >= scale) {
          type new_dist = dist[e.from] + e.cost + pot[e.from] - pot[e.to];
          if (dist[e.to] > new_dist) {
            dist[e.to] = new_dist;
            p[e.to] = i;
            q.push({-dist[e.to], e.to});
          }
        }
      }
    }
  }
  if (!used[t]) {
    return {0, 0};
  }
  for (int v = 0; v < n; v++) {
    pot[v] += ((dist[v] == INF) ? 0 : dist[v]);
  }
  pair<type, type> flow(INF, 0);
  for (int cur = p[t]; cur != -1; cur = p[edges[cur].from]) {
    flow.first = min(flow.first, edges[cur].capacity - edges[cur].flow);
  }
  for (int cur = p[t]; cur != -1; cur = p[edges[cur].from]) {
    edge& e = edges[cur];
    edge& ie = edges[cur ^ 1];
    flow.second += flow.first * e.cost;
    e.flow += flow.first;
    ie.flow -= flow.first;
  }
  return flow;
}
pair<type, type> run_flow(int s, int t) {
  calc_pot(s);
  pair<type, type> total_flow;
  pair<type, type> curr_flow;
  for (type scale = (type(1) << MAXFLOW_LOG); scale > 0; scale >>= 1) {
    while ((curr_flow = dijkstra(s, t, scale)).first > 0) {
      total_flow.first += curr_flow.first;
      total_flow.second += curr_flow.second;
    }
  }
  return total_flow;
}
void solve() {
  string t;
  getline(cin, t);
  vector<int> cnt(26, 0);
  for (char c : t) cnt[c - 'a']++;
  int m;
  scanf("%d\n", &m);
  n = 26 + 2 + m;
  init(26 + 2 + m);
  for (int i = 0; i < 26; i++) {
    add_edge(i, 27, cnt[i], 0);
  }
  for (int i = 0; i < m; i++) {
    vector<int> cnt(26, 0);
    while (true) {
      char c = getchar();
      if (c == ' ') break;
      cnt[c - 'a']++;
    }
    int a;
    scanf("%d\n", &a);
    for (int j = 0; j < 26; j++) {
      add_edge(26 + 2 + i, j, cnt[j], 0);
    }
    add_edge(26, 26 + 2 + i, a, i + 1);
  }
  pair<type, type> c = run_flow(26, 27);
  printf("%d", (c.first < t.size()) ? -1 : c.second);
}
int main() {
  solve();
  return 0;
}
