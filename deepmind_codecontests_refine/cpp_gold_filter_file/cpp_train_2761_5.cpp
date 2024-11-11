#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 20;
long long sa[N << 2], sb[N << 2];
long long ay[N];
int a, b;
void update(int l, int r, int o, int x, int y) {
  if (l == r) {
    if (ay[l] >= a) {
      ay[l] += y;
      return;
    }
    sa[o] += min((long long)y, a - ay[l]);
    if (ay[l] >= b) {
      ay[l] += y;
      return;
    }
    sb[o] += min((long long)y, b - ay[l]);
    ay[l] += y;
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid)
    update(l, mid, o << 1, x, y);
  else
    update(mid + 1, r, o << 1 | 1, x, y);
  sb[o] = sb[o << 1] + sb[o << 1 | 1];
  sa[o] = sa[o << 1] + sa[o << 1 | 1];
}
long long ansa;
long long ansb;
void sum(int l, int r, int o, int L, int R) {
  if (L <= l && r <= R) {
    ansa += sa[o];
    ansb += sb[o];
    return;
  }
  int mid = (l + r) >> 1;
  if (L <= mid) sum(l, mid, o << 1, L, R);
  if (mid < R) sum(mid + 1, r, o << 1 | 1, L, R);
}
int main() {
  int n, k, q;
  cin >> n >> k >> a >> b >> q;
  for (int i = 0; i < q; i++) {
    int mk, c, d;
    scanf("%d", &mk);
    if (mk == 1) {
      scanf("%d%d", &c, &d);
      update(1, n, 1, c, d);
    } else {
      scanf("%d", &c);
      ansa = ansb = 0;
      long long tmp = 0;
      if (c - 1 > 0) sum(1, n, 1, 1, c - 1);
      tmp += ansb;
      ansa = ansb = 0;
      if (c + k <= n) sum(1, n, 1, c + k, n);
      tmp += ansa;
      printf("%I64d\n", tmp);
    }
  }
  return 0;
}
