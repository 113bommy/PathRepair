#include <bits/stdc++.h>
using namespace std;
inline void In(long long _, ...) {
  va_list lis;
  va_start(lis, _);
  while (_--) scanf("%lld", va_arg(lis, long long *));
}
inline void Out(long long _, ...) {
  va_list lis;
  va_start(lis, _);
  while (_--) printf("%lld\n", va_arg(lis, long long));
}
inline void Out_(long long _, ...) {
  va_list lis;
  va_start(lis, _);
  while (_--) printf("%lld ", va_arg(lis, long long));
  puts("");
}
struct Node {
  long long x, s, l, r;
  bool operator<(const Node &tmp) const { return l > tmp.l; }
} a[85];
long long n, m;
long long f[(long long)1E5 + 10];
int main() {
  In(2, &n, &m);
  for (int(i) = (1); (i) <= (n); ++(i)) {
    In(2, &a[i].x, &a[i].s);
    a[i].l = max(0ll, a[i].x - a[i].s);
    a[i].r = min(m, a[i].x + a[i].s);
  }
  sort(a + 1, a + n + 1);
  for (int j = m; j >= 0; --j) {
    f[j] = m - j;
    for (int(i) = (1); (i) <= (n); ++(i)) {
      if (a[i].l <= j + 1 && a[i].r >= j + 1) {
        f[j] = f[a[i].r];
        break;
      }
      if (j < a[i].l) {
        long long dis = a[i].l - j - 1;
        f[j] = min(f[j], dis + f[min(m, a[i].r + dis)]);
      }
    }
  }
  Out(1, f[0]);
}
