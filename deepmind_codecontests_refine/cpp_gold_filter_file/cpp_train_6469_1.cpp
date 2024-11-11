#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int maxn = 2e5 + 50;
const long long inf = 1e17;
int n, m;
long long a[maxn], k[maxn], ks[maxn];
long long sumk[maxn];
struct SegTree {
  long long sum[maxn << 2], flag[maxn << 2];
  void build(int o, int l, int r) {
    flag[o] = inf;
    if (l == r) {
      sum[o] = a[l] - sumk[l];
      return;
    }
    int mid = (l + r) / 2;
    build(o << 1, l, mid);
    build(o << 1 | 1, mid + 1, r);
    sum[o] = sum[o << 1] + sum[o << 1 | 1];
  }
  void push_down(int o, int l, int r) {
    if (flag[o] == inf) return;
    int mid = (l + r) / 2;
    flag[o << 1] = flag[o << 1 | 1] = flag[o];
    sum[o << 1] = flag[o] * (mid - l + 1);
    sum[o << 1 | 1] = flag[o] * (r - mid);
    flag[o] = inf;
  }
  void update(int o, int l, int r, int ql, int qr, long long v) {
    if (ql <= l && r <= qr) {
      flag[o] = v;
      sum[o] = v * (r - l + 1);
      return;
    }
    int mid = (l + r) / 2;
    push_down(o, l, r);
    if (ql <= mid) update(o << 1, l, mid, ql, qr, v);
    if (qr > mid) update(o << 1 | 1, mid + 1, r, ql, qr, v);
    sum[o] = sum[o << 1] + sum[o << 1 | 1];
  }
  long long query(int o, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return sum[o];
    int mid = (l + r) / 2;
    push_down(o, l, r);
    long long res = 0;
    if (ql <= mid) res += query(o << 1, l, mid, ql, qr);
    if (qr > mid) res += query(o << 1 | 1, mid + 1, r, ql, qr);
    return res;
  }
} segtree;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (int i = 1; i < n; i++) scanf("%lld", &k[i]);
  for (int i = 2; i <= n; i++) sumk[i] = sumk[i - 1] + k[i - 1];
  for (int i = 2; i <= n; i++) ks[i] = ks[i - 1] + sumk[i];
  segtree.build(1, 1, n);
  scanf("%d", &m);
  while (m--) {
    char op[5];
    int l, r;
    scanf("%s%d%d", op, &l, &r);
    if (op[0] == 's')
      printf("%lld\n",
             segtree.query(1, 1, n, l, r) + ks[r] - (l >= 1 ? ks[l - 1] : 0));
    else {
      int L = l, R = n, mid, ans = l;
      long long sum = segtree.query(1, 1, n, l, l) + r;
      while (L <= R) {
        mid = (L + R) / 2;
        if (sum > segtree.query(1, 1, n, mid, mid)) {
          ans = mid;
          L = mid + 1;
        } else
          R = mid - 1;
      }
      segtree.update(1, 1, n, l, ans, sum);
    }
  }
  return 0;
}
