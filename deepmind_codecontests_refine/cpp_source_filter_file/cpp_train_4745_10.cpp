#include <bits/stdc++.h>
using LL = long long;
const int MAXN = 10000031;
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
LL exp(LL a, LL b) {
  LL ans = 1;
  for (; b; b >>= 1) {
    if (b & 1) {
      ans *= a;
    }
    a *= a;
  }
  return ans;
}
LL n = 0, l = 0, r = 0;
LL p[MAXN];
LL solve() {
  if (n == 1) {
    return r - l + 1;
  }
  if (n == 2) {
    return (r - l + 1) * (r - l);
  }
  LL t = pow(r, 1.0 / (n - 1)), ans = 0;
  for (int i = 1; i <= t; i++) {
    p[i] = exp(i, n - 1);
  }
  for (int b = 1; b <= t; b++) {
    for (int a = 1; a < b; a++) {
      if (gcd(a, b) == 1) {
        ans += std::max(0LL, r / p[b] - (l - 1) / p[a]);
      }
    }
  }
  return ans << 1;
}
int main() {
  scanf("%I64d%I64d%I64d", &n, &l, &r);
  printf("%I64d\n", solve());
  return 0;
}
