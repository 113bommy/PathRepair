#include <bits/stdc++.h>
using namespace std;
long long n;
long long a, b;
long long fac[1000010];
long long fast_exp(long long a, long long m) {
  if (!m) return 1;
  long long k = fast_exp(a, m / 2);
  if (m & 1) return (((k * k) % 1000000007) * a) % 1000000007;
  return (k * k) % 1000000007;
}
long long bol(long long a, long long b) {
  return (a * fast_exp(b, 1000000007 - 2)) % 1000000007;
}
long long comb(long long t) { return (t * (t - 1) / 2) % 1000000007; }
long long birler() {
  long long p, r;
  long long res = 1;
  long long carp = 1;
  for (long long x = 1; x <= a / 2; x++) {
    p = comb(a + 2 - x * 2);
    carp *= p;
    carp %= 1000000007;
    res += bol(carp, fac[x]);
    res %= 1000000007;
  }
  return res;
}
long long ikiler() {
  long long res = fac[b];
  long long carp = 1;
  for (long long c = 1; c <= b; c++) {
    carp *= a + c - 1;
    carp %= 1000000007;
    res += (carp * bol(fac[b], fac[c])) % 1000000007;
    res %= 1000000007;
  }
  return res;
}
int main() {
  fac[0] = 1;
  for (long long i = 1; i <= 1000000; i++) fac[i] = fac[i - 1] * i;
  scanf(" %I64d", &n);
  for (long long i = 1; i <= n; i++) {
    long long x;
    scanf(" %I64d", &x);
    if (x == 1) a++;
    if (x == 2) b++;
  }
  printf("%I64d\n", (birler() * ikiler()) % 1000000007);
  return 0;
}
