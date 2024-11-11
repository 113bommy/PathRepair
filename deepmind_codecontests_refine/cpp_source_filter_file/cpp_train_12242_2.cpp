#include <bits/stdc++.h>
using namespace std;
const int maxn = 300005;
const int mod = 1000000007;
int fac[maxn << 1], rev[maxn << 1], bin[maxn], f[maxn];
int lena, lenb, n, equ, p, q, da, db, Da, Db, k, tmp, ans;
char a[maxn], b[maxn];
inline int power(int x, int p) {
  int res = 1;
  while (p) {
    if (p & 1) res = 1ll * res * x % mod;
    x = 1ll * x * x % mod;
    p >>= 1;
  }
  return res;
}
inline int C(int n, int m) {
  if (m < 0 || m > n) return 0;
  return 1ll * fac[n] * rev[n - m] % mod * rev[m] % mod;
}
inline int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }
void init() {
  scanf("%s%s%d", a + 1, b + 1, &n);
  lena = strlen(a + 1);
  lenb = strlen(b + 1);
  bin[0] = 1;
  for (int i = (1); i <= (300000); i++) {
    bin[i] = bin[i - 1] + bin[i - 1];
    if (bin[i] >= mod) bin[i] -= mod;
  }
  fac[0] = 1;
  for (int i = (1); i <= (600000); i++) fac[i] = 1ll * i * fac[i - 1] % mod;
  rev[600000] = power(fac[600000], mod - 2);
  for (int i = (600000); i >= (1); i--) rev[i - 1] = 1ll * i * rev[i] % mod;
  for (int i = (n); i >= (1); i--) {
    f[i] = 1ll * (n / i) * (n / i) % mod;
    for (int j = 2 * i; j <= n; j += i) f[i] = (f[i] + mod - f[j]) % mod;
    equ = (equ + 1ll * bin[i] * f[i]) % mod;
  }
}
int same() {
  if (lena != lenb) return 0;
  int cnt = 1;
  for (int i = (1); i <= (lena); i++)
    if (a[i] != '?' && b[i] != '?' && a[i] != b[i])
      return 0;
    else if (a[i] == '?' && b[i] == '?')
      cnt = 2 * cnt % mod;
  return cnt;
}
int main() {
  init();
  for (int i = (1); i <= (lena); i++)
    if (a[i] == '?')
      p++;
    else if (a[i] == 'A')
      Da++;
    else if (a[i] == 'B')
      Db++;
  for (int i = (1); i <= (lenb); i++)
    if (b[i] == '?')
      q++;
    else if (b[i] == 'A')
      Da--;
    else if (b[i] == 'B')
      Db--;
  for (int d = (-q); d <= (p); d++) {
    da = abs(Da + d);
    db = abs(Db + p - q - d);
    if (da == 0 && db == 0) {
      k = C(p + q, q + d);
      ans = (ans + 1ll * k * equ) % mod;
    } else if (1ll * (Da + d) * (Db + p - q - d) < 0) {
      k = C(p + q, q + d);
      tmp = max(da, db) / gcd(da, db);
      ans = (ans + 1ll * k * (bin[n / tmp + 1] - 2)) % mod;
    }
  }
  if (k = same()) {
    ans = (ans + mod - 1ll * k * equ % mod) % mod;
    ans = (ans + 1ll * k * (bin[n + 1] - 2) % mod * (bin[n + 1] - 2)) % mod;
  }
  printf("%d\n", (ans + mod) % mod);
  return 0;
}
