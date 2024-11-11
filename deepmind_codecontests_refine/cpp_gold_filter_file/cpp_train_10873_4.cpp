#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
long long n, m, k, l, r;
long long x;
struct SegTree {
  long long l, r;
  long long data, sum;
  long long lazy;
} t[4 * N];
void build(long long p, long long l, long long r) {
  t[p].l = l;
  t[p].r = r;
  if (l == r) {
    t[p].data = l;
    return;
  }
  long long mid = l + r >> 1;
  build(p * 2, l, mid);
  build(p * 2 + 1, mid + 1, r);
}
void spread(long long p) {
  if (t[p].lazy) {
    t[p * 2].data = t[p * 2 + 1].data = t[p].data;
    t[p * 2].lazy += t[p].lazy;
    t[p * 2 + 1].lazy += t[p].lazy;
    t[p * 2].sum += (t[p * 2].r - t[p * 2].l + 1) * t[p].lazy;
    t[p * 2 + 1].sum += (t[p * 2 + 1].r - t[p * 2 + 1].l + 1) * t[p].lazy;
    t[p].lazy = 0;
    t[p].data = 0;
  }
}
void change(long long p, long long l, long long r, long long x) {
  if (t[p].l >= l && t[p].r <= r && t[p].data) {
    t[p].sum += abs(t[p].data - x) * (t[p].r - t[p].l + 1);
    t[p].lazy += abs(t[p].data - x);
    t[p].data = x;
  } else {
    spread(p);
    long long mid = t[p].l + t[p].r >> 1;
    if (mid >= l) change(p * 2, l, r, x);
    if (mid < r) change(p * 2 + 1, l, r, x);
    t[p].sum = t[p * 2].sum + t[p * 2 + 1].sum;
    t[p].data = t[p * 2].data == t[p * 2 + 1].data ? t[p * 2].data : 0;
  }
}
long long ask(long long p, long long l, long long r) {
  if (t[p].l >= l && t[p].r <= r) {
    return t[p].sum;
  }
  spread(p);
  long long mid = t[p].l + t[p].r >> 1;
  long long res = 0;
  if (mid >= l) res += ask(p * 2, l, r);
  if (mid < r) res += ask(p * 2 + 1, l, r);
  return res;
}
int main() {
  scanf("%lld%lld", &n, &m);
  build(1, 1, n);
  for (int i = 1; i <= m; i++) {
    scanf("%lld%lld%lld", &k, &l, &r);
    if (k == 1) {
      scanf("%lld", &x);
      change(1, l, r, x);
    } else {
      printf("%lld\n", ask(1, l, r));
    }
  }
  return 0;
}
