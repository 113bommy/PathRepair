#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int first = 0, f = 1;
  char ch = getchar();
  for (; ch < '0' || ch > '9';) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  for (; ch >= '0' && ch <= '9';) {
    first = first * 10 + ch - '0';
    ch = getchar();
  }
  return first * f;
}
int n, k;
int dex[200010], tot = 1;
struct node {
  int ed, before;
} g[200010 * 2];
inline void add(int first, int second) {
  g[++tot].ed = second;
  g[tot].before = dex[first];
  dex[first] = tot;
}
int a[200010];
inline void Init() {
  n = read(), k = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= n - 1; i++) {
    int u = read(), v = read();
    add(u, v);
    add(v, u);
  }
}
int size[200010], l[200010], r[200010], Times;
inline void Find(int u, int f) {
  l[u] = ++Times;
  size[u] = 1;
  for (int j = dex[u], v; j; j = g[j].before) {
    v = g[j].ed;
    if (v == f) continue;
    Find(v, u);
    size[u] += size[v];
  }
  r[u] = Times;
}
int ans, flag[200010], f[200010];
inline void getf(int u, int fa) {
  int s1 = 0, s2 = 0;
  for (int j = dex[u], v; j; j = g[j].before) {
    v = g[j].ed;
    if (v == fa) continue;
    getf(v, u);
    if (f[v] == size[v])
      s1 += f[v];
    else
      s2 = max(s2, f[v]);
  }
  if (!flag[u])
    f[u] = 0;
  else
    f[u] = 1 + s1 + s2;
}
inline int getg(int u, int fa, int outs) {
  int s1 = 0, s2j = 0, s3j = 0;
  for (int j = dex[u], v; j; j = g[j].before) {
    v = g[j].ed;
    if (v == fa) continue;
    if (f[v] == size[v])
      s1 += f[v];
    else if (f[v] >= f[s2j])
      s3j = s2j, s2j = v;
    else if (f[v] > f[s3j])
      s3j = v;
  }
  int s2 = f[s2j];
  if (flag[u]) {
    if (outs == n - size[u])
      s1 += outs;
    else if (outs > s2)
      s2 = outs, s2j = 0;
    if (s1 + s2 + 1 >= k) return 1;
  }
  for (int j = dex[u], v; j; j = g[j].before) {
    v = g[j].ed;
    if (v == fa) continue;
    int outj = s1 + s2 + 1;
    if (f[v] == size[v])
      outj -= f[v];
    else if (j == s2j)
      outj -= f[s2j] - f[s3j];
    if (!flag[u]) outj = 0;
    if (getg(v, u, outj)) return 1;
  }
  return 0;
}
inline int check(int first) {
  for (int i = 1; i <= n; i++) flag[i] = (a[i] >= first);
  getf(1, 0);
  return getg(1, 0, 0);
}
inline void Solve() {
  Find(1, 0);
  int l = 1, r = 1000000;
  for (; l <= r;) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  printf("%d\n", ans);
}
int main() {
  Init();
  Solve();
}
