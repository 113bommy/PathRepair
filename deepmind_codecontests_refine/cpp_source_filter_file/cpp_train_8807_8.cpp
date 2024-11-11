#include <bits/stdc++.h>
using namespace std;
const int INF = (int)2e9 + 10;
const int mod = (int)1e9 + 7;
const int N = (int)1e6 + 10;
const long long LLINF = (long long)8e18 + 10;
const double pi = acos(-1.0);
template <typename T1, typename T2>
bool umin(T1 &x, const T2 &y) {
  if (x > y) return x = y, true;
  return false;
}
template <typename T1, typename T2>
bool umax(T1 &x, const T2 &y) {
  if (x < y) return x = y, true;
  return false;
}
template <typename T>
T getint() {
  char c = getchar();
  T p = 1, x = 0;
  while (c == ' ' || c == '\n') c = getchar();
  if (c == '-') p = -1, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * p;
}
struct edge {
  int x, y, cap, flow;
  edge(int X, int Y, int CAP, int FLOW) {
    x = X;
    y = Y;
    cap = CAP;
    flow = FLOW;
  }
};
vector<edge> e;
vector<int> g[N];
int n, m, maxn;
int tox[N], toy[N];
int d[N], ptr[N];
void add(int x, int y, int cap) {
  g[x].push_back(e.size());
  e.push_back(edge(x, y, cap, 0));
  g[y].push_back(e.size());
  e.push_back(edge(y, x, 0, 0));
}
bool bfs(int st, int fi) {
  queue<int> q;
  q.push(st);
  for (int i = 1; i <= maxn; ++i) {
    d[i] = INF;
    ptr[i] = 0;
  }
  d[st] = 0;
  while (q.size()) {
    int v = q.front();
    q.pop();
    for (int i = 0; i < g[v].size(); ++i) {
      int id = g[v][i], u = e[id].y;
      if (e[id].flow < e[id].cap && umin(d[u], d[v] + 1)) q.push(u);
    }
  }
  return d[fi] != INF;
}
int dfs(int v, int fi, int flow) {
  if (v == fi) return flow;
  if (flow == 0) return 0;
  for (; ptr[v] < g[v].size(); ++ptr[v]) {
    int id = g[v][ptr[v]], u = e[id].y;
    if (e[id].flow < e[id].cap && d[u] == d[v] + 1) {
      int push = dfs(u, fi, min(flow, e[id].cap - e[id].flow));
      if (push) {
        e[id].flow += push;
        e[id ^ 1].flow -= push;
        return push;
      }
    }
  }
  return 0;
}
int dinic(int st, int fi) {
  int res = 0;
  while (bfs(st, fi)) {
    while (int pushed = dfs(st, fi, INF)) res += pushed;
  }
  return res;
}
void init(int sz) {
  for (int i = 0; i < n; ++i) {
    e[i * 2].cap = sz;
  }
  for (int i = 0; i < e.size(); ++i) e[i].flow = 0;
}
int main() {
  srand(time(NULL));
  n = getint<int>();
  m = getint<int>();
  maxn = n + m + 2;
  for (int i = 1; i <= n; ++i) {
    add(1, i + 1, 0);
  }
  for (int i = 1; i <= m; ++i) {
    int x = getint<int>(), y = getint<int>();
    add(x + 1, i + n + 1, 1);
    add(y + 1, i + n + 1, 1);
    tox[i] = x;
    toy[i] = y;
  }
  for (int i = 1; i <= m; ++i) {
    add(i + n + 1, maxn, 1);
  }
  int l = 0, r = n;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    init(mid);
    if (dinic(1, maxn) >= m)
      r = mid;
    else
      l = mid;
  }
  init(r);
  dinic(1, maxn);
  printf("%d\n", r);
  for (int i = 0; i < e.size(); i += 2) {
    if (e[i].x == 1 || e[i].y == maxn) continue;
    int tx = tox[e[i].y - n - 1], ty = toy[e[i].y - n - 1];
    if (e[i].flow) printf("%d %d\n", e[i].x - 1, (tx == e[i].x - 1 ? ty : tx));
  }
}
