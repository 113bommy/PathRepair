#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
inline int read() {
  char c = getchar();
  int t = 0, f = 1;
  while ((!isdigit(c)) && (c != EOF)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while ((isdigit(c)) && (c != EOF)) {
    t = (t << 3) + (t << 1) + (c ^ 48);
    c = getchar();
  }
  return t * f;
}
int n, q;
struct edge {
  int v, p, w;
} e[maxn << 1];
int h[maxn], cnt;
inline void add(int a, int b, int c) {
  e[++cnt].p = h[a];
  e[cnt].v = b;
  e[cnt].w = c;
  h[a] = cnt;
  e[++cnt].p = h[b];
  e[cnt].v = a;
  e[cnt].w = c;
  h[b] = cnt;
}
int dis[maxn], pos;
void bfs(int s) {
  queue<int> q;
  while (!q.empty()) q.pop();
  q.push(s);
  memset(dis, -1, sizeof(dis));
  dis[s] = 0;
  pos = s;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = h[u]; i; i = e[i].p) {
      int v = e[i].v;
      if (dis[v] == -1) {
        dis[v] = dis[u] + e[i].v;
        if (dis[v] > dis[pos]) pos = v;
        q.push(v);
      }
    }
  }
}
int rt1, rt2;
struct tree {
  int f[maxn][22], dep[maxn], mx[maxn], ans[maxn];
  int s[maxn], top = 0, p[maxn], sz[maxn], up_dis[maxn];
  void dfs(int u, int fa) {
    top++;
    sz[u] = 1;
    p[top] = u;
    s[u] = top;
    mx[u] = dep[u];
    f[u][0] = fa;
    for (int i = 1; i <= 20; i++) f[u][i] = f[f[u][i - 1]][i - 1];
    for (int i = h[u]; i; i = e[i].p) {
      int v = e[i].v;
      if (v == fa) continue;
      dep[v] = dep[u] + e[i].w;
      up_dis[v] = e[i].w;
      dfs(v, u);
      mx[u] = max(mx[u], mx[v]);
      sz[u] += sz[v];
    }
  }
  pair<int, int> t[maxn * 4];
  int vis[maxn], tag[maxn * 4];
  void update(int rt) { t[rt] = max(t[rt << 1], t[rt << 1 | 1]); }
  inline void build(int rt, int l, int r) {
    if (l == r) {
      t[rt] = pair<int, int>(dep[p[l]], p[l]);
      return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    update(rt);
  }
  inline void pushdown(int rt) {
    if (!tag[rt]) return;
    tag[rt << 1] += tag[rt];
    tag[rt << 1 | 1] += tag[rt];
    t[rt << 1].first += tag[rt];
    t[rt << 1 | 1].first += tag[rt];
    tag[rt] = 0;
  }
  inline void modify(int rt, int l, int r, int x, int y, int z) {
    if (x <= l && r <= y) {
      t[rt].first += z;
      tag[rt] += z;
      return;
    }
    pushdown(rt);
    int mid = (l + r) >> 1;
    if (x <= mid) modify(rt << 1, l, mid, x, y, z);
    if (y > mid) modify(rt << 1 | 1, mid + 1, r, x, y, z);
    update(rt);
  }
  void pre() {
    for (int i = 1; i <= n; i++) {
      int x = t[1].second;
      ans[i] = ans[i - 1] + t[1].first;
      while (!vis[x] && x) {
        modify(1, 1, n, s[x], s[x] + sz[x] - 1, -up_dis[x]);
        vis[x] = i;
        x = f[x][0];
      }
    }
  }
  inline int query(int x, int y) {
    y = min(y, n);
    if (vis[x] <= y) return ans[y];
    int now = x;
    for (int i = 20; i >= 0; i--) {
      if (vis[f[now][i]] >= y) now = f[now][i];
    }
    now = f[now][0];
    int res = mx[x] - dep[now] + ans[y - 1];
    now = x;
    for (int i = 20; i >= 0; i--) {
      if (vis[f[now][i]] > y) now = f[now][i];
    }
    now = f[now][0];
    return max(res, ans[y] - mx[now] + mx[x]);
  }
} T1, T2;
signed main() {
  n = read(), q = read();
  for (int i = 1; i < n; i++) {
    int a = read(), b = read(), c = read();
    add(a, b, c);
  }
  bfs(1);
  rt1 = pos;
  bfs(pos);
  rt2 = pos;
  T1.dfs(rt1, 0);
  T1.build(1, 1, n);
  T1.pre();
  T2.dfs(rt2, 0);
  T2.build(1, 1, n);
  T2.pre();
  int ans = 0;
  while (q--) {
    int x = (read() + ans - 1) % n + 1, y = (read() + ans - 1) % n + 1;
    printf("%d\n", ans = max(T1.query(x, 2 * y - 1), T2.query(x, 2 * y - 1)));
  }
  return 0;
}
