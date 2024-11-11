#include <bits/stdc++.h>
using namespace std;
const long long N = 100010, M = 1000010, INF = 0x3f3f3f3f;
inline long long max(long long x, long long y) { return x > y ? x : y; }
inline long long min(long long x, long long y) { return x < y ? x : y; }
inline void swap(long long &x, long long &y) { x ^= y ^= x ^= y; }
long long head[N], ver[M], Next[M], tot;
long long n, m, k, t, top, num, d[N], id[N], st[N], vis[N], size[N], f[N][20];
vector<long long> v[N];
bool cmp(long long x, long long y) { return id[x] < id[y]; }
void add(long long x, long long y) {
  ver[++tot] = y, Next[tot] = head[x], head[x] = tot;
}
void dfs(long long x, long long fa) {
  d[x] = d[fa] + 1;
  id[x] = ++num;
  for (long long i = head[x]; i; i = Next[i]) {
    long long y = ver[i];
    if (y == fa) continue;
    f[y][0] = x;
    for (long long j = 1; j <= t; j++) f[y][j] = f[f[y][j - 1]][j - 1];
    dfs(y, x);
  }
}
long long lca(long long x, long long y) {
  if (d[x] > d[y]) swap(x, y);
  for (long long i = t; i >= 0; i--)
    if (d[f[y][i]] >= d[x]) y = f[y][i];
  if (x == y) return x;
  for (long long i = t; i >= 0; i--)
    if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
  return f[x][0];
}
long long dp(long long x, long long fa) {
  long long res = 0;
  size[x] = vis[x];
  for (long long i = 0; i < (long long)v[x].size(); i++)
    if (v[x][i] != fa) res += dp(v[x][i], x);
  if (size[x]) {
    for (long long i = 0; i < (long long)v[x].size(); i++)
      if (v[x][i] != fa) res += (size[v[x][i]]);
  } else {
    long long cnt = 0;
    for (long long i = 0; i < (long long)v[x].size(); i++)
      if (v[x][i] != fa) cnt += (size[v[x][i]]);
    if (cnt == 1)
      size[x] = 1;
    else if (cnt > 1)
      res++;
  }
  return res;
}
int main() {
  scanf("%lld", &n);
  t = (long long)(log(n) / log(2)) + 1;
  for (long long i = 1; i < n; i++) {
    long long x, y;
    scanf("%lld%lld", &x, &y);
    add(x, y), add(y, x);
  }
  dfs(1, 0);
  scanf("%lld", &m);
  while (m--) {
    scanf("%lld", &k);
    top = 0;
    for (long long i = 1; i <= k; i++) {
      long long x;
      scanf("%lld", &x);
      st[++top] = x;
      vis[x] = 1;
    }
    long long flag = 0;
    for (long long i = 1; i <= top; i++) flag |= vis[f[st[i]][0]];
    sort(st + 1, st + top + 1, cmp);
    for (long long i = 1; i < k; i++) {
      long long l = lca(st[i], st[i + 1]);
      if (l != st[i] && l != st[i + 1]) st[++top] = l;
    }
    st[++top] = 1;
    sort(st + 1, st + top + 1);
    top = unique(st + 1, st + top + 1) - st - 1;
    sort(st + 1, st + top + 1, cmp);
    for (long long i = 2; i <= top; i++) {
      long long l = lca(st[i - 1], st[i]);
      v[l].push_back(st[i]);
    }
    if (flag)
      puts("-1");
    else
      printf("%lld\n", dp(st[1], 0));
    for (long long i = 1; i <= top; i++) v[st[i]].clear();
    for (long long i = 1; i <= top; i++) vis[st[i]] = 0;
  }
  return 0;
}
