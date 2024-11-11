#include <bits/stdc++.h>
using namespace std;
long long N, M, cnt, Q;
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long id(long long x, long long y) {
  if (x == 1)
    return (y - 1) / (N / cnt) + 1;
  else
    return (y - 1) / (M / cnt) + 1;
}
int main() {
  scanf("%lld%lld%lld", &N, &M, &Q);
  cnt = gcd(N, M);
  while (Q--) {
    long long sx, sy, ex, ey;
    scanf("%lld%lld%lld%lld", &sx, &sy, &ex, &ey);
    id(sx, sy) == id(ex, ey) ? puts("YES") : puts("NO");
  }
  return 0;
}
