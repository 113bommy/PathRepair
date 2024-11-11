#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
struct dabt {
  long long next, to, num;
} e[N << 1];
struct node {
  long long w, c, st, ed, id;
} pt[N];
long long n, m, head[N], k, fa[N], lg[N] = {-1}, deep[N], dp[N][22],
                                   maxx[N][22];
long long S, sum, ans;
bool inn[N];
void add(long long from, long long to, long long num) {
  e[++k] = (dabt){head[from], to, num};
  head[from] = k;
  e[++k] = (dabt){head[to], from, num};
  head[to] = k;
}
bool cmp(node a, node b) { return a.w < b.w; }
long long f(long long son) {
  return fa[son] = fa[son] == son ? son : f(fa[son]);
}
void dfs(long long st) {
  for (long long i = 1; i <= lg[n]; i++) {
    dp[st][i] = dp[dp[st][i - 1]][i - 1];
    long long a1 = maxx[dp[st][i - 1]][i - 1], b1 = maxx[st][i - 1];
    maxx[st][i] = pt[a1].w > pt[b1].w ? a1 : b1;
  }
  for (long long i = head[st]; i; i = e[i].next) {
    long long v = e[i].to;
    if (v == dp[st][0]) continue;
    deep[v] = deep[st] + 1;
    dp[v][0] = st;
    maxx[v][0] = e[i].num;
    dfs(v);
  }
}
long long lca(long long x, long long y) {
  long long best = 0;
  pt[0].w = -1e9;
  if (deep[x] < deep[y]) swap(x, y);
  long long d = deep[x] - deep[y];
  for (long long i = lg[n]; i >= 0; i--)
    if (d & (1 << i)) {
      if (pt[best].w < pt[maxx[x][i]].w) best = maxx[x][i];
      x = dp[x][i];
    }
  if (x == y) return best;
  for (long long i = lg[n]; i >= 0; i--)
    if (dp[x][i] != dp[y][i]) {
      if (pt[best].w < pt[maxx[y][i]].w) best = maxx[y][i];
      if (pt[best].w < pt[maxx[x][i]].w) best = maxx[x][i];
      x = dp[x][i], y = dp[y][i];
    }
  if (pt[best].w < pt[maxx[x][0]].w) best = maxx[x][0];
  if (pt[best].w < pt[maxx[y][0]].w) best = maxx[y][0];
  return best;
}
int main() {
  scanf("%I64d%I64d", &n, &m);
  for (long long i = 1; i <= m; i++) scanf("%I64d", &pt[i].w);
  for (long long i = 1; i <= m; i++) scanf("%I64d", &pt[i].c);
  for (long long i = 1; i <= m; i++)
    scanf("%I64d%I64d", &pt[i].st, &pt[i].ed), pt[i].id = i;
  for (long long i = 1; i <= n; i++) fa[i] = i;
  sort(pt + 1, pt + 1 + m, cmp);
  long long tot = 0, tt = 0;
  pt[tt].c = 3e9;
  for (long long i = 1; i <= m; i++) {
    long long fx = f(pt[i].st), fy = f(pt[i].ed);
    if (fx == fy) continue;
    fa[fx] = fy;
    inn[pt[i].id] = 1;
    sum += pt[i].w;
    add(pt[i].st, pt[i].ed, i);
    tot++;
    if (pt[tt].c > pt[i].c) tt = i;
    if (tot == n - 1) break;
  }
  for (long long i = 1; i <= n; i++) lg[i] = lg[i >> 1] + 1;
  dfs(1);
  scanf("%I64d", &S);
  ans = sum - S / pt[tt].c;
  long long minn = pt[tt].c;
  bool flg = 0;
  for (long long i = 1; i <= m; i++) {
    if (pt[i].c < minn) {
      long long x = lca(pt[i].st, pt[i].ed);
      long long re = sum - pt[x].w + pt[i].w - S / pt[i].c;
      if (re < ans) ans = re, tt = i, flg = 1;
    }
  }
  printf("%I64d\n", ans);
  if (flg) inn[pt[lca(pt[tt].st, pt[tt].ed)].id] = 0, inn[pt[tt].id] = 1;
  pt[tt].w -= S / pt[tt].c;
  for (long long i = 1; i <= m; i++)
    if (inn[pt[i].id]) printf("%I64d %I64d\n", pt[i].id, pt[i].w);
  return 0;
}
