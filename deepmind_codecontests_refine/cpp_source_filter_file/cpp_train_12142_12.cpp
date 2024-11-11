#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
struct edge {
  int to, cost, cap, flow, rid;
  edge() {}
  edge(int a, int b, int c, int d, int e)
      : to(a), cost(b), cap(c), flow(d), rid(e) {}
};
const int N = 3000, S = N - 1, T = N - 2;
vector<edge> g[N];
void add(int a, int b, int cost, int cap) {
  g[a].push_back(edge(b, cost, cap, 0, g[b].size()));
  g[b].push_back(edge(a, -cost, 0, 0, g[a].size() - 1));
}
int h[N];
void bellman_ford(int s) {
  fill(h, h + N, INF);
  h[s] = 0;
  for (int i = 0; i < N - 1; i++)
    for (int at = 0; at < N; at++)
      for (int j = 0; j < (int)g[at].size(); j++) {
        if (!g[at][j].cap) continue;
        int next = g[at][j].to, w = g[at][j].cost;
        h[next] = min(h[next], h[at] + w);
      }
}
pair<int, int> pai[N];
int dist[N];
int dijkstra(int s, int t) {
  fill(dist, dist + N, INF);
  for (int i = 0; i < N; i++) pai[i] = pair<int, int>(-1, -1);
  priority_queue<pair<int, int>, vector<pair<int, int> >,
                 greater<pair<int, int> > >
      pq;
  dist[s] = 0;
  pq.push(pair<int, int>(0, s));
  bool ret = false;
  while (pq.size()) {
    int at = pq.top().second;
    int d = pq.top().first;
    pq.pop();
    if (at == t) ret = true;
    if (d != dist[at]) continue;
    for (int i = 0; i < (int)g[at].size(); i++) {
      edge edg = g[at][i];
      int next = edg.to;
      if (edg.cap - edg.flow <= 0) continue;
      long long w = dist[at] + edg.cost + h[at] - h[next];
      if (dist[next] > w) {
        dist[next] = w;
        pai[next] = pair<int, int>(at, i);
        pq.push(pair<int, int>(dist[next], next));
      }
    }
  }
  for (int i = 0; i < N; i++)
    if (h[i] < INF and dist[i] < INF) h[i] += dist[i];
  return ret;
}
pair<int, int> max_flow(int s, int t) {
  int cost = 0, flow = 0;
  bellman_ford(s);
  while (dijkstra(s, t)) {
    int f = INF;
    for (int at = t; at != s; at = pai[at].first) {
      edge edg = g[pai[at].first][pai[at].second];
      f = min(f, edg.cap - edg.flow);
    }
    flow += f;
    for (int at = t; at != s; at = pai[at].first) {
      edge &edg = g[pai[at].first][pai[at].second];
      edg.flow += f;
      g[edg.to][edg.rid].flow -= f;
      cost += edg.cost * f;
    }
  }
  return make_pair(cost, flow);
}
int n;
string s;
int b[N];
int jc(int j, int c) { return 111 + (j * ('z' - 'a' + 3)) + c; }
int jt(int j) { return T - 1 - j; }
int main(void) {
  ios_base::sync_with_stdio(false);
  cin >> n >> s;
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n; i++) {
    add(S, i, 0, 1);
    for (int j = 0; j < n; j++) {
      int cost = -b[i] * (i == j);
      add(i, jc(j, s[i] - 'a'), cost, 1);
    }
  }
  for (int i = 0; i < n / 2; i++)
    for (int c = 0; c <= 'z' - 'a'; c++) add(jc(i, c), jc(n - i - 1, c), 0, 1);
  for (int i = n / 2; i < n; i++) {
    for (int c = 0; c <= 'z' - 'a'; c++) add(jc(i, c), jt(i), 0, 1);
    add(jt(i), T, 0, 2);
  }
  pair<int, int> mf = max_flow(S, T);
  cout << -mf.first << endl;
  return 0;
}
