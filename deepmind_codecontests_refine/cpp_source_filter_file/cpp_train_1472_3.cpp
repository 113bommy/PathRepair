#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
inline int read() {
  int w = 1, s = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    s = s * 10 + ch - '0';
    ch = getchar();
  }
  return w * s;
}
int n, p[1000010], fac[1000010], Sum[1000010];
inline long long ksm(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = res * x % mod;
    y >>= 1;
    x = x * x % mod;
  }
  return res;
}
inline int lowbit(int x) { return x & (-x); }
inline void add(int pos, int d) {
  while (pos <= n) Sum[pos] += d, pos += lowbit(pos);
}
inline int Qry(int pos) {
  int res = 0;
  while (pos) res += Sum[pos], pos -= lowbit(pos);
  return res;
}
set<int> st;
inline void Init() {
  fac[0] = 1;
  for (register int i = 1; i <= n; ++i) fac[i] = 1ll * fac[i - 1] * i % mod;
}
int main() {
  n = read();
  int tot = 0;
  for (register int i = 1; i <= n; ++i) p[i] = read(), tot += (p[i] == (-1));
  Init();
  long long ans = 0;
  for (register int i = n; i; --i) {
    if (p[i] != -1) {
      add(p[i], 1);
      ans += 1ll * fac[tot] * Qry(p[i] - 1) % mod;
      ans %= mod;
    }
  }
  ans += 1ll * tot * (tot - 1) % mod * ksm(2, mod - 2) % mod * ksm(2, mod - 2) %
         mod * fac[tot] % mod;
  ans %= mod;
  memset(Sum, 0, sizeof(Sum));
  for (register int i = 1; i <= n; ++i) add(i, 1);
  for (register int i = 1; i <= n; ++i)
    if (p[i] != -1) add(p[i], -1);
  if (tot) {
    int sum = 0;
    for (register int i = 1; i <= n; ++i) {
      if (p[i] == -1) {
        ans += 1ll * sum * fac[tot - 1] % mod;
        ans %= mod;
      } else {
        int tmp = Qry(p[i]);
        sum += tmp;
        sum %= mod;
      }
    }
    sum = 0;
    for (register int i = n; i; --i) {
      if (p[i] == -1) {
        ans += 1ll * sum * fac[tot - 1] % mod;
        ans %= mod;
      } else {
        int tmp = tmp - Qry(p[i]);
        sum += tmp;
        sum %= mod;
      }
    }
  }
  cout << 1ll * ans * ksm(fac[tot], mod - 2) % mod << "\n";
  return 0;
}
