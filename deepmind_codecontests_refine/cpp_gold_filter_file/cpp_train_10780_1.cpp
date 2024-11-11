#include <bits/stdc++.h>
using namespace std;
void io() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(15);
}
const int INF = 1e9;
const int InfCost = 1e9;
struct MCMF {
  static const int InfCapacity = INF;
  struct Edge {
    int to;
    int rev;
    int capacity;
    int cost;
  };
  vector<vector<Edge> > g;
  void init(int n) { g.assign(n, vector<Edge>()); }
  void add(int i, int j, int capacity = InfCapacity, int cost = int()) {
    Edge e, f;
    e.to = j, f.to = i;
    e.capacity = capacity, f.capacity = 0;
    e.cost = cost, f.cost = -cost;
    g[i].push_back(e);
    g[j].push_back(f);
    g[i].back().rev = (int)g[j].size() - 1;
    g[j].back().rev = (int)g[i].size() - 1;
  }
  void addB(int i, int j, int capacity = InfCapacity, int cost = int()) {
    add(i, j, capacity, cost);
    add(j, i, capacity, cost);
  }
  pair<int, int> minimumCostMaximumFlow(int s, int t, int f = InfCapacity,
                                        bool bellmanFord = false) {
    int n = g.size();
    vector<int> dist(n);
    vector<int> prev(n);
    vector<int> prevEdge(n);
    pair<int, int> total = make_pair(0, 0);
    vector<int> potential(n);
    while (f > 0) {
      fill(dist.begin(), dist.end(), InfCost);
      if (bellmanFord || total.second == 0) {
        dist[s] = 0;
        for (int k = 0; k < n; k++) {
          bool update = false;
          for (int i = 0; i < n; i++)
            if (dist[i] != InfCost)
              for (int ei = 0; ei < (int)g[i].size(); ei++) {
                const Edge &e = g[i][ei];
                if (e.capacity <= 0) continue;
                int j = e.to;
                int d = dist[i] + e.cost;
                if (dist[j] > d) {
                  dist[j] = d;
                  prev[j] = i;
                  prevEdge[j] = ei;
                  update = true;
                }
              }
          if (!update) break;
        }
      } else {
        vector<bool> vis(n);
        priority_queue<pair<int, int> > q;
        q.push(make_pair(-0, s));
        dist[s] = 0;
        while (!q.empty()) {
          int i = q.top().second;
          q.pop();
          if (vis[i]) continue;
          vis[i] = true;
          for (int ei = 0; ei < (int)g[i].size(); ei++) {
            const Edge &e = g[i][ei];
            if (e.capacity <= 0) continue;
            int j = e.to;
            int d = dist[i] + e.cost + potential[i] - potential[j];
            if (d < dist[i]) d = dist[i];
            if (dist[j] > d) {
              dist[j] = d;
              prev[j] = i;
              prevEdge[j] = ei;
              q.push(make_pair(-d, j));
            }
          }
        }
      }
      if (dist[t] == InfCost) break;
      if (!bellmanFord)
        for (int i = 0; i < n; i++) potential[i] += dist[i];
      int d = f;
      int distt = 0;
      for (int v = t; v != s;) {
        int u = prev[v];
        const Edge &e = g[u][prevEdge[v]];
        d = min(d, e.capacity);
        distt += e.cost;
        v = u;
      }
      f -= d;
      total.first += d * distt;
      total.second += d;
      for (int v = t; v != s; v = prev[v]) {
        Edge &e = g[prev[v]][prevEdge[v]];
        e.capacity -= d;
        g[e.to][e.rev].capacity += d;
      }
    }
    return total;
  }
};
int n, m;
vector<string> word;
int p[105];
int main(int argc, char *argv[]) {
  io();
  cin >> n;
  string s;
  cin >> s;
  string w;
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> w >> p[i];
    word.push_back(w);
  }
  int x;
  cin >> x;
  MCMF mcmf;
  mcmf.init(n + 2);
  int src = n;
  int snk = n + 1;
  mcmf.add(src, 0, x, 0);
  mcmf.add(n - 1, snk, x, 0);
  for (int i = 0; i < (n - 1); i++) {
    mcmf.add(i, i + 1, x, 0);
  }
  for (int i = 0; i < m; i++) {
    w = word[i];
    int l = w.length();
    int j;
    for (j = 0; j <= (n - l); j++) {
      if (s.substr(j, l) == w) {
        int to = ((j + l < n) ? (j + l) : snk);
        mcmf.add(j, to, 1, -p[i]);
      }
    }
  }
  pair<int, int> ans = mcmf.minimumCostMaximumFlow(src, snk);
  cout << -ans.first << '\n';
  return 0;
}
