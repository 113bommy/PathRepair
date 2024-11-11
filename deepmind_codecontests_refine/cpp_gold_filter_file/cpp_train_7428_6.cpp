#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const int N = 2111;
long long a[N];
long long f[N];
long long cal(long long a, long long b, long long mod) {
  long long res = 1, t = a;
  while (b) {
    if (b & 1) res = res * t % mod;
    t = t * t % mod;
    b >>= 1;
  }
  return res;
}
int main() {
  int n, i, j, m;
  f[0] = 1;
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++) scanf("%I64d", a + i);
  for (i = 1; i < n; i++) {
    f[i] = (f[i - 1] * (i + m - 1) % mod) * (cal(i * 1ll, mod - 2, mod)) % mod;
  }
  long long t;
  for (i = 0; i < n; i++) {
    t = 0;
    for (j = 0; j <= i; j++) {
      t += a[j] * f[i - j];
      if (t >= mod) t %= mod;
    }
    if (i) putchar(' ');
    printf("%I64d", t);
  }
  puts("");
  return 0;
}
