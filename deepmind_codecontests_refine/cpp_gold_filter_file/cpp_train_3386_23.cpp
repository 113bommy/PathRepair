#include <bits/stdc++.h>
using namespace std;
int n, a[200005];
long long s[200005];
struct cht {
  pair<long long, long long> hull[200005];
  int p, sz;
  void init() { p = sz = 0; }
  bool ok(pair<long long, long long> a, pair<long long, long long> b,
          pair<long long, long long> c) {
    return 1ll * (a.second - b.second) * (c.first - b.first) >
           1ll * (b.first - a.first) * (b.second - c.second);
  }
  void add(long long a, long long b) {
    while (sz - 2 >= p &&
           ok(hull[sz - 2], hull[sz - 1], pair<long long, long long>(a, b))) {
      sz--;
    }
    hull[sz++] = pair<long long, long long>(a, b);
  }
  long long query(int x) {
    if (p == sz) return -1e18;
    auto func = [&](pair<long long, long long> p, int x) {
      return p.first * x + p.second;
    };
    while (p + 1 < sz && func(hull[p], x) < func(hull[p + 1], x)) p++;
    return func(hull[p], x);
  }
} cht;
int main() {
  scanf("%d", &n);
  long long base = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    base += 1ll * i * a[i];
  }
  cht.init();
  for (int i = 1; i <= n; i++) {
    s[i] = s[i - 1] + a[i];
  }
  int pmax = -1e9;
  long long ret = 0;
  for (int i = 1; i <= n; i++) {
    ret = max(ret, cht.query(i) - s[i]);
    if (a[i] > pmax) {
      pmax = a[i];
      cht.add(a[i], s[i] - 1ll * i * a[i]);
    }
  }
  cht.init();
  pmax = 1e9;
  for (int i = n; i; i--) {
    ret = max(ret, cht.query(-i) - s[i - 1]);
    if (a[i] < pmax) {
      pmax = a[i];
      cht.add(-a[i], s[i - 1] - 1ll * i * a[i]);
    }
  }
  printf("%lld", base + ret);
}
