#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 100;
const long long INF = 1LL << 60;
struct edge {
  int from, to, num, cost;
  edge(int from = 0, int to = 0, int num = 0, int cost = 0)
      : from(from), to(to), num(num), cost(cost) {}
};
vector<edge> E;
vector<int> t, V[maxn];
long long d[maxn];
long long cost[maxn];
long long Tree(int u, int n) {
  priority_queue<pair<pair<long long, int>, pair<long long, int> >,
                 vector<pair<pair<long long, int>, pair<long long, int> > >,
                 greater<pair<pair<long long, int>, pair<long long, int> > > >
      q;
  fill(cost + 1, cost + n + 1, INF);
  cost[u] = 0;
  long long res = 0;
  for (int i = 0; i < V[u].size(); ++i) {
    edge e = E[V[u][i]];
    int k = u == e.from ? e.to : e.from;
    cost[k] = e.cost;
    q.push(pair<pair<long long, int>, pair<long long, int> >(
        pair<long long, int>(d[k], e.cost), pair<long long, int>(e.num, k)));
  }
  while (!q.empty()) {
    pair<pair<long long, int>, pair<long long, int> > p = q.top();
    q.pop();
    int v = p.second.second;
    if (p.first.second != cost[v]) {
      continue;
    }
    res += cost[v];
    t.push_back(p.second.first + 1);
    for (int i = 0; i < V[v].size(); ++i) {
      edge e = E[V[v][i]];
      int k = v == e.from ? e.to : e.from;
      if (d[k] == d[v] + e.cost && cost[k] > e.cost) {
        cost[k] = e.cost;
        q.push(pair<pair<long long, int>, pair<long long, int> >(
            pair<long long, int>(d[k], cost[k]),
            pair<long long, int>(e.num, k)));
      }
    }
  }
  return res;
}
void Dijkstra(int u, int n) {
  priority_queue<pair<long long, int>, vector<pair<long long, int> >,
                 greater<pair<long long, int> > >
      q;
  fill(d + 1, d + n + 1, INF);
  d[u] = 0;
  q.push(pair<long long, int>(0, u));
  while (!q.empty()) {
    pair<long long, int> p = q.top();
    q.pop();
    int v = p.second;
    if (d[v] != p.first) {
      continue;
    }
    for (int i = 0; i < V[v].size(); ++i) {
      edge e = E[V[v][i]];
      int k = v == e.from ? e.to : e.from;
      if (d[k] > d[v] + e.cost) {
        d[k] = d[v] + e.cost;
        q.push(pair<long long, int>(d[k], k));
      }
    }
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int x, y, l;
    cin >> x >> y >> l;
    E.push_back(edge(x, y, i, l));
    V[x].push_back(i);
    V[y].push_back(i);
  }
  int u;
  cin >> u;
  Dijkstra(u, n);
  cout << Tree(u, n) << endl;
  for (int i = 0; i < t.size(); ++i) {
    cout << t[i] << (i != t.size() ? ' ' : '\n');
  }
  return 0;
}
