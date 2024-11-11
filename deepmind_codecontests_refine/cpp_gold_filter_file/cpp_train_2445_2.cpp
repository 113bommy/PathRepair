#include <bits/stdc++.h>
using namespace std;
long long a, b, n;
long long L, t, m;
long long qmod(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
bool ok(long long R) {
  long long sum =
      a * (R - L + 1) + b * (R * (R - 1) / 2 - (L - 1) * (L - 2) / 2);
  if (t < a + (R - 1ll) * b) return false;
  if (sum <= 1ll * t * m) return true;
  return false;
}
int main() {
  scanf("%lld%lld%lld", &a, &b, &n);
  for (int i = 0; i < int(n); i++) {
    scanf("%lld%lld%lld", &L, &t, &m);
    int l = L, r = 1e9 + 7;
    while (l + 1 < r) {
      int m = (l + r) >> 1;
      if (ok(m))
        l = m;
      else
        r = m;
    }
    printf("%d\n", ok(l) ? l : -1);
  }
  return 0;
}
