#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 50, inf = 1e9;
long long n, k, p, mod, x, y, rt, cnt, tot, num[maxn], last[maxn], size[maxn],
    maxs[maxn], vis[maxn], in[maxn], out[maxn];
long long sum, Pow[maxn], inv[maxn];
struct Edge {
  int v, nxt;
} e[2 * maxn];
struct node {
  int pos, num;
} a[maxn], b[maxn];
int read() {
  int x = 0;
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + (c ^ 48), c = getchar();
  return x;
}
bool cmp(node x, node y) { return x.num < y.num; }
inline void insert(int x, int y) {
  cnt++, e[cnt].v = y, e[cnt].nxt = last[x], last[x] = cnt;
}
int qpow(int x, int k) {
  long long d = 1, t = x;
  while (k) {
    if (k & 1) d = d * t % mod;
    t = t * t % mod, k >>= 1;
  }
  return d;
}
void get_root(int u, int fa, int s) {
  size[u] = 1, maxs[u] = 0;
  for (int i = last[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if (v == fa || vis[v]) continue;
    get_root(v, u, s);
    size[u] += size[v], maxs[u] = max(maxs[u], size[v]);
  }
  maxs[u] = max(maxs[u], s - size[u]);
  if (maxs[rt] > maxs[u]) rt = u;
}
void calc(int u, int fa, int d, long long up, long long down) {
  tot++, up = (up * k + num[u]) % mod;
  if (d) down = (down + num[u] * Pow[d - 1]) % mod;
  a[tot].pos = u, a[tot].num = (p - up + mod) % mod * inv[d + 1] % mod;
  b[tot].pos = u, b[tot].num = down;
  for (int i = last[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if (v != fa && !vis[v]) calc(v, u, d + 1, up, down);
  }
}
void solve(int u, int d, long long up, long long down, int opt) {
  tot = 0;
  calc(u, 0, d, up, down);
  sort(a + 1, a + tot + 1, cmp);
  sort(b + 1, b + tot + 1, cmp);
  int pa = 1, pb = 1, s = 0;
  while (pa <= tot) {
    while (pb <= tot && b[pb].num <= a[pa].num) {
      if (pb > 1 && b[pb].num != b[pb - 1].num) s = 0;
      s++, pb++;
    }
    if (pb > 1 && b[pb - 1].num == a[pa].num) out[a[pa].pos] += opt * s;
    pa++;
  }
  pa = 1, pb = 1, s = 0;
  while (pb <= tot) {
    while (pa <= tot && a[pa].num <= b[pb].num) {
      if (pa > 1 && a[pa].num != a[pa - 1].num) s = 0;
      s++, pa++;
    }
    if (pa > 1 && a[pa - 1].num == b[pb].num) in[b[pb].pos] += opt * s;
    pb++;
  }
}
void dfs(int u) {
  vis[u] = 1;
  solve(u, 0, 0, 0, 1);
  for (int i = last[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if (!vis[v]) solve(v, 1, num[u], 0, -1);
  }
  for (int i = last[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if (vis[v]) continue;
    rt = 0;
    get_root(v, u, size[v]);
    dfs(rt);
  }
}
int main() {
  n = read(), mod = read(), k = read(), p = read();
  int t = qpow(k, mod - 2);
  Pow[0] = 1, inv[0] = 1;
  for (int i = 1; i <= n; i++)
    Pow[i] = Pow[i - 1] * k % mod, inv[i] = inv[i - 1] * t % mod;
  for (int i = 1; i <= n; i++) num[i] = read();
  for (int i = 1; i < n; i++) {
    x = read(), y = read();
    insert(x, y), insert(y, x);
  }
  rt = 0, maxs[rt] = inf;
  get_root(1, 0, n);
  dfs(rt);
  for (int i = 1; i <= n; i++)
    sum += 1ll * 2 * in[i] * (n - in[i]) + 2 * out[i] * (n - out[i]) +
           in[i] * (n - out[i]) + out[i] * (n - in[i]);
  cout << 1ll * n * n * n - sum / 2 << endl;
  return 0;
}
