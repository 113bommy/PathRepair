#include <bits/stdc++.h>
using namespace std;
const long double pi = acos(-1);
const int oo = 1 << 30;
const long long OO = 1e18;
const int N = 1e6 + 100;
const int mod = 1e9 + 7;
int gi() {
  int w = 0;
  bool q = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') q = 0, c = getchar();
  while (c >= '0' && c <= '9') w = w * 10 + c - '0', c = getchar();
  return q ? w : -w;
}
char c[N], d[N];
inline int same(char *a, char *b) {
  int n = strlen(a + 1), i, s = 0;
  if (n != strlen(b + 1)) return -1;
  for (i = 1; i <= n; i++)
    if (a[i] == '?' && b[i] == '?')
      s++;
    else if (a[i] != '?' && b[i] != '?' && a[i] != b[i])
      return -1;
  return s;
}
inline int qpow(int x, long long y) {
  int ans = 1;
  while (y) {
    if (y & 1) ans = 1LL * ans * x % mod;
    x = 1LL * x * x % mod;
    y >>= 1;
  }
  return ans;
}
int fac[N], inv[N];
const int lim = 1e7;
int pri[lim], phi[lim], Phi[int(1e10 / lim)];
long long n;
inline int C(int n, int m) {
  if (m < 0 || n < m) return 0;
  return 1LL * fac[n] * inv[m] % mod * inv[n - m] % mod;
}
inline int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
inline void init() {
  int i, j, len = 0, t;
  for (i = 2, phi[1] = 1; i < lim; i++) {
    if (!pri[i]) pri[++len] = i, phi[i] = i - 1;
    for (j = 1; j <= len && (t = i * pri[j]) < lim; j++) {
      pri[t] = 1;
      if (i % pri[j])
        phi[t] = phi[i] * (pri[j] - 1);
      else {
        phi[t] = phi[i] * pri[j];
        break;
      }
    }
    (phi[i] += phi[i - 1]) %= mod;
  }
}
inline int F(long long m) {
  if (m < lim) return phi[m];
  int &ans = Phi[n / m];
  if (ans) return ans;
  ans = (m % mod) * ((m + 1) % mod) % mod * ((mod + 1) / 2) % mod;
  for (long long l = 1, r; l <= m; l = r + 1) {
    r = n / (n / l);
    ans = (ans - 1LL * (r - l + 1) * F(n / l)) % mod;
  }
  return ans;
}
int main() {
  scanf("%s", c + 1);
  scanf("%s", d + 1);
  init();
  cin >> n;
  int i, s, a = 0, b = 0, A = 0, B = 0, u, v, ans = 0, D, w, x, y, S = 0;
  long long l, r;
  u = strlen(c + 1), v = strlen(d + 1);
  for (i = fac[0] = 1; i <= u + v; i++) fac[i] = 1LL * fac[i - 1] * i % mod;
  for (i = 2, inv[0] = inv[1] = 1; i <= u + v; i++)
    inv[i] = -1LL * (mod / i) * inv[mod % i] % mod;
  for (i = 3; i <= u + v; i++) inv[i] = 1LL * inv[i] * inv[i - 1] % mod;
  for (i = 1; i <= u; i++) c[i] == '?' ? A++ : (c[i] == 'A' ? a++ : b++);
  for (i = 1; i <= v; i++) d[i] == '?' ? B++ : (d[i] == 'A' ? a-- : b--);
  for (l = 1; l <= n; l = r + 1) {
    r = n / (n / l);
    S = (S + (2 * F(n / l) - 1) % mod * (qpow(2, r + 1) - qpow(2, l))) % mod;
  }
  for (D = -B; D <= A; D++) {
    w = C(A + B, B + D);
    x = a + D, y = b + A - B - D;
    if (!x && !y)
      ans = (ans + 1LL * S * w) % mod;
    else if (1LL * x * y < 0) {
      x = abs(x), y = abs(y);
      ans = (ans + 1LL * w * (qpow(2, n / (max(x, y) / gcd(x, y)) + 1) - 2)) %
            mod;
    }
  }
  if (~(s = same(c, d))) {
    ans = (ans - 1LL * qpow(2, s) * S) % mod;
    ans = (ans + 1LL * qpow(2, s) * (qpow(2, n + 1) - 2) % mod *
                     (qpow(2, n + 1) - 2)) %
          mod;
  }
  printf("%d\n", (ans + mod) % mod);
  return 0;
}
