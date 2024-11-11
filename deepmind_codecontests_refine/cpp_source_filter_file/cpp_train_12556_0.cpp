#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 20, MOD = 1e9 + 7, INV2 = MOD + 1 >> 1;
inline int add(int a, const int &b) { return (a += b) >= MOD ? a - MOD : a; }
inline int sub(int a, const int &b) { return (a -= b) < 0 ? a + MOD : a; }
inline int mul(const int &a, const int &b) { return 1ll * a * b % MOD; }
inline int &inc(int &a, const int &b) { return a = add(a, b); }
inline int &dec(int &a, const int &b) { return a = sub(a, b); }
inline int &pro(int &a, const int &b) { return a = mul(a, b); }
inline int qpow(int a, int b) {
  int c = 1;
  for (; b; b >>= 1, pro(a, a))
    if (b & 1) pro(c, a);
  return c;
}
int a[N];
int n;
inline void fwt(int *f, int l, int opt) {
  for (int i = 1; i < l; i <<= 1)
    for (int j = 0; j < l; j += i << 1)
      for (int k = 0; k < i; k++) {
        int x = f[j + k], y = f[i + j + k];
        f[j + k] = add(x, y);
        f[i + j + k] = sub(x, y);
        if (opt) pro(f[j + k], INV2), pro(f[i + j + k], INV2);
      }
}
char s[N];
int main() {
  scanf("%d%s", &n, s);
  for (int i = 0; i < 1 << n; i++) a[i] = s[i] - '0';
  fwt(a, 1 << n, 0);
  for (int i = 0; i < 1 << n; i++) pro(a[i], a[i]);
  fwt(a, 1 << n, 1);
  int ans = 0;
  for (int i = 0; i < 1 << n; i++)
    inc(ans, mul(a[i], qpow(2, n - __builtin_popcount(i))));
  printf("%d\n", mul(ans, 3));
  return 0;
}
