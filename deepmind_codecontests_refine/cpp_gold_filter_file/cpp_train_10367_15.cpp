#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
const int MOD = 1000000007;
int fac[maxn], rev[maxn], f, w, h, p, q, now;
inline int power(int x, int p) {
  int res = 1;
  while (p) {
    if (p & 1) res = 1LL * res * x % MOD;
    x = 1LL * x * x % MOD;
    p >>= 1;
  }
  return res;
}
inline int C(int n, int m) {
  if (m < 0 || m > n) return 0;
  return 1LL * fac[n] * rev[m] % MOD * rev[n - m] % MOD;
}
inline int S(int n, int m) {
  if (n == 0 && m == 0) return 1;
  if (n < 0 || m <= 0 || m > n) return 0;
  return C(n - 1, m - 1);
}
int main() {
  scanf("%d%d%d", &f, &w, &h);
  fac[0] = rev[0] = 1;
  for (int i = (1); i <= (100000); i++) {
    fac[i] = 1LL * fac[i - 1] * i % MOD;
    rev[i] = power(fac[i], MOD - 2);
  }
  for (int i = (0); i <= (min(f + 1, w)); i++) {
    now = (1LL * S(f, i - 1) + 2LL * S(f, i) + 1LL * S(f, i + 1)) % MOD;
    if (w >= 1LL * h * i) p = (p + 1LL * now * S(w - h * i, i)) % MOD;
    q = (q + 1LL * now * S(w, i)) % MOD;
  }
  printf("%d\n", 1LL * p * power(q, MOD - 2) % MOD);
  return 0;
}
