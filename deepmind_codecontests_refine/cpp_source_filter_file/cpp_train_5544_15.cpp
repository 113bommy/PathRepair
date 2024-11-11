#include <bits/stdc++.h>
using namespace std;
inline int qr() {
  int f = 0, fu = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') fu = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    f = (f << 3) + (f << 1) + c - 48;
    c = getchar();
  }
  return f * fu;
}
const int N = 1e5 + 10, M = 2e5 + 10;
int head[N], ver[M << 1], Next[M << 1], tot;
struct Union_Find {
  int fa[N];
  void init(int n) {
    for (register int i = 0; i <= n; ++i) fa[i] = i;
  }
  int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
  void unit(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) fa[y] = x;
  }
  bool same(int x, int y) { return find(x) == find(y); }
} uf;
inline void add(int x, int y) {
  ver[++tot] = y;
  Next[tot] = head[x];
  head[x] = tot;
}
vector<pair<int, int> > e;
int n, m, k;
int col[N];
struct LCA {
  int t, f[N][20], d[N];
  void dfs(int x) {
    for (int i = head[x]; i; i = Next[i]) {
      int y = ver[i];
      if (d[y]) continue;
      d[y] = d[x] + 1;
      f[y][0] = x;
      for (int j = 1; j <= t; j++) f[y][j] = f[f[y][j - 1]][j - 1];
      dfs(y);
    }
  }
  inline int lca(int x, int y) {
    if (d[x] > d[y]) swap(x, y);
    for (int i = t; i >= 0; i--)
      if (d[f[y][i]] >= d[x]) y = f[y][i];
    if (x == y) return x;
    for (int i = t; i >= 0; i--)
      if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
    return f[x][0];
  }
  int dis(int x, int y) { return d[x] + d[y] - 2 * d[lca(x, y)]; }
} L;
void colour(int x, int c) {
  col[x] = c;
  for (register int i = head[x]; i; i = Next[i]) {
    int y = ver[i];
    if (col[y]) continue;
    colour(y, 3 - c);
  }
}
int main() {
  n = qr(), m = qr(), k = qr();
  if (m == n - 1) {
    k = ceil((k * 1.0) / 2.0);
    for (register int i = 1; i <= n - 1; ++i) {
      int x = qr(), y = qr();
      add(x, y), add(y, x);
    }
    colour(1, 1);
    int cnt[3] = {0};
    for (register int i = 1; i <= n; ++i) cnt[col[i]]++;
    int c;
    c = cnt[1] > cnt[2] ? 1 : 2;
    puts("1");
    int ct = 0;
    for (register int i = 1; i <= n; ++i)
      if (col[i] == c) {
        printf("%d ", i), ct++;
        if (ct == k) break;
      }
    return 0;
  }
  uf.init(n);
  while (m--) {
    int x = qr(), y = qr();
    if (uf.same(x, y))
      e.push_back({x, y});
    else
      add(x, y), add(y, x), uf.unit(x, y);
  }
  L.d[1] = 1, L.t = log2(n), L.dfs(1);
  pair<int, int> res = {0, 0};
  for (auto it : e)
    if (!res.first || L.d[it.first] < L.d[res.first] ||
        L.d[it.first] == L.d[res.first] && L.d[it.second] < L.d[res.second])
      res = it;
  int x = res.first, y = res.second;
  int lca = L.lca(x, y);
  vector<int> seq;
  while (x != lca) seq.push_back(x), x = L.f[x][0];
  seq.push_back(lca);
  vector<int> tmp;
  while (y != lca) seq.push_back(y), y = L.f[y][0];
  reverse(tmp.begin(), tmp.end());
  for (auto it : tmp) seq.push_back(it);
  if (seq.size() <= k) {
    puts("2");
    printf("%d\n", seq.size());
    for (auto it : seq) printf("%d ", it);
  } else {
    puts("1");
    k = ceil((k * 1.0) / 2.0);
    int ct = 0;
    for (int i = 0; i <= seq.size() - 1; i += 2) {
      printf("%d ", seq[i]), ct++;
      if (ct == k) break;
    }
  }
  return 0;
}
