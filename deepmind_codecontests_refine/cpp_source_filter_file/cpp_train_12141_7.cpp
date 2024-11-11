#include <bits/stdc++.h>
using namespace std;
int ti = 10, n, m, mod, a[100012], b[100012];
char sc[100012];
inline int Ra() { return 1ll * rand() * rand() % (mod - 1); }
inline int gcd(int x, int y) { return (y == 0) ? x : gcd(y, x % y); }
inline int ksm(int p, int k) {
  int res = 1;
  while (k) {
    if (k & 1) res = 1ll * res * p % mod;
    k >>= 1;
    p = 1ll * p * p % mod;
  }
  return res;
}
inline bool che(int x) {
  int i;
  for (i = 2; 1ll * i * i <= x; i++)
    if (x % i == 0) return false;
  return true;
}
inline bool can(int x) {
  int res = 0;
  for (int i = n - 1; i >= 0; i--) res = (1ll * res * x + a[i]) % mod;
  return (res == 0);
}
int P[100012], cn = 0;
inline int G() {
  int i, j, p = mod - 1, fl;
  cn = 0;
  for (i = 2; 1ll * i * i <= p; i++)
    if (p % i == 0) {
      P[++cn] = i;
      while (p % i == 0) p /= i;
    }
  if (p > 1) P[++cn] = p;
  for (i = 2; i < p; i++) {
    fl = true;
    for (j = 1; j <= cn; j++)
      if (ksm(i, (mod - 1) / P[j]) == 1) {
        fl = false;
        break;
      }
    if (fl) return i;
  }
  return 0;
}
int main() {
  srand(19260817);
  scanf("%d", &n);
  int i;
  bool fl = true;
  scanf("%s", sc);
  for (i = 0; i < n; i++) a[i] = sc[i] ^ 48;
  for (mod = n + 1; ti && fl; mod += n)
    if (che(mod)) --ti, fl &= can(ksm(G(), (mod - 1) / n));
  printf("%s", fl ? "YES" : "NO");
  return 0;
}
