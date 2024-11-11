#include <bits/stdc++.h>
using namespace std;
long long k[1000007];
bool cmp(long long a, long long b) { return a > b; }
long long qpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans = (ans * a) % (1000000007);
    }
    a = (a * a) % (1000000007);
    b >>= 1;
  }
  return ans;
}
long long qpow2(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans = (ans * a) % (1000000006);
    }
    a = (a * a) % (1000000006);
    b >>= 1;
  }
  return ans;
}
int main() {
  long long i, n, j, t, u, v, p;
  scanf("%lld", &t);
  while (t--) {
    long long ans = 0, ansn = 0;
    scanf("%lld%lld", &n, &p);
    for (i = 1; i <= n; i++) scanf("%lld", &k[i]);
    sort(k + 1, k + 1 + n, cmp);
    for (i = 1; i <= n; i++) {
      if (!ans && !ansn)
        ans = (ans + qpow(p, k[i])) % (1000000007),
        ansn = (ansn + qpow(p, k[i])) % (1000000007);
      else {
        ans = (ans - qpow(p, k[i]) + (1000000007)) % (1000000007);
        ansn = (ansn - qpow(p, k[i]) + (1000000006)) % (1000000006);
      }
    }
    printf("%lld\n", ans);
  }
}
