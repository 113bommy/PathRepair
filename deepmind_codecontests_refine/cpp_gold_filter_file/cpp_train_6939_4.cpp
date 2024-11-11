#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
template <typename T>
void read(T &x) {
  bool neg = false;
  unsigned char c = getchar();
  for (; (c ^ 48) > 9; c = getchar())
    if (c == '-') neg = true;
  for (x = 0; (c ^ 48) < 10; c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
  if (neg) x = -x;
}
int n, aa[N], bb[N], carda, cardb;
long long a[N], b[N], c[N], cnta[N], cntb[N], a1[N], b1[N], ans = 1;
int disc(long long x, long long *a) {
  int l = 0, r = n, mid;
  while (r - l > 1) {
    mid = (l + r) >> 1;
    if (x < a[mid])
      r = mid;
    else
      l = mid;
  }
  return l;
}
long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }
int main() {
  long long g = 0;
  read(n);
  for (int i = 0, i_end = n; i < i_end; ++i) read(a[i]), read(b[i]), read(c[i]);
  for (int i = 0, i_end = n; i < i_end; ++i) a1[i] = a[i], b1[i] = b[i];
  sort(a1, a1 + n);
  sort(b1, b1 + n);
  for (int i = 0, i_end = n; i < i_end; ++i)
    if (i == 0 || a1[i] != a1[i - 1]) ++carda;
  for (int i = 0, i_end = n; i < i_end; ++i)
    if (i == 0 || b1[i] != b1[i - 1]) ++cardb;
  if (carda * cardb != n) return puts("0"), 0;
  for (int i = 0, i_end = n; i < i_end; ++i) aa[i] = disc(a[i], a1);
  for (int i = 0, i_end = n; i < i_end; ++i) bb[i] = disc(b[i], b1);
  for (int i = 0, i_end = n; i < i_end; ++i)
    cnta[aa[i]] += c[i], cntb[bb[i]] += c[i];
  for (int i = 0, i_end = n; i < i_end; ++i) g = gcd(cnta[i], g);
  for (int i = 0, i_end = n; i < i_end; ++i) cnta[i] /= g;
  g = 0;
  for (int i = 0, i_end = n; i < i_end; ++i) g = gcd(cntb[i], g);
  for (int i = 0, i_end = n; i < i_end; ++i) cntb[i] /= g;
  g = 0;
  for (int i = 0, i_end = n; i < i_end; ++i) {
    long long t = cnta[aa[i]] * cntb[bb[i]];
    if (c[i] % t) return puts("0"), 0;
    if (i == 0)
      g = c[i] / t;
    else if (c[i] / t != g)
      return puts("0"), 0;
  }
  for (long long i = 2; g != 1 && i * i <= g; ++i) {
    int t = 0;
    for (; g % i == 0; ++t) g /= i;
    ans *= (t + 1);
  }
  if (g != 1) ans *= 2;
  printf("%lld\n", ans);
  return 0;
}
