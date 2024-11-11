#include <bits/stdc++.h>
using namespace std;
long long mod;
pair<long long, long long> inrange_sum(long long l, long long r, long long u,
                                       long long v, long long n) {
  if (u > v)
    return make_pair(0LL, 0LL);
  else if (l == 1 && r == n) {
    long long cnt = v - u + 1;
    long long mul = u + v;
    if (cnt & 1)
      mul >>= 1;
    else
      cnt >>= 1;
    long long sum = ((cnt % mod) * (mul % mod)) % mod;
    return make_pair(sum, v - u + 1);
  }
  long long oddcnt = (n + 1LL) >> 1;
  pair<long long, long long> osum, esum;
  long long sum = 0LL;
  if (oddcnt >= l) {
    osum = inrange_sum(l, min(r, oddcnt), ((u | 1LL) + 1LL) >> 1,
                       (v + 1LL) >> 1, oddcnt);
    sum = (osum.first << 1) - osum.second;
  }
  if (oddcnt < r) {
    esum = inrange_sum(max(1LL, l - oddcnt), r - oddcnt, (u + 1LL) >> 1, v >> 1,
                       n >> 1);
    sum += esum.first << 1;
  }
  sum %= mod;
  if (sum < 0) sum += mod;
  return make_pair(sum, osum.second + esum.second);
}
int main() {
  long long n;
  int m;
  scanf("%I64d%d%I64d", &n, &m, &mod);
  long long l, r, u, v;
  for (int i = 0; i < m; ++i) {
    scanf("%I64d%I64d%I64d%I64d", &l, &r, &u, &v);
    v = min(v, n);
    pair<long long, long long> sum = inrange_sum(l, r, u, v, n);
    printf("%I64d\n", sum.first);
  }
  return 0;
}
