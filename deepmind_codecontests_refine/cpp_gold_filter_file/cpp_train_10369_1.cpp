#include <bits/stdc++.h>
long long mod = 1000000000000000007ll;
using namespace std;
int n;
long long x, y, l, r;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
int main() {
  int i, j, fl, test;
  set<long long> tmp;
  scanf("%lld%lld%lld%lld", &x, &y, &l, &r);
  for (i = 0; i <= 63; i++) {
    for (j = 0; j <= 63; j++) {
      if (log(r) / log(x) >= i && log(r) / log(y) >= j) {
        long long S = powmod(x, i) + powmod(y, j);
        if (S >= l && S <= r) tmp.insert(S);
      }
    }
  }
  long long ans = 0;
  long long prev = l;
  for (set<long long>::iterator it = tmp.begin(); it != tmp.end(); it++) {
    long long xx = *it;
    ans = max(ans, xx - prev);
    prev = xx + 1;
  }
  ans = max(ans, r - prev + 1);
  printf("%lld\n", ans);
  return 0;
}
