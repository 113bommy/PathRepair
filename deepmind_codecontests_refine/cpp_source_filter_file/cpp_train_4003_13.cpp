#include <bits/stdc++.h>
using namespace std;
namespace prom {
int read() {
  int res = 0, f = 1;
  char a = getchar();
  while (a < '0' || a > '9') {
    if (a == '-') f = -1;
    a = getchar();
  }
  while (a >= '0' && a <= '9') res = res * 10 + a - '0', a = getchar();
  return res * f;
}
void writ(int x) {
  static int st[22];
  int t = 0;
  bool fl = 0;
  if (x < 0) fl = 1, x = -x;
  if (!x) st[++t] = 0;
  while (x) st[++t] = x % 10, x /= 10;
  if (fl) putchar('-');
  while (t) putchar(st[t--] + '0');
}
const int p = 998244353;
const int rev2 = 499122177;
long long pf(long long x, long long c) {
  long long res = 1, t = x;
  while (c) {
    if (c & 1) res = res * t % p;
    t = t * t % p;
    c >>= 1;
  }
  return res;
}
long long getrev(long long x) { return pf(x, p - 2); }
long long w[300005];
int rev[300005];
void Init(int n) {
  w[0] = w[n] = 1;
  w[1] = pf(3, (p - 1) / n);
  for (int i = 2; i < n; i++) w[i] = w[i - 1] * w[1] % p;
  rev[0] = 0;
  int len = 0;
  for (int i = 20; i >= 0; i--)
    if ((1 << i) & n) {
      len = i;
      break;
    }
  for (int i = 1; i < n; i++)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (len - 1));
}
void NTT(long long* g, int n, int s) {
  for (int i = 0; i < n; i++)
    if (rev[i] > i) swap(g[i], g[rev[i]]);
  long long t1, t2;
  for (int i = 1, L = n / 2 * s; i < n; i <<= 1, L /= 2)
    for (int j = 0; j < n; j += i << 1)
      for (int k = 0, l0 = s > 0 ? 0 : n; k < i; k++, l0 += L) {
        t1 = g[j + k];
        t2 = g[i + j + k] * w[l0] % p;
        g[j + k] = (t1 + t2) % p;
        g[i + j + k] = (t1 - t2 + p) % p;
      }
  t1 = getrev(n);
  if (s == -1)
    for (int i = 0; i < n; i++) g[i] = g[i] * t1 % p;
}
void polrev(long long* a, long long* b, int n) {
  if (n == 1)
    b[0] = getrev(a[0]);
  else {
    polrev(a, b, n >> 1);
    static long long a0[300005];
    for (int i = 0; i < n; i++) a0[i] = a[i], a0[i + n] = 0, b[i + n] = 0;
    n <<= 1;
    Init(n);
    NTT(a0, n, 1);
    NTT(b, n, 1);
    for (int i = 0; i < n; i++) b[i] = (2 - a0[i] * b[i] % p + p) * b[i] % p;
    NTT(b, n, -1);
    for (int i = n >> 1; i < n; i++) b[i] = 0;
  }
}
void polsq(long long* a, long long* b, int n) {
  if (n == 1)
    b[0] = 1;
  else {
    polsq(a, b, n >> 1);
    static long long a0[300005], invb[300005];
    polrev(b, invb, n);
    for (int i = 0; i < n; i++) a0[i] = a[i], a0[i + n] = 0;
    n <<= 1;
    Init(n);
    NTT(a0, n, 1);
    NTT(b, n, 1);
    NTT(invb, n, 1);
    for (int i = 0; i < n; i++) b[i] = rev2 * (b[i] + a0[i] * invb[i] % p) % p;
    NTT(b, n, -1);
    for (int i = n >> 1; i < n; i++) b[i] = 0;
  }
}
long long C[300005], rootc[300005];
int main() {
  int K = read(), n = read();
  int maxc = 0;
  for (int x, i = 1; i <= K; i++) C[x = read()]++, maxc = max(maxc, x);
  for (int i = 0; i <= maxc; i++) C[i] = (p - C[i] * 4 % p) % p;
  C[0]++;
  int m = 1;
  while (m < n) m <<= 1;
  polsq(C, rootc, m);
  rootc[0]++;
  polrev(rootc, C, m);
  for (int i = 0; i < m; i++) C[i] = C[i] * 2 % p;
  for (int i = 1; i <= n; i++) writ(C[i]), putchar('\n');
  return 0;
}
}  // namespace prom
int main() { return prom::main(); }
