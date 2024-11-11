#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T read() {
  T x = 0, f = 0;
  char c = getchar();
  while (!isdigit(c)) f = c == '-', c = getchar();
  while (isdigit(c)) x = x * 10 + c - 48, c = getchar();
  return f ? -x : x;
}
namespace run {
const long long N = 1e6 + 9, inf = 1e18;
long long val[N], mod;
namespace Seg {
long long sum[N << 2];
vector<long long> st[N << 2];
inline void build(long long k, long long l, long long r) {
  st[k].resize(r - l + 2);
  if (l == r)
    return sum[k] = val[l], st[k][1] = mod - val[l], st[k][0] = -inf, void();
  build((k << 1), l, ((l + r) >> 1)),
      build((k << 1 | 1), ((l + r) >> 1) + 1, r);
  st[k][0] = -inf;
  for (long long i = 1; i < r - l + 2; i++) st[k][i] = inf;
  for (long long i = 0, j = 0; i <= ((l + r) >> 1) - l + 1; i++) {
    long long vl = st[(k << 1)][i] + sum[(k << 1)] - i * mod;
    long long vr = i != ((l + r) >> 1) - l + 1
                       ? st[(k << 1)][i + 1] - 1 + sum[(k << 1)] - i * mod
                       : inf;
    if (j) j--;
    while (j + 1 < r - ((l + r) >> 1) + 1 && vl > st[(k << 1 | 1)][j + 1]) j++;
    while (j < r - ((l + r) >> 1) + 1 && vr >= st[(k << 1 | 1)][j]) {
      st[k][i + j] = min(
          st[k][i + j],
          max(st[(k << 1)][i], st[(k << 1 | 1)][j] + i * mod - sum[(k << 1)])),
                j++;
    }
  }
  sum[k] = sum[(k << 1)] + sum[(k << 1 | 1)];
}
long long now;
inline void query(long long k, long long l, long long r, long long _l,
                  long long _r) {
  if (_l <= l && r <= _r)
    return now = now + sum[k] -
                 mod * (upper_bound(st[k].begin(), st[k].end(), now) -
                        st[k].begin() - 1),
           void();
  if (_l <= ((l + r) >> 1)) query((k << 1), l, ((l + r) >> 1), _l, _r);
  if (_r > ((l + r) >> 1)) query((k << 1 | 1), ((l + r) >> 1) + 1, r, _l, _r);
}
}  // namespace Seg
using namespace Seg;
long long n, m;
long long main() {
  n = read<long long>(), m = read<long long>(), mod = read<long long>();
  for (long long i = 1; i <= n; i++) val[i] = read<long long>();
  build(1, 1, n);
  for (long long i = 1; i <= m; i++) {
    long long l = read<long long>(), r = read<long long>();
    now = val[l];
    if (now >= mod) now -= mod;
    if (l ^ r) query(1, 1, n, l + 1, r);
    printf("%lld\n", now);
  }
  return 0;
}
}  // namespace run
int main() { return run::main(); }
