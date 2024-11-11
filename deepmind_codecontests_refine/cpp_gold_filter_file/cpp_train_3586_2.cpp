#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
inline int check(long long now) {
  long long res = 0;
  for (long long i = 1; i <= n; i++) {
    res += min(now / i, m);
    if (res >= k) return 0;
  }
  return res < k;
}
long long erfen(long long l, long long r) {
  if (l == r) return l;
  long long mid = ((l + r) >> 1);
  if (check(mid)) return erfen(mid + 1, r);
  return erfen(l, mid);
}
int main() {
  scanf("%I64d%I64d%I64d", &n, &m, &k);
  printf("%I64d", erfen(1, n * m));
  return 0;
}
