#include <bits/stdc++.h>
using namespace std;
int p1 = 1000000, p2 = 0;
char buf[1000005], wb[1000005];
long long getint() {
  long long ret = 0, flag = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') flag = -1;
    c = getchar();
  }
  while (c <= '9' && c >= '0') {
    ret = (ret << 3) + (ret << 1) + c - '0';
    c = getchar();
  }
  return ret * flag;
}
void pc(char x) {
  if (p2 >= 1000000) fwrite(wb, 1, 1000000, stdout), p2 = 0;
  wb[p2++] = x;
}
void wrt(long long x) {
  if (x < 0) pc('-'), x = -x;
  int c[24] = {0};
  if (!x) return pc('0'), void();
  while (x) c[++c[0]] = x % 10, x /= 10;
  while (c[0]) pc(c[c[0]--] + '0');
}
int n, q;
long long ans;
struct edge {
  int ne, v;
} e[200005];
int head[100005], cnt;
void add(int u, int v) {
  ++cnt;
  e[cnt].v = v;
  e[cnt].ne = head[u];
  head[u] = cnt;
}
int sz[100005], p[100005], fa[100005], size[100005], dep[100005];
long long w[100005];
int get_fa(int x) { return x == fa[x] ? x : fa[x] = get_fa(fa[x]); }
void dfs(int x, int prt) {
  sz[x] = 1, dep[x] = dep[prt] + 1, p[x] = prt;
  for (int i = head[x]; i; i = e[i].ne) {
    int y = e[i].v;
    if (y == prt) continue;
    dfs(y, x);
    sz[x] += sz[y], w[x] += 1ll * sz[y] * sz[y];
  }
  w[x] += 1ll * (n - sz[x]) * (n - sz[x]);
  ans -= w[x];
}
long long cal(int x) {
  return max(1ll * size[x] * (size[x] - 1) * (size[x] - 2), 0ll);
}
void merge_node(int u, int v) {
  ans -= 1ll * (n - size[u]) * (n - size[u]) * size[u] - 1ll * w[u] * size[u];
  ans -= 1ll * (n - size[v]) * (n - size[v]) * size[v] - 1ll * w[v] * size[v];
  ans -= 1ll * (n - size[u]) * size[u] * (size[u] - 1) * 2;
  ans -= 1ll * (n - size[v]) * size[v] * (size[v] - 1) * 2;
  ans -= cal(u) + cal(v);
  fa[v] = u, size[u] += size[v];
  w[u] += w[v] - 1ll * sz[v] * sz[v] - 1ll * (n - sz[v]) * (n - sz[v]);
  ans += 1ll * (n - size[u]) * (n - size[u]) * size[u] - 1ll * w[u] * size[u];
  ans += 1ll * (n - size[u]) * size[u] * (size[u] - 1) * 2;
  ans += cal(u);
}
int main() {
  n = getint();
  for (int i = 1; i < n; i++) {
    int u = getint(), v = getint();
    add(u, v), add(v, u);
  }
  ans = 1ll * n * (n - 1) * (n - 1);
  dfs(1, 0);
  wrt(ans), pc('\n');
  for (int i = 1; i <= n; i++) fa[i] = i, size[i] = 1;
  q = getint();
  for (int i = 1; i <= q; i++) {
    int u = getint(), v = getint();
    u = get_fa(u), v = get_fa(v);
    while (u ^ v) {
      if (dep[u] < dep[v]) swap(u, v);
      int x = get_fa(p[u]);
      merge_node(x, u), u = x;
    }
    wrt(ans), pc('\n');
  }
  fwrite(wb, 1, p2, stdout);
  return 0;
}
