#include <bits/stdc++.h>
template <typename T>
inline void read(T &x) {
  x = 0;
  char c = getchar();
  bool flag = false;
  while (!isdigit(c)) {
    if (c == '-') flag = true;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 + (c ^ 48), c = getchar();
  if (flag) x = -x;
}
using namespace std;
const int inf = 987654321;
template <typename T>
inline void MIN(T &a, T b) {
  if (b < a) a = b;
}
int n, m, s, t;
struct edge {
  int nxt, to, val, fare;
  edge() {}
  edge(int jzp, int zzz, int lsr, int chr) {
    nxt = jzp, to = zzz, val = lsr, fare = chr;
  }
} e[2001000];
int head[111], ecnt = 1, hcur[111];
inline void addedge(int from, int to, int val, int fare) {
  e[++ecnt] = edge(head[from], to, val, fare);
  head[from] = ecnt;
}
inline void Addedge(int u, int v, int w, int f) {
  addedge(u, v, w, f), addedge(v, u, 0, -f);
}
int que[2001000], front, rear, dis[111];
bool vis[111];
inline bool spfa() {
  memset(dis, 0x3f, sizeof(dis));
  front = rear = 0;
  memcpy(hcur, head, sizeof(head));
  que[++rear] = s;
  dis[s] = 0;
  vis[s] = true;
  while (front < rear) {
    int cur = que[++front];
    vis[cur] = false;
    for (int i = head[cur]; i; i = e[i].nxt) {
      int to = e[i].to;
      if (!e[i].val || dis[to] <= dis[cur] + e[i].fare) continue;
      dis[to] = dis[cur] + e[i].fare;
      if (!vis[to]) vis[to] = true, que[++rear] = to;
    }
  }
  return dis[t] <= 1e9;
}
int dfs(int cur, int limi) {
  if (cur == t || !limi) return limi;
  int flow = 0;
  vis[cur] = true;
  for (int i = hcur[cur]; i; i = e[i].nxt) {
    int to = e[i].to;
    hcur[cur] = i;
    if (vis[to] || dis[to] != dis[cur] + e[i].fare) continue;
    int tmp = dfs(to, min(e[i].val, limi));
    if (!tmp) continue;
    e[i].val -= tmp;
    e[i ^ 1].val += tmp;
    flow += tmp;
    limi -= tmp;
    if (!limi) break;
  }
  vis[cur] = false;
  return flow;
}
vector<int> vec;
int main() {
  read(n), read(m);
  s = 1, t = n;
  for (int i = 1; i <= m; ++i) {
    int u, v, w;
    read(u), read(v), read(w);
    Addedge(u, v, 1, w);
  }
  int mxflow = 0;
  while (spfa()) {
    int tmp = dfs(s, inf);
    for (int i = 1; i <= tmp; ++i) vec.push_back(dis[t]);
    mxflow += tmp;
  }
  for (int i = 1; i < mxflow; ++i) vec[i] += vec[i - 1];
  int q;
  read(q);
  while (q--) {
    int x;
    read(x);
    double ans = inf;
    for (int i = 0; i < mxflow; ++i) MIN(ans, 1.0 * (vec[i] + x) / (i + 1));
    printf("%.8f\n", ans);
  }
  return 0;
}
