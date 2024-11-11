#include <bits/stdc++.h>
using namespace std;
int cnt = 0, head[100000 + 5], zhong, fa[100000 + 5], siz[100000 + 5], asize;
int dis[100000 + 5], ans, dd[100000 + 5], in[100000 + 5], out[100000 + 5];
int dl[100000 + 5], tdl[100000 + 5], x, y, k, invk, val[100000 + 5];
map<int, int> num;
struct edge {
  int end, next;
} e[200000 + 5];
bool vis[100000 + 5];
void add_edge(int u, int v) {
  e[++cnt].end = v;
  e[cnt].next = head[u];
  head[u] = cnt;
}
int q[100000 + 5];
void getzhong(int u) {
  int h = 1, t = 0, mx;
  fa[u] = 0;
  q[++t] = u;
  while (h <= t) {
    u = q[h++];
    siz[u] = 1;
    for (int i = head[u]; i; i = e[i].next) {
      int v = e[i].end;
      if (vis[v] || v == fa[u]) continue;
      fa[v] = u;
      q[++t] = v;
    }
  }
  for (int T = t; T >= 1; T--) {
    u = q[T];
    mx = 0;
    for (int i = head[u]; i; i = e[i].next) {
      int v = e[i].end;
      if (vis[v] || v == fa[u]) continue;
      siz[u] += siz[v];
      mx = max(mx, siz[v]);
    }
    mx = max(mx, asize - siz[u]);
    if (mx <= asize / 2) {
      zhong = u;
      return;
    }
  }
}
void getlen(int u, int opt) {
  int h = 1, t = 0;
  fa[u] = 0;
  q[++t] = u;
  while (h <= t) {
    u = q[h++];
    siz[u] = 1;
    if (opt == 0) num[dis[u]]++;
    if (opt == 1) num[dis[u]]--;
    if (opt == 2) {
      int disu = 1ll * (dis[u] - val[zhong] + y) % y * invk % y,
          ddu = dd[u] - 1;
      in[u] += num[disu];
    }
    if (opt == 3) num[1ll * (x - dis[u] + y) % y * tdl[dd[u] + 1] % y]++;
    if (opt == 4) num[1ll * (x - dis[u] + y) % y * tdl[dd[u] + 1] % y]--;
    if (opt == 5) {
      int disu = (dis[u] - 1ll * dl[dd[u]] * val[zhong] % y + y) % y,
          ddu = dd[u] - 1;
      out[u] += num[1ll * (x - disu + y) % y * tdl[ddu + 1] % y];
    }
    for (int i = head[u]; i; i = e[i].next) {
      int v = e[i].end;
      if (vis[v] || v == fa[u]) continue;
      fa[v] = u;
      q[++t] = v;
      dd[v] = dd[u] + 1;
      if (opt <= 2)
        dis[v] = (dis[u] + 1ll * dl[dd[v]] * val[v] % y) % y;
      else
        dis[v] = (val[v] + 1ll * dis[u] * k % y) % y;
    }
  }
  for (int T = t; T >= 1; T--) {
    u = q[T];
    for (int i = head[u]; i; i = e[i].next) {
      int v = e[i].end;
      if (vis[v] || v == fa[u]) continue;
      siz[u] += siz[v];
    }
  }
}
void dfs(int u) {
  int i;
  getzhong(u);
  vis[zhong] = true;
  dis[zhong] = val[zhong];
  dd[zhong] = 0;
  getlen(zhong, 0);
  out[zhong] += num[x];
  for (i = head[zhong]; i; i = e[i].next) {
    int v = e[i].end;
    if (vis[v]) continue;
    dis[v] = (val[zhong] + 1ll * val[v] * k % y) % y;
    dd[v] = 1;
    getlen(v, 1);
    dis[v] = (1ll * val[zhong] * k % y + val[v]) % y;
    dd[v] = 1;
    getlen(v, 5);
    dis[v] = (val[zhong] + 1ll * val[v] * k % y) % y;
    dd[v] = 1;
    getlen(v, 0);
  }
  num.clear();
  dis[zhong] = val[zhong];
  dd[zhong] = 0;
  getlen(zhong, 3);
  in[zhong] += num[0];
  for (i = head[zhong]; i; i = e[i].next) {
    int v = e[i].end;
    if (vis[v]) continue;
    dis[v] = (1ll * val[zhong] * k % y + val[v]) % y;
    dd[v] = 1;
    getlen(v, 4);
    dis[v] = (val[zhong] + 1ll * val[v] * k % y) % y;
    dd[v] = 1;
    getlen(v, 2);
    dis[v] = (1ll * val[zhong] * k % y + val[v]) % y;
    dd[v] = 1;
    getlen(v, 3);
  }
  num.clear();
  for (i = head[zhong]; i; i = e[i].next) {
    int v = e[i].end;
    if (vis[v]) continue;
    asize = siz[v];
    dfs(v);
  }
}
int ksm(int a, int t) {
  int s = 1;
  while (t) {
    if (t & 1) s = 1ll * s * a % y;
    a = 1ll * a * a % y;
    t >>= 1;
  }
  return s;
}
int main() {
  int n, m, i, u, v;
  long long ans = 0;
  scanf("%d%d%d%d", &n, &y, &k, &x);
  for (i = 1; i <= n; i++) scanf("%d", &val[i]);
  dl[0] = tdl[0] = 1;
  invk = ksm(k, y - 2);
  for (i = 1; i <= n; i++) dl[i] = 1ll * dl[i - 1] * k % y;
  for (i = 1; i <= n; i++) tdl[i] = 1ll * tdl[i - 1] * invk % y;
  for (i = 1; i < n; i++) {
    scanf("%d%d", &u, &v);
    add_edge(u, v);
    add_edge(v, u);
  }
  asize = n;
  dfs(1);
  for (int i = 1; i <= n; i++)
    ans += 2ll * out[i] * (n - out[i]) + 1ll * out[i] * (n - in[i]) +
           1ll * in[i] * (n - out[i]) + 2ll * in[i] * (n - in[i]);
  ans = 1ll * n * n * n - ans / 2;
  printf("%lld\n", ans);
}
