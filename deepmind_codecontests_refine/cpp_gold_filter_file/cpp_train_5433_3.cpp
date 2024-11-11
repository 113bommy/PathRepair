#include <bits/stdc++.h>
using namespace std;
int n, m;
long long g[45];
int fa[45], sz[45];
int clr[45];
long long f[(1 << 21)];
int mid;
long long msk;
void init() {
  for (int i = 0; i < n; i++) {
    fa[i] = i;
    sz[i] = 1;
  }
}
int par(int x) {
  if (fa[x] == x) return x;
  return fa[x] = par(fa[x]);
}
void unite(int x, int y) {
  x = par(x);
  y = par(y);
  if (x == y) return;
  if (sz[x] >= sz[y]) {
    fa[y] = x;
    sz[x] += sz[y];
  } else {
    fa[x] = y;
    sz[y] += sz[x];
  }
}
bool check(int rt, int c) {
  if (clr[rt] == (c ^ 1))
    return false;
  else if (clr[rt] == c)
    return true;
  clr[rt] = c;
  for (int i = 0; i < n; i++) {
    if (g[rt] & (1ll << i)) {
      if (!check(i, c ^ 1)) return false;
    }
  }
  return true;
}
long long solve1() {
  long long f8 = 1, f7 = 1, f6 = 1, f3 = 1;
  for (int i = 0; i < n; i++) {
    if (fa[i] == i) {
      f8 = (sz[i] == 1) ? (f8 << 1) : 0;
      f7 = (sz[i] == 1) ? (f7 << 1) : f7;
      f6 = check(i, 0) ? (f6 << 1) : 0;
      f3 = (f3 << 1);
    }
  }
  return -f3 + (f7 << 1) + f6 - f8;
}
void dfs1(int l, int r, int s1, int s2) {
  if (l == r) {
    f[s1]++;
    return;
  }
  dfs1(l + 1, r, s1, s2);
  if (!(s2 & (1ll << l))) {
    dfs1(l + 1, r, s1 | (1 << l), s2 | g[l]);
  }
}
long long dfs2(int l, int r, long long s) {
  if (l == r) {
    s &= msk;
    s ^= msk;
    return f[s];
  }
  long long ans = dfs2(l + 1, r, s);
  if (!(s & (1ll << l))) {
    ans += dfs2(l + 1, r, s | g[l]);
  }
  return ans;
}
long long solve2() {
  mid = n / 2;
  msk = (1 << mid) - 1;
  dfs1(0, mid, 0, 0);
  for (int i = 0; i < mid; i++) {
    for (int j = 0; j <= msk; j++) {
      if (j & (1ll << i)) f[j] += f[j ^ (1ll << i)];
    }
  }
  return dfs2(mid, n, 0);
}
int main() {
  memset(g, 0, sizeof(g));
  memset(clr, -1, sizeof(clr));
  memset(f, 0, sizeof(f));
  scanf("%d%d", &n, &m);
  init();
  int u, v;
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &u, &v);
    --u;
    --v;
    g[u] |= (1ll << v);
    g[v] |= (1ll << u);
    unite(u, v);
  }
  long long part1 = (1ll << n);
  long long part2 = solve1();
  long long part3 = -(solve2() << 1);
  printf("%I64d\n", part1 + part2 + part3);
}
