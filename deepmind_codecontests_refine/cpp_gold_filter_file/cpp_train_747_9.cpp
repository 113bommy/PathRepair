#include <bits/stdc++.h>
using namespace std;
const int _ = 1e2;
const int maxn = 2e6 + _;
const int mod = 998244353;
inline int ad(int x, int y) { return x >= mod - y ? x - mod + y : x + y; }
inline int re(int x, int y) { return x < y ? x - y + mod : x - y; }
inline int mu(int x, int y) { return (long long)x * y % mod; }
inline int qp(int x, long long y) {
  int r = 1;
  while (y) {
    if (y & 1) r = mu(r, x);
    x = mu(x, x);
    y >>= 1;
  }
  return r;
}
inline int iv(int x) { return qp(x, mod - 2); }
inline int dv(int x, int y) { return mu(x, qp(y, mod - 2)); }
inline int gcd(int x, int y) { return x ? gcd(y % x, x) : y; }
inline int read() {
  int x = 0;
  char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x;
}
inline void write(int d) {
  if (d >= 10) write(d / 10);
  putchar(d % 10 + '0');
}
int fac[maxn], fac_inv[maxn];
int C(int n, int m) {
  if (n < m) return 0;
  return mu(fac[n], mu(fac_inv[m], fac_inv[n - m]));
}
void yu(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = mu(fac[i - 1], i);
  fac_inv[n] = iv(fac[n]);
  for (int i = n - 1; i >= 0; i--) fac_inv[i] = mu(fac_inv[i + 1], i + 1);
}
int n, q[maxn], L[maxn], R[maxn];
char ss[maxn];
int main() {
  int n;
  scanf("%s", ss + 1);
  n = strlen(ss + 1);
  yu(2 * n);
  for (int i = 1; i <= n; i++) {
    q[i] = q[i - 1], L[i] = L[i - 1], R[i] = R[i - 1];
    if (ss[i] == '?')
      q[i]++;
    else if (ss[i] == '(')
      L[i]++;
    else if (ss[i] == ')')
      R[i]++;
  }
  int ans = 0;
  for (int i = 1; i < n; i++) {
    int ll = L[i], rr = R[n] - R[i];
    int lq = q[i], rq = q[n] - q[i];
    ans = ad(ans, mu(ll + lq, C(lq + rq, lq + ll - rr)));
    ans = re(ans, mu(lq, C(lq + rq - 1, lq + ll - rr - 1)));
  }
  printf("%d\n", ans);
  return 0;
}
