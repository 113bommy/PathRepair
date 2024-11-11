#include <bits/stdc++.h>
using namespace std;
const int maxn = 112345;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
int n, m, k, d[105][105], bit[105][maxn << 2], s, b, c[maxn][4], dis[maxn][3],
    s1[1123], s2[1123], best[maxn], S, T, cnt;
bool used[maxn];
map<int, int> mp;
vector<int> def;
inline int ID(int x) {
  return upper_bound(def.begin(), def.end(), x) - def.begin();
}
inline int get(int x) {
  if (mp.find(x) == mp.end()) mp[x] = ++cnt;
  return mp[x];
}
inline void update(int x, int val, int *bit) {
  while (x <= m) {
    bit[x] = max(bit[x], val);
    x += x & -x;
  }
}
inline int query(int x, int *bit) {
  int ret = -inf;
  while (x) {
    ret = max(ret, bit[x]);
    x -= x & -x;
  }
  return ret;
}
struct edge {
  int to;
  long long cap;
  int rev;
  edge() {}
  edge(int to, long long cap, int rev) : to(to), cap(cap), rev(rev) {}
};
vector<edge> G[2123];
int level[2123], iter[2123];
inline void addedge(int from, int to, long long cap) {
  G[from].push_back(edge(to, cap, G[to].size()));
  G[to].push_back(edge(from, 0, G[from].size() - 1));
}
inline void bfs(int s) {
  memset(level, -1, sizeof level);
  queue<int> que;
  level[s] = 0;
  que.push(s);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (int i = 0; i < (int)G[v].size(); ++i) {
      edge &e = G[v][i];
      if (e.cap > 0 && level[e.to] < 0) {
        level[e.to] = level[v] + 1;
        que.push(e.to);
      }
    }
  }
}
long long dfs(int v, int t, long long f) {
  if (v == t) return f;
  for (int &i = iter[v]; i < (int)G[v].size(); ++i) {
    edge &e = G[v][i];
    if (e.cap > 0 && level[v] < level[e.to]) {
      long long d = dfs(e.to, t, min(f, e.cap));
      if (d > 0) {
        e.cap -= d;
        G[e.to][e.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}
inline long long max_flow(int s, int t) {
  long long flow = 0;
  while (1) {
    bfs(s);
    if (level[t] < 0) return flow;
    memset(iter, 0, sizeof iter);
    int f;
    while ((f = dfs(s, t, INF)) > 0) flow += f;
  }
}
int main() {
  scanf("%d%d", &n, &m);
  memset(dis, 0x3f, sizeof dis);
  for (int i = 1; i <= n; ++i) dis[i][i] = 0;
  for (int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    dis[u][v] = dis[v][u] = 1;
  }
  for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
  scanf("%d%d%d", &s, &b, &k);
  for (int i = 1; i <= s; ++i)
    for (int j = 0; j < 4; ++j) scanf("%d", &c[i][j]);
  for (int i = 1; i <= b; ++i)
    for (int j = 0; j < 3; ++j) scanf("%d", &d[i][j]), def.push_back(d[i][1]);
  for (int i = 1; i <= k; ++i)
    scanf("%d%d", &s1[i], &s2[i]), used[s1[i]] = used[s2[i]] = true;
  sort(def.begin(), def.end());
  def.erase(unique(def.begin(), def.end()), def.end());
  m = def.size();
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) bit[i][j] = -inf;
  for (int i = 1; i <= b; ++i) update(ID(d[i][1]), d[i][2], bit[d[i][0]]);
  for (int i = 1; i <= s; ++i) {
    best[i] = -inf;
    for (int j = 1; j <= n; ++j)
      if (dis[c[i][0]][j] <= c[i][2])
        best[i] = max(best[i], query(ID(c[i][1]), bit[j]));
  }
  for (int i = 1; i <= s; ++i)
    if (best[i] != -inf) best[i] -= c[i][3];
  long long res = 0;
  S = 0, T = 2001;
  for (int i = 1; i <= s; ++i)
    if (!used[i])
      res += max(0, best[i]);
    else {
      if (best[i] >= 0)
        addedge(S, get(i), best[i]), res += best[i];
      else if (best[i] == -inf)
        addedge(get(i), T, INF);
      else
        addedge(get(i), T, -best[i]);
    }
  for (int i = 1; i <= k; ++i) addedge(get(s1[i]), get(s2[i]), INF);
  res -= max_flow(S, T);
  cout << res << endl;
  return 0;
}
