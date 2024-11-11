#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int res = 0;
  char ch;
  while (ch = getchar(), ch < '0' || ch > '9')
    ;
  do {
    res = res * 10 + ch - '0';
  } while (ch = getchar(), ch >= '0' && ch <= '9');
  return res;
}
void write(long long x) {
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
const int N = 2e5 + 5, B = (1 << 30) - 1;
int n, q, p[N], ip[N];
struct Edge {
  int next, to, val;
} a[N << 1];
int head[N], sze;
inline void add(int u, int v, int w) {
  a[++sze].next = head[u], a[sze].to = v, a[sze].val = w, head[u] = sze;
}
inline void insert(int u, int v, int w) { add(u, v, w), add(v, u, w); }
struct node {
  int p;
  long long s1, s2;
  inline node(int P = 0, long long S1 = 0, long long S2 = 0)
      : p(P), s1(S1), s2(S2) {}
  inline bool operator<(const node &a) const { return p < a.p; }
};
vector<node> vec[N];
long long dis[21][N];
int f[N], dep[N];
int sz[N], mx[N] = {N}, rt, tot;
bool vst[N];
void getsize(int u, int fa) {
  sz[u] = 1;
  for (int i = head[u], v; i; i = a[i].next)
    if (!vst[v = a[i].to] && v != fa) getsize(v, u), sz[u] += sz[v];
}
void getrt(int u, int fa) {
  sz[u] = 1, mx[u] = 0;
  for (int i = head[u], v; i; i = a[i].next)
    if (!vst[v = a[i].to] && v != fa)
      getrt(v, u), sz[u] += sz[v], mx[u] = max(mx[u], sz[v]);
  mx[u] = max(mx[u], tot - sz[u]);
  if (mx[u] < mx[rt]) rt = u;
}
void getdis(int d, int u, int fa) {
  for (int i = head[u], v; i; i = a[i].next)
    if (!vst[v = a[i].to] && v != fa)
      dis[d][v] = dis[d][u] + a[i].val, getdis(d, v, u);
}
void solve(int u) {
  vst[u] = 1, getdis(dep[u], u, u);
  for (int i = head[u]; i; i = a[i].next) {
    int v = a[i].to;
    if (vst[v]) continue;
    getsize(v, u), tot = sz[v], rt = 0;
    getrt(v, u), f[rt] = u, dep[rt] = dep[u] + 1, solve(rt);
  }
}
long long lst;
inline void query(int x, int l, int r, long long &d1, long long &d2, int &s) {
  int p1 = upper_bound(vec[x].begin(), vec[x].end(), node(r)) - vec[x].begin();
  if (!p1) return d1 = 0, d2 = 0, s = 0, void();
  --p1;
  int p2 = lower_bound(vec[x].begin(), vec[x].end(), node(l)) - vec[x].begin();
  if (!p2) return d1 = vec[x][p1].s1, d2 = vec[x][p1].s2, s = p1 + 1, void();
  --p2;
  d1 = vec[x][p1].s1 - vec[x][p2].s1, d2 = vec[x][p1].s2 - vec[x][p2].s2,
  s = p2 - p1;
}
inline void update(int x, int y) {
  int rev = 1;
  if (dep[x] < dep[y]) swap(x, y), rev = -1;
  int p1 = x, p2 = y;
  while (dep[x] > dep[y]) {
    int o = lower_bound(vec[x].begin(), vec[x].end(), node(ip[p1])) -
            vec[x].begin();
    vec[x][o].p += rev, x = f[x];
  }
  while (x != y) {
    int o1 = lower_bound(vec[x].begin(), vec[x].end(), node(ip[p1])) -
             vec[x].begin();
    int o2 = lower_bound(vec[y].begin(), vec[y].end(), node(ip[p2])) -
             vec[y].begin();
    vec[x][o1].p += rev, vec[y][o2].p -= rev, x = f[x], y = f[y];
  }
  if (rev == -1) swap(p1, p2);
  while (x) {
    int o1 = lower_bound(vec[x].begin(), vec[x].end(), node(ip[p1])) -
             vec[x].begin(),
        o2 = o1 + 1;
    vec[x][o1].s1 = vec[x][o2].s1 - dis[dep[x]][p1],
    vec[x][o1].s2 = vec[x][o2].s2 - dis[dep[x] - 1][p1];
    x = f[x];
  }
  swap(p[ip[p1]], p[ip[p2]]);
  swap(ip[p1], ip[p2]);
}
int main() {
  n = read(), q = read();
  for (int i = 1; i <= n; ++i) p[i] = read(), ip[p[i]] = i;
  for (int i = 1, u, v, w; i < n; ++i)
    u = read(), v = read(), w = read(), insert(u, v, w);
  tot = n, getrt(1, 0), dep[rt] = 1, solve(rt);
  for (int i = 1; i <= n; ++i) {
    int x = p[i], y = x;
    while (y) {
      vec[y].push_back(node(i, dis[dep[y]][x], dis[dep[y] - 1][x]));
      y = f[y];
    }
  }
  for (int x = 1; x <= n; ++x)
    for (unsigned i = 1; i < vec[x].size(); ++i)
      vec[x][i].s1 += vec[x][i - 1].s1, vec[x][i].s2 += vec[x][i - 1].s2;
  while (q--) {
    int op = read();
    if (op == 1) {
      int l = read() ^ (lst & B), r = read() ^ (lst & B),
          x = read() ^ (lst & B);
      int y = x;
      long long res, w1, w2, l2;
      int ls = 0, ns = 0;
      query(x, l, r, w1, w2, ns);
      res = w1, y = f[y];
      while (y) {
        ls = ns, l2 = w2;
        query(y, l, r, w1, w2, ns);
        res += w1 - l2 + (ns - ls) * dis[dep[y]][x];
        y = f[y];
      }
      write(lst = res), putchar('\n');
    } else {
      int x = read() ^ (lst & B);
      int p1 = p[x], p2 = p[x + 1];
      update(p1, p2);
    }
  }
  return 0;
}
