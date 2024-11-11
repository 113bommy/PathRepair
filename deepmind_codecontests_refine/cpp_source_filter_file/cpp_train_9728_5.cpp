#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
long long M = 1e9 + 7;
const long long R = 320;
long long n, m;
long long a[N];
long long ps[R + 10];
set<pair<long long, long long> > s[R + 10];
void get() {
  long long l, r, res = 0;
  scanf("%lld%lld", &l, &r);
  long long p = l;
  while (p <= r && p % R) {
    res += a[p];
    p++;
  }
  while (p + R - 1 <= r) {
    res += ps[p / R];
    p += R;
  }
  while (p <= r) {
    res += a[p];
    p++;
  }
  printf("%lld ", res);
}
void upd(long long p, long long x) {
  s[p / R].erase({-a[p], p});
  ps[p / R] -= a[p];
  a[p] = x;
  s[p / R].insert({-a[p], p});
  ps[p / R] += a[p];
}
void mod() {
  long long l, r, x;
  scanf("%lld%lld%lld", &l, &r, &x);
  long long p = l;
  while (p <= r && p % R) {
    if (a[p] >= x) upd(p, a[p] % x);
    p++;
  }
  while (p + R - 1 <= r) {
    while (-s[p / R].begin()->first >= x) {
      upd(s[p / R].begin()->second, (-s[p / R].begin()->first) % x);
    }
    p += R;
  }
  while (p <= r) {
    if (a[p] > x) upd(p, (a[p] % x));
    p++;
  }
}
int32_t main() {
  scanf("%lld%lld", &n, &m);
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    ps[i / R] += a[i];
    s[i / R].insert({-a[i], i});
  }
  while (m--) {
    long long type;
    scanf("%lld", &type);
    if (type == 1) get();
    if (type == 2) mod();
    if (type == 3) {
      long long p, x;
      scanf("%lld%lld", &p, &x);
      upd(p, x);
    }
  }
  return 0;
}
