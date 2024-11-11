#include <bits/stdc++.h>
using namespace std;
const int maxin = 4e2 + 10, maxn = maxin << 1, maxm = maxin * maxin, inf = 1e9;
int sum[maxm], f[maxm], c[maxm], par[maxn], flow, in, m, n;
vector<int> adj[maxn];
long double cost[maxm], ans;
bitset<maxn> mark;
queue<int> q;
pair<int, int> p[maxin];
pair<long double, int> d[maxn];
inline long double dist(int v, int u) {
  return sqrt(pow(p[v].first - p[u].first, 2) +
              pow(p[v].second - p[u].second, 2));
}
inline int rev(int e) { return e < m ? e + m : e - m; }
void edge(int v, int u, int w, int e) {
  adj[v].push_back(e);
  adj[u].push_back(e + m);
  c[e] = w;
  c[e + m] = w;
  f[e + m] = w;
  sum[e] = v + u;
  sum[e + m] = v + u;
  if (min(v, u) && max(v, u) + 1 < n) {
    v = (v - 1) % in;
    u = (u - 1) % in;
    cost[e] = dist(v, u);
    cost[e + m] = -cost[e];
  }
  return;
}
bool spfa() {
  for (int i = 0; i < maxn; ++i) d[i] = {inf, inf};
  memset(par, -1, sizeof(par));
  d[0] = {0, -inf};
  q.push(0);
  mark[0] = true;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    mark[v] = false;
    for (auto e : adj[v])
      if (f[e] < c[e]) {
        int u = sum[e] - v;
        if (d[u] > pair<long double, int>{d[v].first + cost[e],
                                          max(d[v].second, f[e] - c[e])}) {
          d[u] = {d[v].first + cost[e], max(d[v].second, f[e] - c[e])};
          par[u] = e;
          if (!mark[u]) {
            q.push(u);
            mark[u] = true;
          }
        }
      }
  }
  if (d[n - 1].first == inf) return false;
  int in = -d[n - 1].second, v = n - 1;
  flow += in;
  ans += d[n - 1].first * in;
  while (~par[v]) {
    f[par[v]] += in;
    f[rev(par[v])] -= in;
    v = sum[par[v]] - v;
  }
  return true;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> in;
  n = (in << 1) + 2;
  m = in * (in - 1) / 2 + (in << 1) + 1;
  for (int i = 0; i < in; ++i) cin >> p[i].second >> p[i].first;
  sort(p, p + in);
  int all = 0;
  for (int i = 1; i < n - 1; ++i)
    if (i > in)
      edge(i, n - 1, 1, all++);
    else
      edge(0, i, 2, all++);
  edge(0, n - 2, 1, all++);
  for (int i = 0; i < in; ++i)
    for (int j = 0; j < i; ++j)
      if (p[j].first < p[i].first)
        edge(i + 1, j + in + 1, 1, all++);
      else
        break;
  while (spfa())
    ;
  if (flow < in) return cout << "-1\n", 0;
  cout << fixed << setprecision(12) << ans << '\n';
  return 0;
}
