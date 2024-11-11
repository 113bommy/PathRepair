#include <bits/stdc++.h>
using namespace std;
const int maxn = 2.5e6 + 100;
const int inf = 0x3f3f3f3f;
const int iinf = 1 << 30;
const long long linf = 2e18;
const long long mod = 998244353;
const double eps = 1e-7;
template <class T>
void read(T &a) {
  int f = 1;
  a = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    a = (a << 3) + (a << 1) + ch - '0';
    ch = getchar();
  }
  a *= f;
}
long long n, lim;
long long a[maxn], b[maxn];
char s[maxn], t[maxn];
long long count(long long a) { return __builtin_popcount(a); }
long long power(long long a, long long b) {
  long long ret = 1;
  for (; b; b >>= 1, a *= a)
    if (b & 1) ret *= a;
  return ret;
}
void fwt_or(long long *a, long long opt) {
  for (long long i = 1; i <= lim; i <<= 1)
    for (long long j = 0; j <= lim; j += i << 1)
      for (register long long k = (0); k <= (i - 1); ++k)
        a[i + j + k] += a[j + k] * opt;
}
signed main() {
  scanf("%lld", &n);
  scanf("%s", s);
  scanf("%s", t);
  lim = (1ll << n) - 1;
  for (register long long i = (0); i <= (lim); ++i)
    a[i] = (s[i] - '0') * power(4, count(i));
  for (register long long i = (0); i <= (lim); ++i)
    b[i] = (t[i] - '0') * power(4, count(i));
  fwt_or(a, 1), fwt_or(b, 1);
  for (register long long i = (0); i <= (lim); ++i) a[i] *= b[i];
  fwt_or(a, -1);
  for (register long long i = (0); i <= (lim); ++i)
    putchar('0' + ((a[i] / power(4, count(i))) & 3));
  return 0;
}
