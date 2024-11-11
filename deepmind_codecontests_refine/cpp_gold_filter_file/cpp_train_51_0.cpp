#include <bits/stdc++.h>
using namespace std;
long long n, k, a, b, q, i, j;
long long tp, l, r;
long long t1[888888], ta[888888], tb[888888];
void update(long long v, long long s, long long e, long long h, long long del) {
  long long m = (s + e) / 2;
  if (s == e) {
    t1[v] += del;
    if (t1[v] >= b) tb[v] = t1[v] - b;
    if (t1[v] >= a) ta[v] = t1[v] - a;
    return;
  }
  if (h <= m)
    update(v * 2, s, m, h, del);
  else
    update(v * 2 + 1, m + 1, e, h, del);
  t1[v] = t1[v * 2] + t1[v * 2 + 1];
  ta[v] = ta[v * 2] + ta[v * 2 + 1];
  tb[v] = tb[v * 2] + tb[v * 2 + 1];
}
long long qaqb(long long v, long long s, long long e, long long l,
               long long r) {
  long long m = (s + e) / 2;
  if (l > r) return 0;
  if (l == s && e == r) return t1[v] - tb[v];
  return qaqb(v * 2, s, m, l, min(r, m)) +
         qaqb(v * 2 + 1, m + 1, e, max(l, m + 1), r);
}
long long qaqa(long long v, long long s, long long e, long long l,
               long long r) {
  long long m = (s + e) / 2;
  if (l > r) return 0;
  if (l == s && e == r) return t1[v] - ta[v];
  return qaqa(v * 2, s, m, l, min(r, m)) +
         qaqa(v * 2 + 1, m + 1, e, max(l, m + 1), r);
}
int main() {
  scanf("%lld%lld%lld%lld%lld", &n, &k, &a, &b, &q);
  for (i = 1; i <= q; i++) {
    scanf("%lld%lld", &tp, &l);
    if (tp == 1) {
      scanf("%lld", &r);
      update(1, 1, n, l, r);
    } else {
      long long sum = qaqb(1, 1, n, 1, l - 1) + qaqa(1, 1, n, l + k, n);
      printf("%lld\n", sum);
    }
  }
  return 0;
}
