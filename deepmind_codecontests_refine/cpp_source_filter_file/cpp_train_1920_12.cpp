#include <bits/stdc++.h>
using namespace std;
const int inf = ~0U >> 1;
template <class T>
inline void read(T &n) {
  char c;
  for (c = getchar(); !(c >= '0' && c <= '9'); c = getchar())
    ;
  n = c - '0';
  for (c = getchar(); c >= '0' && c <= '9'; c = getchar()) n = n * 10 + c - '0';
}
const int maxn = 210000;
struct edge {
  int y;
  edge *nxt;
  edge() {}
  edge(int _y, edge *_nxt) : y(_y), nxt(_nxt) {}
} * head[maxn];
int fa[maxn], dep[maxn], h[maxn], nxt[maxn], f[maxn], dia[maxn];
int root, bot, N, M, x, y, n;
vector<int> Dia;
void add(int x, int y) { head[x] = new edge(y, head[x]); }
void dfs(int u, int par) {
  fa[u] = par;
  dep[u] = dep[par] + 1;
  for (edge *i = head[u]; i; i = i->nxt)
    if (i->y != par) dfs(i->y, u);
}
void col(int u, int fa, int c, int d) {
  h[u] = c;
  dep[u] = d;
  f[u] = 0;
  for (edge *i = head[u]; i; i = i->nxt)
    if (i->y != fa && !dia[i->y])
      col(i->y, u, c, d + 1), f[u] = max(f[u], f[i->y] + 1);
}
struct RMQ {
  int n, a[maxn], f[maxn][20];
  void precalc() {
    int K = int(log(n) / log(2));
    for (int i = (1); i <= (n); ++i) f[i][0] = a[i];
    for (int j = (1); j <= (K); ++j)
      for (int i = 1; i + (1 << (j - 1)) <= n; ++i)
        f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
  }
  int query(int x, int y) {
    if (x > y) return -10000000;
    int k = int((log(y - x + 1) / log(2)));
    return max(f[x][k], f[y - (1 << k) + 1][k]);
  }
} rmq1, rmq2;
int query(int x, int y) {
  if (h[x] == h[y]) {
    return max(h[x] + rmq1.query(1, h[x]), -h[x] + rmq2.query(h[x], n)) +
           min(dep[x], dep[y]);
  }
  if (h[x] > h[y]) swap(x, y);
  int mid = (h[x] + h[y] + dep[y] - dep[x]) / 2;
  int ans = 0;
  if (mid > h[y]) mid = h[y];
  if (mid < h[x]) mid = h[x];
  if (mid - h[x] + dep[x] > h[y] - mid + dep[y]) mid--;
  if (h[y] - h[x] + dep[x] < dep[y]) {
    ans = max(ans, rmq1.query(1, h[x]) + h[x] + dep[x]);
    ans = max(ans, rmq2.query(h[x], n) - h[x] + dep[x]);
  } else if (h[y] - h[x] + dep[y] < dep[x]) {
    ans = max(ans, rmq1.query(1, h[y]) + h[y] + dep[y]);
    ans = max(ans, rmq2.query(h[y], mid) - h[y] + dep[y]);
  } else {
    ans = max(ans, rmq1.query(1, h[x]) + h[x] + dep[x]);
    ans = max(ans, rmq2.query(h[x], mid) - h[x] + dep[x]);
    ans = max(ans, rmq1.query(mid + 1, h[y]) + h[y] + dep[y]);
    ans = max(ans, rmq2.query(h[y], n) - h[y] + dep[y]);
    ans = max(ans, max(f[x], f[y]));
  }
  return ans;
}
int main() {
  read(N);
  for (int i = (1); i <= (N - 1); ++i) read(x), read(y), add(x, y), add(y, x);
  dfs(1, 0);
  for (int i = (1); i <= (N); ++i)
    if (dep[i] > dep[root]) root = i;
  dfs(root, 0);
  for (int i = (1); i <= (N); ++i)
    if (dep[i] > dep[bot]) bot = i;
  for (int i = bot; i; i = fa[i]) nxt[fa[i]] = i, dia[i] = 1;
  for (int i = root; i; i = nxt[i]) Dia.push_back(i);
  n = Dia.size();
  for (int i = 0; i < Dia.size(); ++i) col(Dia[i], 0, i + 1, 0);
  rmq1.n = rmq2.n = n;
  for (int i = (1); i <= (n); ++i)
    rmq1.a[i] = f[Dia[i - 1]] - i, rmq2.a[i] = f[Dia[i - 1]] + i;
  rmq1.precalc();
  rmq2.precalc();
  read(M);
  while (M--) {
    read(x);
    read(y);
    printf("%d\n", query(x, y));
  }
}
