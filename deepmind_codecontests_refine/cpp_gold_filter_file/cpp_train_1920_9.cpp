#include <bits/stdc++.h>
using namespace std;
namespace Base {
const int inf = 0x3f3f3f3f, INF = 0x7fffffff;
const long long infll = 0x3f3f3f3f3f3f3f3fll, INFll = 0x7fffffffffffffffll;
template <typename T>
void read(T &x) {
  x = 0;
  int fh = 1;
  double num = 1.0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') fh = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  if (ch == '.') {
    ch = getchar();
    while (isdigit(ch)) {
      num /= 10;
      x = x + num * (ch - '0');
      ch = getchar();
    }
  }
  x = x * fh;
}
template <typename T>
void chmax(T &x, T y) {
  x = x < y ? y : x;
}
template <typename T>
void chmin(T &x, T y) {
  x = x > y ? y : x;
}
}  // namespace Base
using namespace Base;
const int N = 100010, K = 18;
struct Edge {
  int data, next;
} e[N * 2];
int dis[N], dep[N], d[N][3], up[N][K + 1], down[N][K + 1], head[N], place,
    dad[N][K + 1], n, m;
void build(int u, int v) {
  e[++place].data = v;
  e[place].next = head[u];
  head[u] = place;
}
void dfs(int x, int fa) {
  dis[x] = dis[fa] + 1;
  dad[x][0] = fa;
  for (int ed = head[x]; ed != 0; ed = e[ed].next)
    if (e[ed].data != fa) {
      dfs(e[ed].data, x);
      int tmp = dep[e[ed].data] + 1;
      if (tmp >= d[x][0])
        d[x][2] = d[x][1], d[x][1] = d[x][0], d[x][0] = tmp;
      else if (tmp >= d[x][1])
        d[x][2] = d[x][1], d[x][1] = tmp;
      else if (tmp > d[x][2])
        d[x][2] = tmp;
      dep[x] = max(dep[x], tmp);
    }
  for (int ed = head[x]; ed != 0; ed = e[ed].next)
    if (e[ed].data != fa) {
      int tmp = dep[e[ed].data] + 1;
      if (tmp == d[x][0])
        up[e[ed].data][0] = d[x][1] + 1, down[e[ed].data][0] = d[x][1] + 1;
      else
        up[e[ed].data][0] = d[x][0] + 1, down[e[ed].data][0] = d[x][0] + 1;
    }
}
void pre() {
  for (int i = 1, j = 1; j * 2 <= n; i++, j *= 2)
    for (int k = 1; k <= n; k++) {
      dad[k][i] = dad[dad[k][i - 1]][i - 1];
      if (dad[k][i] == 0) continue;
      up[k][i] = max(up[k][i - 1], up[dad[k][i - 1]][i - 1] + j);
      down[k][i] = max(down[dad[k][i - 1]][i - 1], down[k][i - 1] + j);
    }
}
int lca(int u, int v) {
  if (dis[u] > dis[v]) swap(u, v);
  for (int i = K; i >= 0; i--)
    if (dis[dad[v][i]] >= dis[u]) v = dad[v][i];
  if (u == v) return u;
  for (int i = K; i >= 0; i--)
    if (dad[v][i] != dad[u][i]) v = dad[v][i], u = dad[u][i];
  return dad[v][0];
}
int p(int x, int d) {
  for (int i = K; i >= 0; i--)
    if ((1 << i) <= d) {
      x = dad[x][i];
      d = d - (1 << i);
    }
  return x;
}
int qup(int x, int d) {
  int num = 0, tmp = 0;
  for (int i = K; i >= 0; i--)
    if ((1 << i) <= d) {
      chmax(num, up[x][i] + tmp);
      x = dad[x][i];
      tmp = tmp + (1 << i);
      d = d - (1 << i);
    }
  return num;
}
int qdown(int x, int d) {
  int num = 0, tmp = d;
  for (int i = K; i >= 0; i--)
    if ((1 << i) <= d) {
      tmp = tmp - (1 << i);
      chmax(num, down[x][i] + tmp);
      x = dad[x][i];
      d = d - (1 << i);
    }
  return num;
}
int main() {
  read(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    read(u);
    read(v);
    build(u, v);
    build(v, u);
  }
  dfs(1, 0);
  pre();
  read(m);
  for (int i = 1; i <= m; i++) {
    int u, v, l, tot, mid, ans;
    read(u);
    read(v);
    l = lca(u, v);
    if (dis[u] < dis[v]) swap(u, v);
    tot = dis[u] + dis[v] - 2 * dis[l];
    mid = p(u, (tot - 1) / 2);
    ans = dep[u];
    if (l == v) {
      int tmp = p(u, tot - 1);
      if (dep[tmp] + 1 != d[v][0])
        chmax(ans, d[v][0]);
      else
        chmax(ans, d[v][1]);
    } else {
      chmax(ans, dep[v]);
      int tmp1 = dep[p(u, dis[u] - dis[l] - 1)] + 1,
          tmp2 = dep[p(v, dis[v] - dis[l] - 1)] + 1;
      if (tmp1 < tmp2) swap(tmp1, tmp2);
      if (tmp1 == d[l][0] && tmp2 == d[l][1])
        chmax(ans, d[l][2] + dis[v] - dis[l]);
      else if (tmp1 == d[l][0])
        chmax(ans, d[l][1] + dis[v] - dis[l]);
      else
        chmax(ans, d[l][0] + dis[v] - dis[l]);
    }
    chmax(ans, qup(u, dis[u] - dis[mid]));
    chmax(ans, qdown(mid, dis[mid] - dis[l] - 1) + dis[v] - dis[l]);
    chmax(ans, qup(v, dis[v] - dis[l] - 1));
    chmax(ans, qup(l, dis[l] - 1) + dis[v] - dis[l]);
    printf("%d\n", ans);
  }
  return 0;
}
