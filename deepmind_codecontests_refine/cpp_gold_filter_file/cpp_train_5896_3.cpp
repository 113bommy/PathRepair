#include <bits/stdc++.h>
const int maxn = 2e5 + 10;
const int N = 4e5 + 10;
using namespace std;
long long gcd(long long p, long long q) { return q == 0 ? p : gcd(q, p % q); }
long long qmul(long long p, long long q, long long mo) {
  long long f = 0;
  while (q) {
    if (q & 1) f = (f + p) % mo;
    p = (p + p) % mo;
    q >>= 1;
  }
  return f;
}
long long qpow(long long p, long long q) {
  long long f = 1;
  while (q) {
    if (q & 1) f = f * p % 998244353;
    p = p * p % 998244353;
    q >>= 1;
  }
  return f;
}
int n, m, k, t, a[maxn], lst[maxn];
int main() {
  int i, j;
  scanf("%d", &n);
  for (i = 1; i <= (int)n; i++) scanf("%d", &a[i]);
  int ret = 0;
  for (i = 1; i <= (int)n; i++) {
    if (lst[a[i]])
      lst[a[i]] = 0, lst[i] = 1;
    else
      ret++, lst[i] = 1;
  }
  printf("%d\n", ret);
  return 0;
}
