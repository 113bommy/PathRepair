#include <bits/stdc++.h>
using namespace std;
long long n, edges[50], fans;
void kapjapalgo(long long r, long long p, long long x) {
  if (p == 0 && x == 0) {
    fans = max(fans, (long long)__builtin_popcountll(r));
    return;
  }
  int u = 0;
  while (!((1LL << u) & (p | x))) u++;
  for (int v = 0; v < n; v++) {
    if (((1LL << v) & p) && !((1LL << v) & edges[u])) {
      kapjapalgo(r | (1LL << v), p & edges[u], x & edges[u]);
      p -= (1LL << v);
      x |= (1LL << v);
    }
  }
}
int main() {
  long long k;
  scanf("%lld %lld", &n, &k);
  long long a;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%lld", &a);
      if (a > 0) edges[i] |= (1LL << j);
    }
  }
  kapjapalgo(0, (1LL << n) - 1, 0);
  long long ans = (fans * (fans - 1)) / 2LL;
  double ffans = ans * ((1.0 * k * k) / (1.0 * fans * fans));
  printf("%.9f\n", ffans);
  return 0;
}
