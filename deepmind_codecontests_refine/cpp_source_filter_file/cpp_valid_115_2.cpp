#include <bits/stdc++.h>
using namespace std;
const long long mo = 998244353, N = 1e6 + 5;
inline long long add(long long x, long long y) {
  return x + y >= mo ? x + y - mo : x + y;
}
inline long long sub(long long x, long long y) {
  return x - y < 0 ? x - y + mo : x - y;
}
inline long long mul(long long x, long long y) { return 1ll * x * y % mo; }
inline long long fast(long long a, long long b) {
  register long long ans = 1;
  while (b) b & 1 && (ans = mul(ans, a)), a = mul(a, a), b >>= 1;
  return ans;
}
long long n, m, k, x, y, t, pw[N], a[3], b[3], rc[2];
map<pair<long long, long long>, long long> now;
vector<long long> r[2], c[2];
signed main() {
  scanf("%lld%lld%lld", &n, &m, &k);
  a[2] = n, b[2] = m;
  pw[0] = 1;
  for (register long long i = 1; i <= min(n, m); ++i)
    pw[i] = add(pw[i - 1], pw[i - 1]);
  for (register long long i = 1; i <= max(n, m) + 2; ++i)
    r[0].push_back(0), r[1].push_back(0), c[0].push_back(0), c[1].push_back(0);
  while (k--) {
    scanf("%lld%lld%lld", &x, &y, &t);
    --a[2 - (bool)r[0][x] - (bool)r[1][x]],
        --b[2 - (bool)c[0][y] - (bool)c[1][y]];
    if (now.count(make_pair(x, y)) && ~now[make_pair(x, y)])
      --r[(y ^ now[{x, y}]) & 1][x], --c[(x ^ now[{x, y}]) & 1][y],
          --rc[(x ^ y ^ now[{x, y}]) & 1];
    now[make_pair(x, y)] = t;
    if (t != -1)
      ++r[(y ^ t) & 1][x], ++c[(x ^ t) & 1][y], ++rc[(x ^ y ^ t) & 1];
    ++a[2 - (bool)r[0][x] - (bool)r[1][x]],
        ++b[2 - (bool)c[0][y] - (bool)c[1][y]];
    printf("%lld\n", sub(add(a[0] ? 0 : pw[a[2]], b[0] ? 0 : pw[b[2]]),
                         (2 - (bool)rc[0] - (bool)rc[1])));
  }
  return rand() & 0;
}
