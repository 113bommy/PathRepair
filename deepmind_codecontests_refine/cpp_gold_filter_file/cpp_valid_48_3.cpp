#include <bits/stdc++.h>
using namespace std;
int aabs(int x) {
  if (x < 0) return -x;
  return x;
}
long long n, q;
long long a[100030], b[100030], c[100030], pre[100030], npre[100030];
long long minx[100030 << 2], maxx[100030 << 2];
void build(int o, int l, int r) {
  if (l == r) {
    maxx[o] = minx[o] = pre[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(o << 1, l, mid);
  build(o << 1 | 1, mid + 1, r);
  minx[o] = min(minx[o << 1], minx[o << 1 | 1]);
  maxx[o] = max(maxx[o << 1], maxx[o << 1 | 1]);
}
long long querymax(int o, int l, int r, int ql, int qr) {
  if (ql <= l && qr >= r) return maxx[o];
  int mid = (l + r) >> 1;
  long long nowmax = -1e17 - 10;
  if (ql <= mid) nowmax = max(nowmax, querymax(o << 1, l, mid, ql, qr));
  if (qr > mid) nowmax = max(nowmax, querymax(o << 1 | 1, mid + 1, r, ql, qr));
  return nowmax;
}
long long querymin(int o, int l, int r, int ql, int qr) {
  if (ql <= l && qr >= r) return minx[o];
  int mid = (l + r) >> 1;
  long long nowmin = 1e17 + 10;
  if (ql <= mid) nowmin = min(nowmin, querymin(o << 1, l, mid, ql, qr));
  if (qr > mid) nowmin = min(nowmin, querymin(o << 1 | 1, mid + 1, r, ql, qr));
  return nowmin;
}
int main() {
  scanf("%lld%lld", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &b[i]);
    c[i] = b[i] - a[i];
    pre[i] = c[i] + pre[i - 1];
  }
  build(1, 0, n);
  for (int i = 1; i <= q; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    if (pre[r] - pre[l - 1] != 0)
      printf("-1\n");
    else if (querymin(1, 0, n, l, r) - pre[l - 1] < 0)
      printf("-1\n");
    else {
      printf("%lld\n", querymax(1, 0, n, l, r) - pre[l - 1]);
    }
  }
  return 0;
}
