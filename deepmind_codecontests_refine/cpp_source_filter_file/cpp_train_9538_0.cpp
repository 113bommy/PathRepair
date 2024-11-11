#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T qmin(const T &a, const T &b) {
  return a < b ? a : b;
}
template <typename T>
inline T qmax(const T &a, const T &b) {
  return a > b ? a : b;
}
template <typename T>
inline void getmin(T &a, const T &b) {
  if (a > b) a = b;
}
template <typename T>
inline void getmax(T &a, const T &b) {
  if (a < b) a = b;
}
inline void fileio(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
const int inf = (int)1e9 + 7;
const long long linf = (long long)1e17 + 7;
const int N = 5e5 + 7, M = N;
int v[M], nxt[M];
int head[N], dep[N], id[N], cnt, par[N], child[N], top[N], sz[N];
long long sum[N], w[N];
long long ans[N];
int q[N];
int n, rt;
inline void addedge(int p, int x, int y) {
  v[p] = y, nxt[p] = head[x], head[x] = p;
}
inline void dfs(int u) {
  sz[u] = 1;
  dep[u] = dep[par[u]] + 1;
  child[u] = 0;
  for (int e = head[u]; e; e = nxt[e]) {
    dfs(v[e]);
    sz[u] += sz[v[e]];
    if (sz[v[e]] > sz[child[u]]) child[u] = v[e];
  }
}
inline void dfs2(int u, int t) {
  id[u] = ++cnt;
  top[u] = t;
  if (child[u]) dfs2(child[u], t);
  for (int e = head[u]; e; e = nxt[e]) {
    if (v[e] == child[u]) continue;
    dfs2(v[e], v[e]);
  }
}
inline void bit_ins(int p, long long v1, long long v2) {
  for (; p <= n; p += p & -p) {
    sum[p] += v1;
    w[p] += v2;
  }
}
inline long long bit_qsum(int p) {
  long long s1 = 0, s2 = 0;
  for (int i = p; i; i ^= i & -i) {
    s1 += sum[i];
    s2 += w[i];
  }
  return s1 + s2 * p;
}
inline void ins(int l, int r, long long v) {
  bit_ins(l, -(l - 1) * v, v);
  bit_ins(r, v * r, -v);
}
inline long long qsum(int l, int r) { return bit_qsum(r) - bit_qsum(l - 1); }
inline void ins(int u, long long v) {
  for (; u; u = par[top[u]]) {
    ins(id[top[u]], id[u], v);
  }
}
inline long long getval(int u) {
  long long ans = 0;
  for (; u; u = par[top[u]]) {
    ans += qsum(id[top[u]], id[u]);
  }
  return ans;
}
inline void getans(int u) {
  for (int e = head[u]; e; e = nxt[e]) {
    ans[v[e]] += ans[u];
    getans(v[e]);
  }
}
int main() {
  scanf("%d", &n);
  for (register int i = (1); i <= (n); ++i) {
    scanf("%d", par + i);
    if (!par[i])
      rt = i;
    else
      addedge(i, par[i], i);
  }
  dfs(rt);
  dfs2(rt, rt);
  int st = 1, ed = 1;
  q[ed] = rt;
  while (st <= ed) {
    int cur = ed;
    for (int i = st; i <= cur; ++i) {
      int u = q[i];
      for (int e = head[u]; e; e = nxt[e]) q[++ed] = v[e];
      ins(u, 1);
    }
    for (int i = st; i <= cur; ++i) {
      ans[q[i]] = getval(q[i]);
    }
    for (int i = st; i <= cur; ++i) {
      ins(q[i], -1);
    }
    st = cur + 1;
  }
  getans(rt);
  for (register int i = (1); i <= (n); ++i) printf("%d ", ans[i] - dep[i]);
  return puts(""), 0;
}
