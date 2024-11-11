#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int maxn = 100010;
const int INF = ~0U >> 1;
const double eps = 1e-9;
void getint(int &ret) {
  char ch;
  while (ch = getchar(), ch < '0' || ch > '9')
    ;
  ret = ch - '0';
  while (ch = getchar(), ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0';
}
namespace maxCost {
const int maxn = 200010;
int tot, s, t, Flow, v_tot;
long long Cost;
int nxt[maxn], first[maxn], to[maxn], cap[maxn], cost[maxn], dis[maxn], a[maxn],
    inq[maxn], flow[maxn];
int path[maxn], pre[maxn];
void init(int _s, int _t, int _v_tot) {
  s = _s;
  t = _t;
  v_tot = _v_tot;
  tot = 1;
  Flow = Cost = 0;
  memset(first, 0, sizeof(first));
  memset(flow, 0, sizeof(flow));
}
void add_edge(int x, int y, int z, int COST) {
  nxt[++tot] = first[x];
  first[x] = tot;
  to[tot] = y;
  cap[tot] = z;
  cost[tot] = COST;
  nxt[++tot] = first[y];
  first[y] = tot;
  to[tot] = x;
  cap[tot] = 0;
  cost[tot] = -COST;
}
bool bfs() {
  queue<int> Q;
  Q.push(s);
  inq[s] = 1;
  a[t] = 0;
  a[s] = ~0U >> 3;
  for (int i = 1; i <= v_tot; i++) dis[i] = 1e9;
  dis[s] = 0;
  while (!Q.empty()) {
    int x = Q.front();
    Q.pop();
    inq[x] = 0;
    for (int i = first[x]; i; i = nxt[i])
      if (cap[i] > flow[i] && dis[to[i]] > dis[x] + cost[i]) {
        dis[to[i]] = dis[x] + cost[i];
        a[to[i]] = min(a[x], cap[i] - flow[i]);
        path[to[i]] = i;
        pre[to[i]] = x;
        if (!inq[to[i]]) {
          Q.push(to[i]);
          inq[to[i]] = 1;
        }
      }
  }
  Flow += a[t];
  Cost += 1LL * a[t] * dis[t];
  if (!a[t]) return false;
  int u = t;
  while (u != s) {
    flow[path[u]] += a[t];
    flow[path[u] ^ 1] -= a[t];
    u = pre[u];
  }
  return true;
}
void solve() {
  while (bfs())
    ;
}
}  // namespace maxCost
int du[maxn];
int main() {
  int n, m, ans = 0;
  cin >> n >> m;
  int s = n + 1, t = s + 1;
  maxCost::init(s, t, t);
  for (int i = 1; i <= m; i++) {
    int x, y, c, f;
    scanf("%d%d%d%d", &x, &y, &c, &f);
    du[x] += f;
    du[y] -= f;
    if (c < f) {
      ans += f - c;
      maxCost::add_edge(y, x, f - c, 0);
      maxCost::add_edge(y, x, c, 1);
      maxCost::add_edge(x, y, INF, 2);
    } else {
      maxCost::add_edge(y, x, f, 1);
      maxCost::add_edge(x, y, c - f, 1);
      maxCost::add_edge(x, y, INF, 2);
    }
  }
  maxCost::add_edge(n, 1, INF, 0);
  for (int i = 1; i <= n; i++)
    if (du[i] < 0)
      maxCost::add_edge(s, i, -du[i], 0);
    else
      maxCost::add_edge(i, t, du[i], 0);
  maxCost::solve();
  cout << ans + maxCost::Cost;
  return 0;
}
