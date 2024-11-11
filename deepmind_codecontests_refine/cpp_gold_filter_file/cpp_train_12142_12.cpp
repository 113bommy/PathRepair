#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 88;
const int inf = 1e9 + 88;
const int logn = 22;
const int maxa = 3e6 + 88;
const long long infll = 1e18 + 88;
const char sgl[5] = {'a', 'e', 'i', 'o', 'u'};
const char sep = 'a' - 1;
const double eps = 1e-9;
int mod;
int readint() {
  long long cur;
  scanf("%I64d", &cur);
  return cur;
}
struct _edge {
  int v, to, c, f, cost;
};
int s, t;
vector<_edge> edge;
priority_queue<pair<int, int> > q;
vector<int> g[maxn];
int b[maxn], cnt[26];
int d[maxn], p[maxn], pr[maxn];
string st;
void add_edge(int v, int to, int cap, int cost) {
  g[v].push_back(edge.size());
  edge.push_back({v, to, cap, 0, cost});
  g[to].push_back(edge.size());
  edge.push_back({to, v, 0, 0, -cost});
}
bool dijkstra() {
  int i;
  for (i = 0; i <= t; i++) {
    pr[i] = -1;
    d[i] = inf;
  }
  d[s] = 0;
  q.push({0, s});
  while (!q.empty()) {
    int curd = q.top().first, v = q.top().second;
    q.pop();
    if (curd > d[v]) continue;
    for (i = 0; i < g[v].size(); i++) {
      int id = g[v][i], to = edge[id].to, l = p[v] + edge[id].cost - p[to];
      if (d[v] + l < d[to] && edge[id].c > edge[id].f) {
        d[to] = d[v] + l;
        q.push({-d[to], to});
        pr[to] = id;
      }
    }
  }
  for (i = 0; i <= t; i++) p[i] += d[i];
  return d[t] != inf;
}
void flow() {
  int curflow = inf, v = t;
  while (pr[v] != -1) {
    int id = pr[v];
    curflow = min(curflow, edge[id].c - edge[id].f);
    v = edge[id].v;
  }
  v = t;
  while (pr[v] != -1) {
    int id = pr[v];
    edge[id].f += curflow;
    edge[id ^ 1].f -= curflow;
    v = edge[id].v;
  }
}
int mincostmaxflow() {
  int ans = 0, i;
  while (dijkstra()) flow();
  for (i = 0; i < edge.size(); i++)
    if (edge[i].v < 26 && edge[i].f > 0) ans += edge[i].f * edge[i].cost;
  return ans;
}
void solve() {
  int n, i, j;
  cin >> n;
  cin >> st;
  int mx = 0;
  for (i = 0; i < n; i++) cin >> b[i], mx = max(mx, b[i]);
  for (i = 0; i < n; i++) b[i] = mx - b[i];
  for (i = 0; i < n; i++) cnt[st[i] - 'a']++;
  s = 26 + n / 2;
  t = s + 1;
  for (i = 0; i < 26; i++) add_edge(s, i, cnt[i], 0);
  for (i = 0; i < n / 2; i++) add_edge(i + 26, t, 2, 0);
  for (i = 0; i < 26; i++)
    for (j = 0; j < n / 2; j++) {
      int cost = mx;
      if (st[j] - 'a' == i) cost = b[j];
      if (st[n - j - 1] - 'a' == i) cost = b[n - j - 1];
      if (st[j] == st[n - j - 1] && st[j] - 'a' == i)
        cost = min(b[j], b[n - j - 1]);
      add_edge(i, j + 26, 1, cost);
    }
  printf("%d", mx * n - mincostmaxflow());
}
int main() {
  ios_base::sync_with_stdio(0);
  solve();
  return 0;
}
