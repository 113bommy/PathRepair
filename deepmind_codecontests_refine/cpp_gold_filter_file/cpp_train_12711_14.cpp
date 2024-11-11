#include <bits/stdc++.h>
using namespace std;
void read(long long &x) {
  x = 0;
  long long f = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -f;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  x *= f;
}
void print(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (!x) return;
  print(x / 10), putchar(x % 10 + 48);
}
void write(long long x) {
  if (!x)
    putchar('0');
  else
    print(x);
  putchar('\n');
}
const long long maxn = 2.1e6 + 10;
const long long inf = 1e9;
const double eps = 1e-8;
const long long mod = 1e9 + 7;
char s[maxn], t[maxn];
long long n, a[maxn], b[maxn];
void fwt(long long *r, long long op) {
  for (long long i = 1; i < 1 << n; i <<= 1)
    for (long long j = 0; j < 1 << n; j += i << 1)
      for (long long k = 0; k < i; k++) r[i + j + k] += r[j + k] * op;
}
signed main() {
  read(n);
  scanf("%s%s", s, t);
  for (long long i = 0; i < 1 << n; i++) {
    a[i] = (1ll << (__builtin_popcount(i) << 1)) * (s[i] - '0');
    b[i] = (1ll << (__builtin_popcount(i) << 1)) * (t[i] - '0');
  }
  fwt(a, 1), fwt(b, 1);
  for (long long i = 0; i < 1 << n; i++) a[i] = a[i] * b[i];
  fwt(a, -1);
  for (long long i = 0; i < 1 << n; i++)
    putchar(((a[i] >> (__builtin_popcount(i) << 1)) & 3) + '0');
  puts("");
  return 0;
}
