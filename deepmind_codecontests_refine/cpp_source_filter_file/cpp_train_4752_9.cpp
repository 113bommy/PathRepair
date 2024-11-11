#include <bits/stdc++.h>
long long a, b, p;
long long x, ans, po;
long long inv(int x, int y) {
  long long ans = 1;
  for (long long now = x; y; y /= 2, now = now * now % p)
    if (y & 1) ans = ans * now % p;
  return ans;
}
int cal(int mi, int n) {
  long long now = 1ll * b * inv(mi, p - 2) % p;
  long long ans = n + 1ll * (p - 1) * ((n - now + p + p) % p);
  if (ans > x) return 0;
  return (x - ans) / (1ll * p * (p - 1)) + 1;
}
int main() {
  scanf("%lld%lld%lld%lld", &a, &b, &p, &x);
  po = 1;
  for (int i = 1; i < p; i++) {
    po = po * a % p;
    ans += cal(po, i);
  }
  printf("%lld", ans);
}
