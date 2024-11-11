#include <bits/stdc++.h>
using namespace std;
char getc() {
  char c = getchar();
  while ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z') && (c < '0' || c > '9'))
    c = getchar();
  return c;
}
int gcd(int n, int m) { return m == 0 ? n : gcd(m, n % m); }
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9')
    x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  return x * f;
}
int n, m, p[70], a[100010], pre[100010], pos[100010], cnt, q;
int ksm(int a, int k, int P) {
  int s = 1;
  for (; k; k >>= 1, a = 1ll * a * a % P)
    if (k & 1) s = 1ll * s * a % P;
  return s;
}
long long KSM(int a, long long k) {
  long long s = 1;
  if (k > 32) return 2000000000;
  for (int i = 1; i <= k; i++) {
    s *= a;
    if (s >= 2000000000) break;
  }
  return s;
}
long long get(int l, int r) {
  long long s = 1;
  for (int i = pre[r]; i >= l; i = pre[i - 1]) {
    s = KSM(a[i], s);
    if (s >= 2000000000) break;
  }
  return s;
}
signed main() {
  n = read(), p[0] = read();
  m = 0;
  while (p[m] > 1) {
    m++;
    int x = p[m] = p[m - 1];
    for (int i = 2; i * i <= x; i++)
      if (x % i == 0) {
        p[m] /= i;
        p[m] *= i - 1;
        while (x % i == 0) x /= i;
      }
    if (x > 1) p[m] /= x, p[m] *= x - 1;
  }
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= n; i++)
    if (a[i] == 1)
      pos[++cnt] = i, pre[i] = pre[i - 1];
    else
      pre[i] = i;
  pos[++cnt] = n + 1;
  q = read();
  while (q--) {
    int l = read(), r = read(), ans = 1;
    int u = *lower_bound(pos + 1, pos + cnt + 1, l);
    long long t = get(min(min(r, l + m), u - 1) + 1, r);
    if (u <= min(r, l + m)) t = 1;
    for (int i = min(min(r, l + m), u - 1); i >= l; i--) {
      ans = ksm(a[i], ans, p[i - l]);
      t = KSM(a[i], t);
      if (i > l && t >= p[i - l]) ans += p[i - l];
    }
    printf("%d\n", ans % p[0]);
  }
  return 0;
}
