#include <bits/stdc++.h>
using namespace std;
const int MN = 1e5 + 5, mod = 1e9 + 7;
int par[MN], cnt[MN], N, f[MN];
long long sz[MN];
inline void inc(int &x, int y) { x = x + y < mod ? x + y : x + y - mod; }
inline int gcd(int x, int y) {
  if (y == 0)
    return x;
  else
    return gcd(y, x % y);
}
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) scanf("%lld", &sz[i]);
  for (int i = 2; i <= N; ++i) scanf("%d", &par[i]);
  for (int i = N; i > 0; --i) sz[par[i]] += sz[i];
  long long s = sz[1];
  for (int i = 1; i <= N; ++i) {
    long long x = s / gcd(s, sz[i]);
    if (x <= N) ++cnt[x];
  }
  for (int i = N; i; --i)
    for (int j = i + i; j <= N; j += i) cnt[j] += cnt[i];
  f[1] = 1;
  int res = 0;
  for (int i = 1; i <= N; ++i) {
    inc(res, f[i]);
    for (int j = 2 * i; j <= N; j += i)
      if (cnt[j] == j) inc(f[j], f[i]);
  }
  printf("%d\n", res);
  return 0;
}
