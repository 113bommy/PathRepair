#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long u = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    u = u * 10 + c - '0';
    c = getchar();
  }
  return u * f;
}
struct Edge {
  long long To, Next;
} ed[200005 * 2];
long long n, m, num, d[200005], tot, head[200005], f[200005], s[200005],
    t[200005], w[200005], L[200005], R[200005], fa[200005][20];
long long c[200005 * 4];
void addedge(long long u, long long v) {
  ed[++tot].Next = head[u];
  head[u] = tot;
  ed[tot].To = v;
}
inline long long lowbit(long long x) { return x & -x; }
void dfs(long long x, long long pre) {
  L[x] = ++num;
  d[x] = d[pre] + 1;
  for (long long i = 1; i <= 19; i++) fa[x][i] = fa[fa[x][i - 1]][i - 1];
  for (long long i = head[x]; i; i = ed[i].Next) {
    long long v = ed[i].To;
    if (v == pre) continue;
    dfs(v, x);
  }
  R[x] = num;
}
long long lca(long long x, long long y) {
  if (d[x] < d[y]) swap(x, y);
  for (long long i = 19; i >= 0; i--) {
    if (d[fa[x][i]] >= d[y]) x = fa[x][i];
  }
  for (long long i = 19; i >= 0; i--) {
    if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
  }
  return (x == y ? x : fa[x][0]);
}
void add(long long x, long long p) {
  for (long long i = x; i <= n; i += lowbit(x)) {
    c[x] += p;
  }
}
long long query(long long x) {
  long long res = 0;
  for (; x; x -= lowbit(x)) res += c[x];
  return res;
}
void update(long long x, long long y, long long z) {
  add(x, z);
  add(y + 1, -z);
}
vector<long long> v[200005];
void dp(long long x, long long pre) {
  long long S = 0;
  for (long long i = head[x]; i; i = ed[i].Next) {
    long long v = ed[i].To;
    if (v == pre) continue;
    dp(v, x);
    S += f[v];
  }
  f[x] = S;
  long long sz = v[x].size();
  for (long long i = 0; i < sz; i++) {
    long long pp = v[x][i];
    f[x] = max(f[x], S + query(L[s[pp]]) + query(L[t[pp]]) + w[pp]);
  }
  update(L[x], R[x], S - f[x]);
}
signed main() {
  n = read();
  m = read();
  for (long long i = 2; i <= n; i++)
    addedge(i, fa[i][0] = read()), addedge(fa[i][0], i);
  dfs(1, 0);
  for (long long i = 1; i <= m; i++) {
    s[i] = read();
    t[i] = read();
    w[i] = read();
    v[lca(s[i], t[i])].push_back(i);
  }
  dp(1, 0);
  cout << f[1] << endl;
  return 0;
}
