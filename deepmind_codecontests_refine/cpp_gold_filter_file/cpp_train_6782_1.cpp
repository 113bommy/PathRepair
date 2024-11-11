#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 4000;
const int INF = 1e9;
struct edge {
  int to, c, f, back;
  edge(int to, int c, int f, int back) : to(to), c(c), f(f), back(back) {}
};
vector<edge> g[N];
vector<int> d(N), ptr(N);
int n, h, m;
int s, t;
void add_edge(int v, int u, int c) {
  g[v].push_back({u, c, 0, (int)g[u].size()});
  g[u].push_back({v, 0, 0, (int)g[v].size() - 1});
}
bool bfs() {
  fill(d.begin(), d.end(), INF);
  d[s] = 0;
  queue<int> q;
  q.push(s);
  while ((int)q.size()) {
    int v = q.front();
    q.pop();
    for (auto i : g[v]) {
      if (i.c > i.f && d[i.to] == INF) {
        d[i.to] = d[v] + 1;
        q.push(i.to);
      }
    }
  }
  return d[t] != INF;
}
int dfs(int v, int cur_flow = INF) {
  if (v == t || cur_flow == 0) return cur_flow;
  for (int i = ptr[v]; i < (int)g[v].size(); i++) {
    int u = g[v][i].to;
    if (d[v] + 1 == d[u]) {
      int push = dfs(u, min(cur_flow, g[v][i].c - g[v][i].f));
      if (push) {
        g[v][i].f += push;
        g[u][g[v][i].back].f -= push;
        return push;
      }
    }
    ptr[v]++;
  }
  return 0;
}
int maxFlow() {
  int ret = 0;
  while (bfs()) {
    int cur = dfs(s);
    fill(ptr.begin(), ptr.end(), 0);
    while (cur) {
      ret += cur;
      cur = dfs(s);
    }
  }
  return ret;
}
int get_hash(int x, int y) { return x * 52 + y; }
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> h >> m;
  s = 0, t = N - 1;
  for (int i = 0; i < n; i++) {
    add_edge(s, get_hash(i, 0), INF);
    for (int j = 0; j <= h; j++) {
      add_edge(get_hash(i, j), get_hash(i, j + 1), h * h - j * j);
      add_edge(get_hash(i, j + 1), get_hash(i, j), INF);
    }
    add_edge(get_hash(i, h), t, 0);
  }
  int st = 50 * 55 + 10;
  assert(st + m < N);
  for (int i = 0; i < m; i++) {
    int l, r, x, c;
    cin >> l >> r >> x >> c;
    if (x == h) continue;
    l--;
    r--;
    for (int j = l; j <= r; j++) {
      add_edge(get_hash(j, x + 1), st + i, INF);
    }
    add_edge(st + i, t, c);
  }
  cout << n * h * h - maxFlow() << '\n';
}
