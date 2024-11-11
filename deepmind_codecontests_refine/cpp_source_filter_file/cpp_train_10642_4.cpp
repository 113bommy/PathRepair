#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void cmin(T &a, T b) {
  ((a > b) && (a = b));
}
template <class T>
inline void cmax(T &a, T b) {
  ((a < b) && (a = b));
}
char IO;
template <class T = int>
T rd() {
  T s = 0;
  int f = 0;
  while (!isdigit(IO = getchar())) f |= IO == '-';
  do s = (s << 1) + (s << 3) + (IO ^ '0');
  while (isdigit(IO = getchar()));
  return f ? -s : s;
}
const int N = 3e5 + 10, INF = 1e9 + 10;
int n, m, k;
vector<int> G[N], E[N];
int L[N], R[N], I[N], dfn, fa[N][20], dep[N];
void dfs(int u, int f) {
  I[L[u] = ++dfn] = u;
  dep[u] = dep[fa[u][0] = f] + 1;
  for (int i = 1, iend = 19; i <= iend; ++i) fa[u][i] = fa[fa[u][i - 1]][i - 1];
  for (int v : G[u])
    if (v != f) dfs(v, u);
  R[u] = dfn;
}
int LCA(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  for (int i = 0, del = dep[x] - dep[y]; (1 << i) <= del; ++i)
    if (del & (1 << i)) x = fa[x][i];
  if (x == y) return x;
  for (int i = 18, iend = 0; i >= iend; --i)
    if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
  return fa[x][0];
}
int vis[N], S[N], T;
void Link(int u, int v) { E[u].push_back(v), E[v].push_back(u); }
void Ins(int u) {
  if (S[T] == u) return;
  E[u].clear(), vis[u] = 0;
  if (!T) return void(S[++T] = u);
  int lca = LCA(u, S[T]);
  if (lca == S[T]) return void(S[++T] = u);
  while (T > 1 && L[S[T - 1]] >= L[lca]) Link(S[T], S[T - 1]), T--;
  if (S[T] != lca) vis[lca] = 0, E[lca].clear(), Link(lca, S[T]), S[T] = lca;
  S[++T] = u;
}
int P[N], B[N], Q[N], A[N * 2], C;
struct Node {
  int u, f, d;
  long long ti() const { return 1ll * (d + B[f] - 1) / B[f] * (m + 1) + f; }
  bool operator<(const Node __) const { return ti() > __.ti(); }
};
priority_queue<Node> que;
void Solve() {
  k = rd(), m = rd(), C = 0;
  for (int i = 1, iend = k; i <= iend; ++i) A[++C] = P[i] = rd(), B[i] = rd();
  for (int i = 1, iend = m; i <= iend; ++i) A[++C] = Q[i] = rd();
  sort(A + 1, A + C + 1, [&](int x, int y) { return L[x] < L[y]; }), T = 0;
  for (int i = 1, iend = C; i <= iend; ++i) Ins(A[i]);
  while (T > 1) Link(S[T - 1], S[T]), T--;
  for (int i = 1, iend = k; i <= iend; ++i) que.push((Node){P[i], i, 0});
  while (!que.empty()) {
    Node u = que.top();
    que.pop();
    if (vis[u.u]) continue;
    vis[u.u] = u.f;
    for (int v : E[u.u])
      if (!vis[v]) que.push((Node){v, u.f, u.d + abs(dep[u.u] - dep[v])});
  }
  for (int i = 1, iend = m; i <= iend; ++i) printf("%d ", vis[Q[i]]);
  puts("");
}
int main() {
  n = rd();
  for (int i = 2, iend = n; i <= iend; ++i) {
    int u = rd(), v = rd();
    G[u].push_back(v), G[v].push_back(u);
  }
  dfs(1, 0);
  for (int _ = 1, _end = rd(); _ <= _end; ++_) Solve();
}
