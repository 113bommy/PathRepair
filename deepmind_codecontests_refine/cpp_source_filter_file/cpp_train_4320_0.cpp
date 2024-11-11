#include <bits/stdc++.h>
using namespace std;
bool exitInput = false;
int ntest = 1, itest = 1;
const char* directions[4] = {"NE", "SE", "SW", "NW"};
const long long Mod = 1000000000LL + 7;
const int maxn = 200000 + 5;
const int maxv = 500000 + 5;
const int maxe = 600000 + 5;
const int root = 1;
int n, a[maxn], LogN, rmq[maxn][18];
int it[4 * maxn + 4], lazy[4 * maxn + 4];
void lazy_update(int node, int l, int r) {
  if (lazy[node] == 0) return;
  it[node] = max(it[node], lazy[node]);
  if (l != r) {
    lazy[(node << 1)] = max(lazy[(node << 1)], lazy[node]);
    lazy[((node << 1) | 1)] = max(lazy[((node << 1) | 1)], lazy[node]);
    lazy[node] = 0;
  }
}
void update(int node, int l, int r, int x, int val) {
  lazy_update(node, l, r);
  if (l > x) return;
  if (r <= x) {
    it[node] = max(it[node], val);
    if (l != r) {
      lazy[(node << 1)] = max(lazy[(node << 1)], val);
      lazy[((node << 1) | 1)] = max(lazy[((node << 1) | 1)], val);
    }
    return;
  }
  update((node << 1), l, ((l + r) >> 1), x, val);
  update(((node << 1) | 1), ((l + r) >> 1) + 1, r, x, val);
  it[node] = max(it[(node << 1)], it[((node << 1) | 1)]);
}
int get(int node, int l, int r, int x) {
  lazy_update(node, l, r);
  if (l > x || r < x) return 0;
  if (l == r && r == x) {
    return it[node];
  }
  int p1 = get((node << 1), l, ((l + r) >> 1), x);
  int p2 = get(((node << 1) | 1), ((l + r) >> 1) + 1, r, x);
  return max(p1, p2);
}
void build_rmq() {
  int i, j, k;
  for (LogN = 1; (1 << LogN) <= n; ++LogN)
    ;
  --LogN;
  for (i = 1; i <= n; ++i) rmq[i][0] = a[i];
  for (j = 1; j <= LogN; ++j) {
    for (i = 1; i + (1 << j) - 1 <= n; ++i) {
      k = i + (1 << (j - 1));
      rmq[i][j] = min(rmq[i][j - 1], rmq[k][j - 1]);
    }
  }
}
int get_min(int i, int j) {
  int len = j - i + 1;
  int k;
  for (k = 1; (1 << k) <= len; ++k)
    ;
  --k;
  return min(rmq[i][k], rmq[j - (1 << k) + 1][k]);
}
int get_left(int idx) {
  int lo = 1, hi = idx, mid, res = idx;
  int k;
  while (lo <= hi) {
    mid = (lo + hi) >> 1;
    k = get_min(mid, idx);
    if (k >= a[idx]) {
      res = mid;
      hi = mid - 1;
    } else
      lo = mid + 1;
  }
  return res;
}
int get_right(int idx) {
  int lo = idx, hi = n, mid, res = idx;
  int k;
  while (lo <= hi) {
    mid = (lo + hi) >> 1;
    k = get_min(mid, idx);
    if (k >= a[idx]) {
      res = mid;
      lo = mid + 1;
    } else
      hi = mid - 1;
  }
  return res;
}
int main() {
  int i, j, k;
  int x, res;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  build_rmq();
  int L, R;
  for (i = 1; i <= n; ++i) {
    L = get_left(i);
    R = get_right(i);
    update(1, 1, n, R - L + 1, a[i]);
  }
  for (i = 1; i <= n; ++i) {
    k = get(1, 1, n, i);
    printf("%d ", k);
  }
  return 0;
}
