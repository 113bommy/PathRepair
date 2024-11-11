#include <bits/stdc++.h>
using namespace std;
int n, L, R, ans = -1;
int totm = 1, now[100000 + 10];
struct Edge {
  int k, f, next;
} e[100000 + 10 << 1];
int cq, size, sum, tot, lim;
int s[100000 + 10];
bool used[100000 + 10];
pair<int, int> p[100000 + 10], f[100000 + 10], g[100000 + 10], tmp, res;
int dl[100000 + 10];
void getsum(int i, int fa) {
  ++sum;
  for (int j = now[i]; j; j = e[j].next)
    if (!used[e[j].k] && e[j].k != fa) getsum(e[j].k, i);
}
void getcq(int i, int fa) {
  int t = 0;
  s[i] = 1;
  for (int j = now[i]; j; j = e[j].next)
    if (!used[e[j].k] && e[j].k != fa) {
      getcq(e[j].k, i);
      s[i] += s[e[j].k];
      t = max(t, s[e[j].k]);
    }
  t = max(t, sum - s[i]);
  if (t < size) {
    size = t;
    cq = i;
  }
}
void dfs(int i, int fa, int d, int s) {
  g[d] = max(g[d], make_pair(s, i));
  for (int j = now[i]; j; j = e[j].next)
    if (!used[e[j].k] && e[j].k != fa)
      dfs(e[j].k, i, d + 1, s + (e[j].f >= lim ? 1 : -1));
}
bool check() {
  int i, j, k, l, r;
  f[0].second = cq;
  for (i = 1; i <= tot; ++i) {
    for (j = 1; j <= p[i].first; ++j) g[j].first = -1000000001;
    dfs(e[p[i].second].k, 0, 1, (e[p[i].second].f >= lim ? 1 : -1));
    l = 1, r = 0;
    for (j = 1, k = min(p[i - 1].first, R); j <= min(p[i].first, R); ++j) {
      while (k >= max(L - j, 0)) {
        while (l <= r && f[dl[r]] <= f[k]) --r;
        dl[++r] = k--;
      }
      while (l <= r && j + dl[l] > R) ++l;
      if (l <= r && g[j].first + f[dl[l]].first >= 0) {
        tmp = make_pair(g[j].second, f[dl[l]].second);
        return 1;
      }
    }
    for (j = 1; j <= p[i - 1].first; ++j) f[j] = max(f[j], g[j]);
    for (; j <= p[i].first; ++j) f[j] = g[j];
  }
  return 0;
}
void work(int i) {
  sum = 0;
  getsum(i, 0);
  size = 1000000001;
  getcq(i, 0);
  used[cq] = 1;
  tot = 0;
  for (i = now[cq]; i; i = e[i].next)
    if (!used[e[i].k])
      p[++tot] = make_pair(s[e[i].k] < s[cq] ? s[e[i].k] : sum - s[cq], i);
  sort(p + 1, p + tot + 1);
  int l = 0, r = 1000000001;
  while (l < r) {
    lim = (l + r) >> 1;
    if (check())
      l = lim + 1;
    else
      r = lim;
  }
  if (ans < l - 1) {
    ans = lim = l - 1;
    check();
    res = tmp;
  }
  for (i = now[cq]; i; i = e[i].next)
    if (!used[e[i].k]) work(e[i].k);
}
int main() {
  int i, u, v, w;
  scanf("%d%d%d", &n, &L, &R);
  for (i = 1; i < n; ++i) {
    scanf("%d%d%d", &u, &v, &w);
    ++totm;
    e[totm].k = v;
    e[totm].f = w;
    e[totm].next = now[u];
    now[u] = totm;
    ++totm;
    e[totm].k = u;
    e[totm].f = w;
    e[totm].next = now[v];
    now[v] = totm;
  }
  work(1);
  printf("%d %d\n", res.first, res.second);
  return 0;
}
