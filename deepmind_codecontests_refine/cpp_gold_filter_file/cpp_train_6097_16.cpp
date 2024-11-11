#include <bits/stdc++.h>
const long long N = 2e5;
const long long inf = 0x3f3f3f3f3f3f3f3fLL;
struct Edge {
  long long u, v, w, c;
  long long to, nxt, id;
  long long st;
};
inline bool operator<(Edge a, Edge b) { return a.w < b.w; }
Edge _e[N * 2 + 10], qwq[N * 2 + 10];
long long head[N + 10], tote;
long long n, m, S, fa[N + 10], dep[N + 10], f[N + 10][25];
long long maxx[N + 10][25];
long long sum, minn, minnn;
inline void addEdge(long long u, long long v, long long w) {
  qwq[++tote].to = v;
  qwq[tote].w = w;
  qwq[tote].nxt = head[u];
  head[u] = tote;
}
inline long long getRt(long long u) {
  return fa[u] == u ? u : fa[u] = getRt(fa[u]);
}
inline void Kruskal() {
  std::sort(_e + 1, _e + m + 1);
  for (long long i = 1; i <= n; i++) fa[i] = i;
  minn = inf, minnn = 0;
  for (long long i = 1; i <= m; i++) {
    long long u = _e[i].u, v = _e[i].v, w = _e[i].w, c = _e[i].c;
    if (getRt(u) == getRt(v)) continue;
    if (c < minn)
      _e[i].st = 2, _e[minnn].st = 1, minn = c, minnn = i;
    else
      _e[i].st = 1;
    sum += w;
    fa[getRt(u)] = getRt(v);
    addEdge(u, v, w);
    addEdge(v, u, w);
  }
}
void DFS(long long u, long long _fa, long long w) {
  dep[u] = dep[_fa] + 1;
  f[u][0] = _fa;
  maxx[u][0] = w;
  for (long long i = 1; i <= 20; i++) {
    f[u][i] = f[f[u][i - 1]][i - 1];
    maxx[u][i] = std::max(maxx[u][i - 1], maxx[f[u][i - 1]][i - 1]);
  }
  for (long long i = head[u]; i; i = qwq[i].nxt) {
    long long v = qwq[i].to;
    if (v == _fa) continue;
    DFS(v, u, qwq[i].w);
  }
}
inline long long getLCA(long long u, long long v) {
  if (dep[u] < dep[v]) std::swap(u, v);
  for (long long i = 20; i >= 0; i--)
    if (dep[u] - (1 << i) >= dep[v]) u = f[u][i];
  if (u == v) return u;
  for (long long i = 20; i >= 0; i--)
    if (f[u][i] != f[v][i]) u = f[u][i], v = f[v][i];
  return f[u][0];
}
inline long long getMax(long long u, long long v) {
  long long ans = -inf;
  if (dep[u] < dep[v]) std::swap(u, v);
  for (long long i = 20; i >= 0; i--)
    if (dep[u] - (1 << i) >= dep[v])
      ans = std::max(ans, maxx[u][i]), u = f[u][i];
  if (u == v) return ans;
  for (long long i = 20; i >= 0; i--)
    if (f[u][i] != f[v][i])
      ans = std::max(ans, std::max(maxx[u][i], maxx[v][i])), u = f[u][i],
      v = f[v][i];
  return std::max(ans, std::max(maxx[u][0], maxx[v][0]));
}
inline bool check(long long a, long long b, long long c) {
  long long ab = getLCA(a, b);
  long long bc = getLCA(b, c);
  long long ca = getLCA(c, a);
  if (ab == bc && ca == c) return 1;
  if (ab == ca && bc == c) return 1;
  return 0;
}
signed main() {
  scanf("%lld%lld", &n, &m);
  for (long long i = 1; i <= m; i++) scanf("%lld", &_e[i].w);
  for (long long i = 1; i <= m; i++) scanf("%lld", &_e[i].c);
  for (long long i = 1; i <= m; i++) {
    long long u, v;
    scanf("%lld%lld", &u, &v);
    _e[i].u = u, _e[i].v = v, _e[i].st = 0, _e[i].id = i;
  }
  scanf("%lld", &S);
  Kruskal();
  long long tmpAns = sum;
  long long add = 0;
  sum -= S / minn;
  DFS(1, 0, 0);
  for (long long i = 1; i <= m; i++) {
    long long u = _e[i].u, v = _e[i].v, w = _e[i].w, c = _e[i].c;
    if (!_e[i].st) {
      if (c < minn) {
        long long tmp = tmpAns - getMax(u, v) + w - S / c;
        if (tmp < sum) add = i, sum = tmp;
      }
    }
  }
  printf("%lld\n", sum);
  if (!add) {
    for (long long i = 1; i <= m; i++) {
      if (_e[i].st == 1) printf("%lld %lld\n", _e[i].id, _e[i].w);
      if (_e[i].st == 2) printf("%lld %lld\n", _e[i].id, _e[i].w - S / _e[i].c);
    }
  } else {
    long long U = _e[add].u, V = _e[add].v;
    bool flag = 1;
    for (long long i = 1; i <= m; i++) {
      if (i == add) printf("%lld %lld\n", _e[i].id, _e[i].w - S / _e[i].c);
      if (_e[i].st) {
        if (_e[i].w == getMax(U, V) && check(U, V, _e[i].u) &&
            check(U, V, _e[i].v) && flag) {
          flag = 0;
          continue;
        }
        printf("%lld %lld\n", _e[i].id, _e[i].w);
      }
    }
  }
  return 0;
}
