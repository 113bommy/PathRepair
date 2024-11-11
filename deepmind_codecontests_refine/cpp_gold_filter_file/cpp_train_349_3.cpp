#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 28;
const double INF = 1e12, EPS = 1e-9;
struct Edge {
  int src, dst;
  int weight;
  Edge(int src, int dst, int weight) : src(src), dst(dst), weight(weight) {}
};
bool operator<(const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight
         : e.src != f.src     ? e.src < f.src
                              : e.dst < f.dst;
}
int maximumFlow(const vector<vector<Edge> > &g, int s, int t,
                int limit = 1 << 30) {
  int n = g.size();
  vector<vector<int> > flow(n, vector<int>(n)), capacity(n, vector<int>(n));
  for (int u = 0; u < n; u++)
    for (__typeof((g[u]).begin()) e = (g[u]).begin(); e != (g[u]).end(); e++)
      capacity[e->src][e->dst] += e->weight;
  int total = 0;
  while (total < limit) {
    queue<int> Q;
    Q.push(s);
    vector<int> prev(n, -1);
    prev[s] = s;
    while (!Q.empty() && prev[t] < 0) {
      int u = Q.front();
      Q.pop();
      for (__typeof((g[u]).begin()) e = (g[u]).begin(); e != (g[u]).end(); e++)
        if (prev[e->dst] < 0 && (capacity[u][e->dst] - flow[u][e->dst]) > 0) {
          prev[e->dst] = u;
          Q.push(e->dst);
        }
    }
    if (prev[t] < 0) return total;
    int inc = limit - total;
    for (int j = t; prev[j] != j; j = prev[j])
      inc = min(inc, (capacity[prev[j]][j] - flow[prev[j]][j]));
    for (int j = t; prev[j] != j; j = prev[j])
      flow[prev[j]][j] += inc, flow[j][prev[j]] -= inc;
    total += inc;
  }
}
int n, m, d[500][500];
vector<vector<Edge> > e;
bool visit[500], use[500][500];
int pa[500][500], push_back[500][500], cost[500][500];
int rec(int c) {
  visit[c] = 1;
  int ret = 1;
  for (__typeof((e[c]).begin()) i = (e[c]).begin(); i != (e[c]).end(); i++)
    if (!visit[i->dst]) ret += rec(i->dst);
  return ret;
}
bool can() {
  scanf("%d%d", &n, &m);
  e.clear();
  e.resize(n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) d[i][j] = i == j ? 0 : 1e9;
  for (int i = 0; i < m; i++) {
    int s, t;
    scanf("%d%d", &s, &t);
    s--;
    t--;
    e[s].push_back(Edge(s, t, 1));
    e[t].push_back(Edge(t, s, 1));
    d[s][t] = d[t][s] = 1;
  }
  int flow = maximumFlow(e, 0, n - 1);
  if (flow == 0) return 0;
  if (flow > 1) return 1;
  vector<int> prev(n, -1), path;
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int c = q.front();
    q.pop();
    visit[c] = 1;
    if (c == n - 1) break;
    for (__typeof((e[c]).begin()) i = (e[c]).begin(); i != (e[c]).end(); i++)
      if (prev[i->dst] < 0) prev[i->dst] = c, q.push(i->dst);
  }
  int cur = n - 1;
  for (; cur != 0; cur = prev[cur]) path.push_back(cur);
  path.push_back(0);
  if (path.size() % 2 == 0) return 1;
  for (int i = 0; i < n; i++) visit[i] = 0;
  for (int i = 0; i < path.size(); i++) visit[i] = 1;
  for (__typeof((path).begin()) i = (path).begin(); i != (path).end(); i++)
    for (__typeof((e[*i]).begin()) j = (e[*i]).begin(); j != (e[*i]).end(); j++)
      if (!visit[j->dst]) {
        int ret = rec(j->dst);
        if (ret > 1) return 1;
      }
  return 0;
}
void run() {
  if (!can()) {
    cout << -1 << endl;
    return;
  }
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      pa[i][j] = push_back[i][j] = -1, cost[i][j] = 1e9, use[i][j] = 0;
  priority_queue<pair<int, pair<int, int> > > q;
  q.push(make_pair(-d[0][n - 1], make_pair(0, n - 1)));
  cost[0][n - 1] = 0;
  while (!q.empty()) {
    int a = q.top().second.first, b = q.top().second.second;
    q.pop();
    if (use[a][b]) continue;
    use[a][b] = 1;
    if (a == n - 1 && b == 0) break;
    for (__typeof((e[a]).begin()) i = (e[a]).begin(); i != (e[a]).end(); i++)
      for (__typeof((e[b]).begin()) j = (e[b]).begin(); j != (e[b]).end(); j++)
        if (i->dst != j->dst && cost[i->dst][j->dst] > cost[a][b] + 1)
          pa[i->dst][j->dst] = a, push_back[i->dst][j->dst] = b,
          cost[i->dst][j->dst] = cost[a][b] + 1,
          q.push(make_pair(-max(d[i->dst][n - 1], d[j->dst][0]) - cost[a][b],
                           make_pair(i->dst, j->dst)));
  }
  if (cost[n - 1][0] == 1e9) {
    cout << -1 << endl;
    return;
  }
  vector<int> p, pp;
  int a = n - 1, b = 0;
  for (; a != 0 || b != n - 1;) {
    p.push_back(a), pp.push_back(b);
    int na = pa[a][b], nb = push_back[a][b];
    a = na;
    b = nb;
  }
  p.push_back(0);
  pp.push_back(n - 1);
  reverse((p).begin(), (p).end());
  reverse((pp).begin(), (pp).end());
  printf("%d\n", (int)p.size() - 1);
  for (int i = 0; i < p.size(); i++) printf("%d ", p[i] + 1);
  puts("");
  for (int i = 0; i < p.size(); i++) printf("%d ", pp[i] + 1);
  puts("");
}
int main() { run(); }
