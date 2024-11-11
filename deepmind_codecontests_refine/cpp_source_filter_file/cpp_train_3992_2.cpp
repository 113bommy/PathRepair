#include <bits/stdc++.h>
using namespace std;
const long long maxn = 100000 + 100;
const long long maxm = 200000 + 100;
const long long maxk = 100000 + 100;
long long n, m, k, a[maxk], b[maxk];
long long dfn[maxn], low[maxn], tim, st[maxn], top, c[maxn], color, vis[maxn];
long long he[maxn], ne[maxm], ver[maxm], tot;
long long he2[maxn], ne2[maxm], ver2[maxm], tot2;
long long d[maxn], dp[maxn][21];
void init() {
  for (long long i = 0; i < n; i++) {
    dfn[i] = 0;
    he[i] = he2[i] = 0;
    vis[i] = 0;
  }
  tot = tot2 = 1;
  tim = top = 0;
  color = -1;
}
void add(long long x, long long y) {
  ver[++tot] = y;
  ne[tot] = he[x];
  he[x] = tot;
}
void add2(long long x, long long y) {
  ver2[++tot2] = y;
  ne2[tot2] = he2[x];
  he2[x] = tot2;
}
void tarjan(long long x, long long e) {
  dfn[x] = low[x] = ++tim;
  st[top++] = x;
  for (long long cure = he[x]; cure; cure = ne[cure]) {
    long long m = cure ^ (long long)1;
    if (m == e) continue;
    long long y = ver[cure];
    if (dfn[y]) {
      low[x] = min(low[x], dfn[y]);
      continue;
    }
    tarjan(y, cure);
    low[x] = min(low[x], low[y]);
    if (low[y] > dfn[x]) {
      long long cur;
      color++;
      do {
        cur = st[--top];
        c[cur] = color;
      } while (cur != y);
    }
  }
  if (x == 0) {
    color++;
    for (long long i = top - 1; i >= 0; i--) {
      c[st[i]] = color;
    }
  }
}
queue<long long> que;
void bfs() {
  que.push(0);
  vis[0] = 1;
  d[0] = 0;
  while (que.size()) {
    long long x = que.front();
    que.pop();
    for (long long cure = he2[x]; cure; cure = ne2[cure]) {
      long long y = ver2[cure];
      if (vis[y]) continue;
      que.push(y);
      d[y] = d[x] + 1;
      vis[y] = 1;
      dp[y][0] = x;
      for (long long i = 1; i <= 20; i++) {
        if (((long long)1 << i) > d[y]) break;
        dp[y][i] = dp[dp[y][i - 1]][i - 1];
      }
    }
  }
}
long long lca(long long x, long long y) {
  if (d[x] < d[y]) swap(x, y);
  long long cnt = 0;
  for (long long i = 20; i >= 0; i--) {
    if (((long long)1 << i) > d[x]) continue;
    if (d[dp[x][i]] >= d[y]) {
      x = dp[x][i];
      cnt += (long long)1 << i;
    }
  }
  if (x == y) return cnt;
  for (long long i = 20; i >= 0; i--) {
    if (((long long)1 << i) > d[x]) continue;
    if (dp[x][i] != dp[y][0]) {
      x = dp[x][i];
      y = dp[y][i];
      cnt += 2 * ((long long)1 << i);
    }
  }
  return cnt + 2;
}
void build() {
  for (long long x = 0; x < n; x++) {
    for (long long cure = he[x]; cure; cure = ne[cure]) {
      long long y = ver[cure];
      if (c[x] == c[y]) continue;
      add2(c[x], c[y]);
    }
  }
}
int main() {
  long long x, y;
  scanf("%lld%lld", &n, &m);
  init();
  for (long long i = 0; i < m; i++) {
    scanf("%lld%lld", &x, &y);
    x--;
    y--;
    add(x, y);
    add(y, x);
  }
  tarjan(0, -1);
  build();
  bfs();
  scanf("%lld", &k);
  for (long long i = 0; i < k; i++) {
    scanf("%lld%lld", &x, &y);
    x--;
    y--;
    x = c[x];
    y = c[y];
    printf("%lld\n", lca(x, y));
  }
  return 0;
}
