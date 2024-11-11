#include <bits/stdc++.h>
using namespace std;
int n, sz, a[100000 + 5], bl[100000 + 5];
long long f[100000 + 5];
inline bool cmp(const int& x, const int& y) { return a[x] < a[y]; }
namespace FastIO {
int Ff;
char oc, FI[100000], *FA = FI, *FB = FI;
template <typename Ty>
inline void read(Ty& x) {
  x = 0, Ff = 1;
  while (!isdigit(
      oc = (FA == FB && (FB = (FA = FI) + fread(FI, 1, 100000, stdin), FA == FB)
                ? EOF
                : *FA++)))
    Ff = oc ^ '-' ? 1 : -1;
  while (
      x = (x << 3) + (x << 1) + (oc & 15),
      isdigit(oc = (FA == FB && (FB = (FA = FI) + fread(FI, 1, 100000, stdin),
                                 FA == FB)
                        ? EOF
                        : *FA++)))
    ;
  x *= Ff;
}
template <typename Ty, typename... Ar>
inline void read(Ty& x, Ar&... y) {
  read(x), read(y...);
}
}  // namespace FastIO
using namespace FastIO;
struct Block {
  int H, T, q[320 + 5], p[320 + 5];
  long long t, b;
  inline void Build(const int& L, const int& R) {
    register int i;
    for (i = L; i <= R; ++i) f[p[i - L + 1] = i] += a[i] * t + b;
    t = b = 0;
    sort(p + 1, p + R - L + 2, cmp);
    for (H = 1, T = 0, i = 1; i <= R - L + 1; q[++T] = p[i++])
      while (H < T &&
             (a[q[T - 1]] ^ a[q[T]]
                  ? 1.0 * (f[q[T]] - f[q[T - 1]]) / (a[q[T]] - a[q[T - 1]])
                  : (f[q[T]] > f[q[T - 1]] ? 1e18 : -1e18)) <
                 (a[q[T]] ^ a[p[i]]
                      ? 1.0 * (f[p[i]] - f[q[T]]) / (a[p[i]] - a[q[T]])
                      : (f[p[i]] > f[q[T]] ? 1e18 : -1e18)))
        --T;
  }
  inline pair<long long, int> Q() {
    while (H < T &&
           (f[q[H]] + a[q[H]] * t + b) < (f[q[H + 1]] + a[q[H + 1]] * t + b))
      ++H;
    return make_pair((f[q[H]] + a[q[H]] * t + b), q[H]);
  }
} B[320 + 5];
int main() {
  register int i, x;
  for (read(n), sz = sqrt(n), i = 1; i <= n; ++i)
    read(a[i]), bl[i] = (i - 1) / sz + 1, f[i] = a[i];
  for (i = 1; i <= bl[n]; ++i) B[i].Build((i - 1) * sz + 1, min(i * sz, n));
  pair<long long, int> k;
  long long ans = 0;
  while (true) {
    for (k = make_pair(0LL, 0), i = 1; i <= bl[n]; ++i) k = max(k, B[i].Q());
    if (!k.first) break;
    ans += k.first, x = k.second;
    for (i = 1; i ^ bl[x]; ++i) B[i].b += a[x];
    for (i = bl[x] + 1; i <= bl[n]; ++i) ++B[i].t;
    for (i = (bl[x] - 1) * sz + 1; i ^ x; ++i) f[i] += a[x];
    for (i = x + 1; i <= min(bl[x] * sz, n); ++i) f[i] += a[i];
    f[x] = -1e18, B[bl[x]].Build((bl[x] - 1) * sz + 1, min(bl[x] * sz, n));
  }
  return printf("%lld\n", ans), 0;
}
