#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using ll = long long;
const int maxn = 3005;
std::vector<int> upd[maxn];
int w[maxn], D[maxn][maxn], ref[maxn], n, m, k, q;
int G[maxn][maxn];
ll ans;
struct data {
  int L[10] = {0}, R[10] = {0}, ans = 0, sum = 0;
};
inline data New(int x) {
  data d;
  if (x <= k) {
    d.L[x] = d.R[x] = 1;
  }
  d.sum = x;
  d.ans = (x <= k);
  return d;
}
inline data merge(data x, data y) {
  data z;
  std::memcpy(z.L, x.L, 40);
  std::memcpy(z.R, y.R, 40);
  z.ans = x.ans + y.ans;
  z.sum = x.sum + y.sum;
  int pre = 0;
  for (int i = 0; i <= k; ++i) {
    pre += x.R[i];
    z.ans += pre * y.L[k - i];
  }
  for (int i = 0; i + x.sum <= k; ++i) z.L[i + x.sum] += y.L[i];
  for (int i = 0; i + y.sum <= k; ++i) z.R[i + y.sum] += x.R[i];
  return z;
}
struct segmentTree {
  data sum[maxn << 2];
  inline void update(int x) { sum[x] = merge(sum[x << 1], sum[x << 1 | 1]); }
  void build(int l, int r, int rt) {
    if (l == r) {
      w[l] = 0;
      ref[l] = rt;
      sum[rt] = New(0);
      return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, rt << 1);
    build(mid + 1, r, rt << 1 | 1);
    update(rt);
  }
  void add(int x) {
    if (w[x] > k) return;
    int p = ref[x];
    w[x]++;
    sum[p] = New(w[x]);
    p >>= 1;
    while (p) {
      update(p);
      p >>= 1;
    }
  }
} seg;
void find_next(int i, int j, int cnt) {
  if ((i > n) || (!i) || (!cnt)) return;
  int x = D[i][j];
  if (!x) return;
  upd[x].push_back(j);
  find_next(x + 1, j, cnt - 1);
}
int main() {
  scanf("%d%d%d%d", &n, &m, &q, &k);
  k--;
  ans = (ll)n * (n + 1) * m * (m + 1) / 4;
  int sum = 0;
  while (q--) {
    int x, y;
    scanf("%d%d", &x, &y);
    G[x][y] = 1;
    sum += x - n / 2;
  }
  if (sum > 0) {
    for (int i = 1; i <= n / 2; ++i)
      for (int j = 1; j <= n; ++j) std::swap(G[i][j], G[n - i + 1][j]);
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= m; ++j) {
      if (G[i][j] == 1)
        D[i][j] = i;
      else
        D[i][j] = D[i + 1][j];
    }
  }
  for (int l = 1; l <= n; ++l) {
    for (int r = l; r <= n; ++r) upd[r].clear();
    seg.build(1, m, 1);
    for (int j = 1; j <= m; ++j) find_next(l, j, k + 1);
    for (int r = l; r <= n; ++r) {
      for (auto x : upd[r]) {
        seg.add(x);
      }
      ans -= seg.sum[1].ans;
    }
  }
  printf("%lld", ans);
  return 0;
}
