#include <bits/stdc++.h>
using namespace std;
const int maxn = 500 + 1;
const int maxm = 50000 + 500;
int n, m;
string s, t;
int E, to[maxm], cost[maxm], capa[maxm], flow[maxm], d[maxn], cha[maxn];
void AddEdge(int u, int v, int ca, int co) {
  to[E] = v, cost[E] = co, capa[E] = ca, flow[E] = 0;
  E++;
  to[E] = u, cost[E] = -co, capa[E] = 0, flow[E] = 0;
  E++;
}
int findCost() {
  fill(d, d + n + 2, 1e9);
  d[0] = 0;
  while (1) {
    bool ok = false;
    for (int e = 0; e < E; ++e)
      if (capa[e] > flow[e]) {
        int u = to[e ^ 1], v = to[e];
        if (d[v] > d[u] + cost[e]) {
          d[v] = d[u] + cost[e];
          cha[v] = e;
          ok = true;
        }
      }
    if (!ok) break;
  }
  for (int v = n + 1; v != 0;) {
    int e = cha[v];
    flow[e]++;
    flow[e ^ 1]--;
    v = to[e ^ 1];
  }
  return -d[n ^ 1];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> s >> m;
  s = " " + s;
  while (m--) {
    int t_cost;
    cin >> t >> t_cost;
    int len = t.size();
    for (int i = 1; i <= n - len + 1; ++i)
      if (s.substr(i, len) == t) AddEdge(i, i + len, 1, -t_cost);
  }
  int x;
  cin >> x;
  for (int i = 0; i <= n; ++i) AddEdge(i, i + 1, x, 0);
  int res = 0;
  while (x--) res += findCost();
  cout << res;
  return 0;
}
