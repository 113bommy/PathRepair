#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const long long MOD = 1e9 + 7;
int n, m;
struct Box {
  long long loc, weight;
} a[N];
struct Push_R {
  long long l, r, weight, cost;
};
Push_R operator+(const Push_R a, const Push_R b) {
  Push_R res;
  res.weight = (a.weight + b.weight) % MOD;
  res.l = b.l - (a.r - a.l + 1), res.r = b.r;
  res.cost = (a.cost + b.cost + a.weight * (b.l - a.r - 1)) % MOD;
  return res;
}
struct Push_L {
  long long l, r, weight, cost;
};
Push_L operator+(const Push_L a, const Push_L b) {
  Push_L res;
  res.weight = (a.weight + b.weight) % MOD;
  res.l = a.l, res.r = a.r + (b.r - b.l + 1);
  res.cost = (a.cost + b.cost + b.weight * (b.l - a.r - 1)) % MOD;
  return res;
}
struct Seg_Tree {
  struct Node {
    Push_L L;
    Push_R R;
  } tr[N << 2];
  void up(int u) {
    tr[u].L = tr[u << 1].L + tr[u << 1 | 1].L;
    tr[u].R = tr[u << 1].R + tr[u << 1 | 1].R;
  }
  void build(int u, int l, int r, Box a[]) {
    if (l == r) {
      tr[u].L.l = tr[u].L.r = a[l].loc;
      tr[u].L.weight = a[l].weight, tr[u].L.cost = 0;
      tr[u].R.l = tr[u].R.r = a[l].loc;
      tr[u].R.weight = a[l].weight, tr[u].R.cost = 0;
      return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid, a);
    build(u << 1 | 1, mid + 1, r, a);
    up(u);
  }
  void chg(int u, int l, int r, int x, Box z) {
    if (l == r) {
      tr[u].L.weight = z.weight;
      tr[u].R.weight = z.weight;
      return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
      chg(u << 1, l, mid, x, z);
    else
      chg(u << 1 | 1, mid + 1, r, x, z);
    up(u);
  }
  Push_L query_L(int u, int l, int r, int x, int y) {
    if (x <= l && r <= y) return tr[u].L;
    int mid = (l + r) >> 1;
    Push_L tmp1, tmp2;
    if (x <= mid) tmp1 = query_L(u << 1, l, mid, x, y);
    if (y > mid) tmp2 = query_L(u << 1 | 1, mid + 1, r, x, y);
    if (x <= mid && y > mid) return tmp1 + tmp2;
    return x <= mid ? tmp1 : tmp2;
  }
  Push_R query_R(int u, int l, int r, int x, int y) {
    if (x <= l && r <= y) return tr[u].R;
    int mid = (l + r) >> 1;
    Push_R tmp1, tmp2;
    if (x <= mid) tmp1 = query_R(u << 1, l, mid, x, y);
    if (y > mid) tmp2 = query_R(u << 1 | 1, mid + 1, r, x, y);
    if (x <= mid && y > mid) return tmp1 + tmp2;
    return x <= mid ? tmp1 : tmp2;
  }
} t1;
struct Tree_Array {
  long long tr[N];
  int lowbit(int x) { return x & (-x); }
  void add(int k, long long x) {
    for (; k <= n; k += lowbit(k)) tr[k] += x;
  }
  long long sum(int k) {
    long long res = 0;
    for (; k; k -= lowbit(k)) res += tr[k];
    return res;
  }
} t2;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) scanf("%lld", &a[i].loc);
  for (int i = 1; i <= n; ++i) scanf("%lld", &a[i].weight);
  for (int i = 1; i <= n; ++i) t2.add(i, a[i].weight);
  t1.build(1, 1, n, a);
  while (m--) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x < 0) {
      t2.add(-x, -a[-x].weight);
      a[-x].weight = y;
      t1.chg(1, 1, n, -x, a[-x]);
      t2.add(-x, a[-x].weight);
    } else {
      int l = x, r = y, tmp = -1;
      while (l <= r) {
        int mid = (l + r) >> 1;
        long long sum1 = t2.sum(mid) - t2.sum(x - 1);
        long long sum2 = t2.sum(y) - t2.sum(mid);
        if (sum1 >= sum2)
          r = mid - 1, tmp = mid;
        else
          l = mid + 1;
      }
      Push_R tmp1 = t1.query_R(1, 1, n, x, tmp);
      Push_L tmp2 = t1.query_L(1, 1, n, tmp, y);
      printf("%lld\n", (tmp1.cost + tmp2.cost) % MOD);
    }
  }
  return 0;
}
