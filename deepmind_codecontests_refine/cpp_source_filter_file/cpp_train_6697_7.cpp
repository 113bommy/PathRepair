#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const int mod = 998244353;
int Mod(long long x) { return x >= mod ? x - mod : x; }
long long read() {
  long long x = 0;
  int f = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + (ch ^ 48);
  return x * f;
}
void print(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
}
const int N = 50010, M = N;
int n, k;
;
struct edge {
  int nxt, to, w;
} e[M << 1];
int head[N], ecnt = 1;
void add(int u, int v, long long w = 0) {
  e[++ecnt].w = w, e[ecnt].to = v, e[ecnt].nxt = head[u];
  head[u] = ecnt;
}
void add_edge(int u, int v, long long w = 0) {
  add(u, v, w), add(v, u, w * 1);
};
long long ans;
int root, mx[N], S, siz[N], vis[N];
void get_root(int u, int fa) {
  siz[u] = 1, mx[u] = 0;
  for (int i = head[u], v; i; i = e[i].nxt)
    if (!vis[v = e[i].to] && v != fa)
      get_root(v, u), siz[u] += siz[v], mx[u] = max(mx[u], siz[v]);
  mx[u] = max(mx[u], S - siz[u]);
  if (mx[u] < mx[root]) root = u;
}
long long dis[N], res[N];
int maxx, tot;
void dfs(int u, int fa, int dep) {
  maxx = max(maxx, dep);
  res[dep]++;
  for (int i = head[u], v; i; i = e[i].nxt)
    if (!vis[v = e[i].to] && v != fa) dfs(v, u, dep + 1);
}
void calc(int u) {
  dis[0] = 1, tot = 0;
  for (int i = head[u], v; i; i = e[i].nxt)
    if (!vis[v = e[i].to]) {
      maxx = 0, dfs(v, u, 1);
      for (int j = 0; j <= maxx; j++) ans = ans + res[j] * dis[k - j];
      for (int j = 0; j <= maxx; j++) dis[j] += res[j], res[j] = 0;
      tot = max(tot, maxx);
    }
  for (int i = 0; i <= maxx; i++) dis[i] = 0;
}
void solve(int u) {
  get_root(u, 0), vis[u] = 1;
  calc(u);
  for (int i = head[u], v; i; i = e[i].nxt)
    if (!vis[v = e[i].to]) {
      root = 0, S = siz[v], get_root(v, u);
      solve(root);
    }
}
int main() {
  n = read(), k = read();
  for (int i = 1; i < n; i++) add_edge(read(), read());
  mx[root = 0] = S = n;
  get_root(1, 0), solve(root);
  print(ans), putchar('\n');
}
