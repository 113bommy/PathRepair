#include <bits/stdc++.h>
using namespace std;
template <typename tp>
inline void read(tp &x) {
  x = 0;
  register int f = 1;
  register char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  x *= f;
}
template <typename tp>
inline void print(tp x) {
  if (x < 0) x = -x, putchar('-');
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
}
const long long N = 1e6 + 10;
long long n, mod, k;
long long a[N];
map<long long, long long> buc;
long long ans = 0;
signed main() {
  read(n), read(mod), read(k);
  for (register long long i = 1; i <= n; ++i) read(a[i]);
  for (register long long i = 1; i <= n; ++i) {
    long long res = a[i] * a[i] % mod;
    res = res * a[i] % mod;
    res = res * a[i] % mod;
    res = ((res - k) % mod + mod) % mod;
    if (buc.count(res)) ans += buc[res];
    buc[res]++;
  }
  print(ans);
  return 0;
}
