#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9, N = 2e6 + 100, M = 4e6 + 100, WID = 1e5 + 100;
int head[N], cur[N], dep[N], to[M], lim[M], nxt[M], vis[N], cnt = 1, n, m, s, t;
void add_edge(int u, int v, int l) {
  nxt[++cnt] = head[u], head[u] = cnt, lim[cnt] = l, to[cnt] = v;
  nxt[++cnt] = head[v], head[v] = cnt, lim[cnt] = 0, to[cnt] = u;
}
bool bfs() {
  queue<int> q;
  memset(dep, 0x3f, sizeof(dep));
  memset(vis, 0, sizeof(vis));
  memcpy(cur, head, sizeof(cur));
  dep[s] = 0;
  q.push(s);
  while (!q.empty()) {
    int h = q.front();
    vis[h] = 0;
    q.pop();
    for (int i = head[h]; i; i = nxt[i])
      if ((dep[to[i]] > dep[h] + 1) && lim[i]) {
        dep[to[i]] = dep[h] + 1;
        if (!vis[to[i]]) vis[to[i]] = 1, q.push(to[i]);
      }
  }
  if (dep[t] != 0x3f3f3f3f) return true;
  return false;
}
long long dfs(int rt = s, long long flow = 1e18) {
  if (rt == t) return flow;
  long long f = 0, ans = 0;
  for (int i = cur[rt]; i; i = nxt[i]) {
    cur[rt] = i;
    if (lim[i] && dep[to[i]] == dep[rt] + 1) {
      f = dfs(to[i], min(flow - ans, 1ll * lim[i]));
      if (f) {
        lim[i] -= f;
        lim[i ^ 1] += f;
        ans += f;
        if (ans == flow) break;
      }
    }
  }
  return ans;
}
long long dinic() {
  long long ans = 0, flow;
  while (bfs()) {
    while (flow = dfs()) ans += flow;
  }
  return ans;
}
int id[WID << 2], tag[WID << 2], pos[WID << 2], q, siz;
struct node {
  int u, d;
  node(int d, int u) : d(d), u(u){};
};
vector<node> le[WID], ri[WID];
void build(int rt, int l = 1, int r = n) {
  id[rt] = pos[rt] = ++siz;
  if (l == r) {
    add_edge(id[rt], t, 1);
    return;
  }
  int mid = l + r >> 1;
  build((rt << 1), l, mid);
  build(((rt << 1) | 1), mid + 1, r);
  add_edge(id[rt], id[(rt << 1)], inf);
  add_edge(id[rt], id[((rt << 1) | 1)], inf);
}
void modify(int rt, int L, int R, int l = 1, int r = n) {
  if (l >= L && r <= R) {
    tag[rt] ^= 1;
    if (tag[rt])
      id[rt] = 0;
    else
      id[rt] = pos[rt];
    return;
  }
  int mid = l + r >> 1;
  id[rt] = ++siz;
  if (mid >= L) modify((rt << 1), L, R, l, mid);
  if (mid < R) modify(((rt << 1) | 1), L, R, mid + 1, r);
  if (id[(rt << 1)]) add_edge(id[rt], id[(rt << 1)], inf);
  if (id[((rt << 1) | 1)]) add_edge(id[rt], id[((rt << 1) | 1)], inf);
}
int main() {
  cin >> n >> q;
  s = ++siz, t = ++siz;
  int a, b, c, d;
  build(1);
  for (int i = 1; i <= q; ++i) {
    cin >> a >> b >> c >> d;
    le[a].push_back(node(b, d));
    ri[c + 1].push_back(node(b, d));
  }
  build(1);
  for (int i = 1; i <= n; ++i) {
    for (auto it : ri[i]) modify(1, it.d, it.u);
    for (auto it : le[i]) modify(1, it.d, it.u);
    add_edge(s, id[1], 1);
  }
  cout << dinic() << endl;
}
