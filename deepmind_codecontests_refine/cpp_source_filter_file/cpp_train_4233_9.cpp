#include <bits/stdc++.h>
#pragma GCC optimize(4)
using namespace std;
inline int gi() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return (f == 1) ? x : -x;
}
const int maxn = 2e6 + 5, mod = 1e9 + 7;
struct line {
  int l, r;
  inline bool operator<(const line &b) const {
    if (l != b.l)
      return l < b.l;
    else
      return r - l > b.r - b.l;
  }
} a[2][maxn];
int temp[maxn], tot, m, n1, n2, sum[2];
vector<pair<int, int> > vec[maxn];
inline int min(int a, int b) { return a < b ? a : b; }
inline long long qpow(long long x, long long k) {
  long long ret = 1;
  while (k) {
    if (k & 1) ret = (ret * x) % mod;
    k >>= 1, x = (x * x) % mod;
  }
  return ret;
}
struct segmentree {
  static const int maxn = 4e6 + 5;
  long long sum[maxn], tag[maxn];
  inline void pushup(int u) { sum[u] = sum[u << 1] + sum[u << 1 | 1]; }
  segmentree() { memset(tag, -1, sizeof(tag)); }
  inline void pushdown(int u, int l, int r) {
    if (tag[u] != -1) {
      int mid = (l + r) >> 1;
      sum[u << 1] = tag[u] * (mid - l + 1) % mod;
      sum[u << 1 | 1] = tag[u] * (r - mid) % mod;
      tag[u << 1] = tag[u], tag[u << 1 | 1] = tag[u];
      tag[u] = -1;
    }
  }
  inline void update(int u, int l, int r, int x, int y, long long v) {
    if (x <= l && y >= r) {
      sum[u] = v;
      tag[u] = v;
      return;
    } else {
      pushdown(u, l, r);
      int mid = (l + r) >> 1;
      if (x <= mid) update(u << 1, l, mid, x, y, v);
      if (y > mid) update(u << 1 | 1, mid + 1, r, x, y, v);
      pushup(u);
    }
  }
  inline long long query(int u, int l, int r, int x, int y) {
    if (x <= l && y >= r)
      return sum[u];
    else {
      long long ret = 0;
      int mid = (l + r) >> 1;
      if (x <= mid) ret += query(u << 1, l, mid, x, y) % mod;
      if (y > mid) ret += query(u << 1 | 1, mid + 1, r, x, y) % mod;
      ret %= mod;
      return ret;
    }
  }
} T0, T1;
int main() {
  m = gi(), n1 = gi(), n2 = gi();
  for (int i = 1; i <= n1; ++i) {
    int l = gi(), r = gi();
    temp[++tot] = l, temp[++tot] = r;
    if (r > 1) temp[++tot] = r - 1;
    a[0][++sum[0]].l = l;
    a[0][sum[0]].r = r;
  }
  for (int i = 1; i <= n2; ++i) {
    int l = gi(), r = gi();
    temp[++tot] = l, temp[++tot] = r;
    if (r > 1) temp[++tot] = r - 1;
    a[1][++sum[1]].l = l;
    a[1][sum[1]].r = r;
  }
  sort(temp + 1, temp + tot + 1);
  temp[++tot] = m;
  tot = unique(temp + 1, temp + tot + 1) - temp - 1;
  for (int i = 0; i <= 1; ++i) {
    for (int j = 1; j <= sum[i]; ++j) {
      a[i][j].l = lower_bound(temp + 1, temp + tot + 1, a[i][j].l) - temp;
      a[i][j].r = lower_bound(temp + 1, temp + tot + 1, a[i][j].r) - temp;
      vec[a[i][j].r].push_back(pair<int, int>(i, a[i][j].l));
    }
  }
  int n = tot;
  T0.update(1, 0, n, 0, 0, 1);
  for (int i = 1; i <= tot; ++i) {
    long long delta = temp[i] - temp[i - 1] - 1;
    delta = qpow(2, delta) - 1;
    long long x = T0.query(1, 0, n, 0, i - 1);
    long long y = T1.query(1, 0, n, 0, i - 1);
    T1.update(1, 0, n, i - 1, i - 1, T1.query(1, 0, n, i - 1, i - 1) + x);
    T0.update(1, 0, n, i - 1, i - 1, T0.query(1, 0, n, i - 1, i - 1) + y);
    x += y;
    x %= mod;
    x = (x * delta) % mod;
    T0.update(1, 0, n, i, i, x);
    T1.update(1, 0, n, i, i, x);
    for (auto z : vec[i]) {
      if (z.first == 0) T1.update(1, 0, n, 0, z.second - 1, 0);
      if (z.first == 1) T0.update(1, 0, n, 0, z.second - 1, 0);
    }
  }
  long long ans = 0;
  ans += T0.query(1, 0, n, 0, n) + T1.query(1, 0, n, 0, n);
  ans %= mod;
  printf("%lld\n", ans);
  return 0;
}
