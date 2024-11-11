#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e3 + 100;
const long long mod = 1e9 + 7;
const long long base = 102;
struct MinimumCostMaximumFlow {
  static const int InfCapacity = base;
  static const int InfCost = base;
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
                                        bool useSPFA = false) {
    int n = g.size();
    vector<int> dist(n);
    vector<int> prev(n);
    vector<int> prevEdge(n);
    pair<int, int> total = make_pair(0, 0);
    vector<int> potential(n);
    while (f > 0) {
      fill(dist.begin(), dist.end(), InfCost);
      if (useSPFA || total.second == 0) {
        deque<int> q;
        q.push_back(s);
        dist[s] = 0;
        vector<bool> inqueue(n);
        while (!q.empty()) {
          int i = q.front();
          q.pop_front();
          inqueue[i] = false;
          for (int ei = 0; ei < (int)g[i].size(); ei++) {
            const Edge &e = g[i][ei];
            int j = e.to;
            int d = dist[i] + e.cost;
            if (e.capacity > 0 && d < dist[j]) {
              if (!inqueue[j]) {
                inqueue[j] = true;
                q.push_back(j);
              }
              dist[j] = d;
              prev[j] = i;
              prevEdge[j] = ei;
            }
          }
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
      if (!useSPFA)
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
long long m;
string s1[maxn];
long long c[maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (fopen("t.inp", "r")) {
    freopen("test.inp", "r", stdin);
    freopen("test.ans", "w", stdout);
  }
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long so = 0;
  long long sk = n + 1;
  s = " " + s;
  MinimumCostMaximumFlow man;
  man.init(n + 10);
  cin >> m;
  for (int i = 1; i <= m; i++) cin >> s1[i] >> c[i];
  long long x;
  cin >> x;
  for (int i = 1; i <= n; i++) {
    man.add(i - 1, i, base, 0);
    for (int t = 1; t <= m; t++) {
      long long len = s1[t].length();
      if (i + len - 1 > n) continue;
      bool chk = true;
      for (int j = i; j <= i + len - 1; j++) {
        if (s[j] != s1[t][j - i]) chk = false;
      }
      if (chk) man.add(i, i + len, 1, -c[t]);
    }
  }
  man.add(n, sk, base, 0);
  cout << -man.minimumCostMaximumFlow(so, sk, x).first;
}
