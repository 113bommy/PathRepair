#include <bits/stdc++.h>
using namespace std;
long long in() {
  long long a;
  scanf("%lld", &a);
  return a;
}
double din() {
  double a;
  scanf("%lf", &a);
  return a;
}
long long bigmod(long long b, long long p, long long md) {
  if (p == 0) return 1;
  if (p % 2 == 1) {
    return ((b % md) * bigmod(b, p - 1, md)) % md;
  } else {
    long long y = bigmod(b, p / 2, md);
    return (y * y) % md;
  }
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long getRandom(long long a, long long b) {
  long long ret = (long long)rand() * (long long)rand();
  ret %= (b - a + 1);
  ret += a;
  return ret;
}
int par[100005], sz[100005];
int fi_par(int u) {
  if (par[u] == u) return u;
  return par[u] = fi_par(par[u]);
}
int main() {
  int n = in(), m = in();
  for (int i = 0; i <= n; i++) par[i] = i, sz[i] = 1;
  ;
  int cnt = m;
  for (int i = 0; i < m; i++) {
    int a = in(), b = in();
    a = fi_par(a);
    b = fi_par(b);
    if (a != b) {
      cnt--;
      par[a] = b;
      sz[b] += sz[a];
    }
  }
  cnt = 0;
  for (int i = 1; i <= n; i++)
    if (par[i] == i) cnt += (sz[i] - 1);
  printf("%lld\n", (long long)m - cnt);
}
